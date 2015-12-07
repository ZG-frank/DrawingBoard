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
	void setshape(shapetype);								// �ı����ͼ�ε��ź�
	void paintEvent(QPaintEvent *);							// ���ƺ���
	void SetPenWidth(Penwidth);								// �ı仭�ʿ�ȵ��ź�
	void SetPenColor(Pencolor);								// �ı仭����ɫ���ź�

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
	QString								Openfilepath;		// ���ļ�·��
	QString								SaveAspath;			// ���Ϊ·��
	QString								Originpath;			// ԭʼ·��
	QVector<MyShape>					shapeData;			// ������ļ�������
	int									m_ShapeNum;			// ��ǰͼ����Ŀ
};

#endif