#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QCloseEvent>
#include "paintwidget.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT;

public:
	MainWindow(QWidget* parent);
	~MainWindow();
	int changed;
	//work space
	PaintWidget* m_paintWidget;

signals:
	void setshape(shapetype);								// 改变绘制图形的信号
	void paintEvent(QPaintEvent *);							// 绘制函数
	void SetPenWidth(Penwidth);								// 改变画笔宽度的信号
	void SetPenColor(Pencolor);								// 改变画笔颜色的信号

protected slots:
	void DrawLineActionClicked();							
	void DrawRectActionClicked();
	void DrawCircleActionClicked();
	void DrawCurveActionClicked();
	void SetPenWidth1Clicked();
	void SetPenWidth2Clicked();
	void SetPenWidth3Clicked();
	void SetPenWidth4Clicked();
	void SetPenColorBlackClicked();				
	void SetPenColorBlueClicked();
	void SetPenColorRedClicked();
	void SetPenColorGreenClicked();
	void Aboutsof();
	void openfile();
	void savefile();
	void saveas();
	void ClearUI();
	void closeEvent(QCloseEvent *);
	void DataChange();
	void GetShapeNum();

private:
	QString								Openfilepath;		// 打开文件路径
	QString								SaveAspath;			// 另存为路径
	QString								Originpath;			// 原始路径
	QVector<MyShape>					shapeData;			// 保存打开文件的数据
	int									m_ShapeNum;			// 当前图形数目
};

#endif