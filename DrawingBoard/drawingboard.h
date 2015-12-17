#ifndef DRAWINGBOARD_H
#define DRAWINGBOARD_H

#include <QtWidgets/QMainWindow>
#include "ui_drawingboard.h"

class DrawingBoard : public QMainWindow
{
	Q_OBJECT

public:
	DrawingBoard(QWidget *parent = 0);
	~DrawingBoard();

private:
	Ui::DrawingBoardClass ui;
};

#endif // DRAWINGBOARD_H
