#pragma once

#include <QMainWindow>
#include "ui_ScribbleArea.h"

#include<QColor>
#include<QImage>
#include<QPoint>
#include<QWidget>
#include<QMouseEvent>
#include<QPainter>

class ScribbleArea : public QMainWindow
{
	Q_OBJECT

public:
	ScribbleArea(QWidget *parent = nullptr);
	~ScribbleArea();

	void SetPenColor(const QColor& newColor);
	void SetPenWidth(int newWidth);

	bool isModified() const { return modified; }
	QColor PenColor() const { return myPenColor; }
	int PenWidth() const { return myPenWidth; }

public slots:
	void ClearImage();

private:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
	void drawLineTo(const QPoint& endPoint);

	bool modified;
	bool scribbling;

	QColor myPenColor;
	int myPenWidth;
	QImage image;
	QPoint lastPoint;
};
