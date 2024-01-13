#include "ScribbleArea.h"

ScribbleArea::ScribbleArea(QWidget *parent)
	: QMainWindow(parent)
{
	image = QImage(640, 720, QImage::Format_RGB32);
	image.fill(Qt::white);
	modified = false;
	scribbling = false;
	myPenWidth = 1;
	myPenColor = Qt::black;
}

ScribbleArea::~ScribbleArea()
{}

void ScribbleArea::SetPenColor(const QColor& newColor)
{
	myPenColor = newColor;
}

void ScribbleArea::SetPenWidth(int newWidth)
{
	myPenWidth = newWidth;
}

void ScribbleArea::ClearImage()
{
	image.fill(qRgb(255, 255, 255));
	modified = true;
	update();
}

void ScribbleArea::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		lastPoint = event->pos();
		scribbling = true;
	}
}

void ScribbleArea::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton) && scribbling)
		drawLineTo(event->pos());
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && scribbling) 
	{
		drawLineTo(event->pos());
		scribbling = false;
	}
}

void ScribbleArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void ScribbleArea::drawLineTo(const QPoint& endPoint)
{
	QPainter painter(&image);
	painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
	painter.drawLine(lastPoint, endPoint);
	modified = true;
	int rad = (myPenWidth / 2) + 2;
	update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	lastPoint = endPoint;
}








