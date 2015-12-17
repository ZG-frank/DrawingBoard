#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QVector>
#include <QMessageBox>
#include <math.h>

enum shapetype
{
	SHAPE_TYPE_CURVE,
	SHAPE_TYPE_LINE,
	SHAPE_TYPE_RECT,
	SHAPE_TYPE_CIRCLE,
};

enum Penwidth
{
	WIDTH_ONE,
	WIDTH_TWO,
	WIDTH_THREE,
	WIDTH_FOUR,
};

enum Pencolor
{
	COLOR_BLACK,
	COLOR_BLUE,
	COLOR_RED,
	COLOR_GREEN,
};

typedef struct _MyShape
{
	shapetype nType;
	QPoint StartPnt;
	QPoint EndPnt;
	
	_MyShape()
	{
		nType = SHAPE_TYPE_CURVE;
		StartPnt = QPoint();
		EndPnt = QPoint();
	}

	_MyShape(shapetype a, QPoint b, QPoint c)
	{
		nType = a;
		StartPnt = b;
		EndPnt = c;
	}
}MyShape;

class PaintWidget : public QWidget
{
	Q_OBJECT;

public:
	PaintWidget(QWidget* parent);
	~PaintWidget();
	void getData(QVector<MyShape>& ShapeList);			// ��mainwindow
	void loadDataandPaint(QVector<MyShape> ShapeList);	// ��ȡʱû����
	void ClearDraw();									// ��������ϵ�
	void paintEvent(QPaintEvent *p);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void getCurrentShapeNum(int& Nums);

private:
	MyShape							m_CurShapes;		// MyShape����
	QVector<MyShape>				m_DataList;			// ��¼�ѻ�����״��Ϣ
	bool							isPressed;			// ����Ƿ���
	shapetype						CurrentShape;		// ��ǰ���Ķ���
	Penwidth						CurrentWidth;		// ��ǰ���ʿ��
	Pencolor						CurrentColor;		// ��ǰ������ɫ
	int								CurrentShapeNum;	// ��ǰͼ����Ŀ

public slots:
	void SetCurrentShape(shapetype);
	void SetCurrentWidth(Penwidth);
	void SetCurrentColor(Pencolor);
};
#endif