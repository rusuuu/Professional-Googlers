#include "ScribbleWindow.h"

int ScribbleWindow::WindowIndex = 5;

ScribbleWindow::ScribbleWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scribbleArea = new ScribbleArea;
	setCentralWidget(scribbleArea);
	CreateActions();
	CreateMenus();
}

ScribbleWindow::~ScribbleWindow()
{}

void ScribbleWindow::ClearImage()
{

}

void ScribbleWindow::PenColor()
{
	QColor newColor = QColorDialog::getColor(scribbleArea->PenColor());

	if (newColor.isValid())
		scribbleArea->SetPenColor(newColor);
}

void ScribbleWindow::PenWidth()
{
	bool ok;

	int newWidth = QInputDialog::getInt(this, tr("Scribble"),
		tr("Select pen width:"),
		scribbleArea->PenWidth(),
		1, 50, 1, &ok);

	if (ok)
		scribbleArea->SetPenWidth(newWidth);
}

void ScribbleWindow::CreateActions()
{
	penColorAct = new QAction(tr("&Pen Color..."), this);
	connect(penColorAct, SIGNAL(triggered()), this, SLOT(PenColor()));

	penWidthAct = new QAction(tr("&Pen Width..."), this);
	connect(penWidthAct, SIGNAL(triggered()), this, SLOT(PenWidth()));

	clearScreenAct = new QAction(tr("&Clear Screen..."), this);
	connect(clearScreenAct, SIGNAL(triggered()), scribbleArea, SLOT(ClearImage()));
}

void ScribbleWindow::CreateMenus()
{
	optionMenu = new QMenu(tr("&Options"), this);
	optionMenu->addAction(penColorAct);
	optionMenu->addAction(penWidthAct);
	optionMenu->addAction(clearScreenAct);

	menuBar()->addMenu(optionMenu);
}
