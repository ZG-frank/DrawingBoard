#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent)
{
	isPressed = false;
	CurrentShape = SHAPE_TYPE_CURVE;
	CurrentWidth = WIDTH_ONE;
	m_DataList.clear();
	this->setMouseTracking(true);
	CurrentShapeNum = 0;
}

void PaintWidget::SetCurrentShape(shapetype Stype)
{
	CurrentShape = Stype;
}

void PaintWidget::SetCurrentWidth(Penwidth Pwidth)
{
	CurrentWidth = Pwidth;
}

void PaintWidget::SetCurrentColor(Pencolor Pcolor)
{
	CurrentColor = Pcolor;
}

void PaintWidget::paintEvent(QPaintEvent *p)
{
	// �����滭����(����ֻ����һ����)
	QPainter painter(this);
	QPen pen;
	// �ı�������С
	switch (CurrentWidth)
	{
	case WIDTH_ONE:
		pen.setWidth(1);
		break;
	case WIDTH_TWO:
		pen.setWidth(2);
		break;
	case WIDTH_THREE:
		pen.setWidth(3);
		break;
	case WIDTH_FOUR:
		pen.setWidth(4);
		break;
	}
	// �ı���ɫ
	switch (CurrentColor)
	{
	case COLOR_BLACK:
		pen.setColor(Qt::black);
		break;
	case COLOR_BLUE:
		pen.setColor(Qt::blue);
		break;
	case COLOR_RED:
		pen.setColor(Qt::red);
		break;
	case COLOR_GREEN:
		pen.setColor(Qt::green);
		break;
	}
	painter.setPen(pen);
	// �����
	painter.setRenderHint(QPainter::Antialiasing, true);

	// Ϊ��ʵʱ����ֱ�ߣ����κ�Բ
	switch (m_CurShapes.nType)
	{
	case SHAPE_TYPE_CURVE:
		painter.drawLine(m_CurShapes.StartPnt, m_CurShapes.EndPnt);
		break;
	case SHAPE_TYPE_LINE:
		painter.drawLine(m_CurShapes.StartPnt, m_CurShapes.EndPnt);
		break;
	case SHAPE_TYPE_RECT:
		painter.drawRect(m_CurShapes.StartPnt.x(), m_CurShapes.StartPnt.y(),
			m_CurShapes.EndPnt.x() - m_CurShapes.StartPnt.x(),
			m_CurShapes.EndPnt.y() - m_CurShapes.StartPnt.y());
		break;
	case SHAPE_TYPE_CIRCLE:
		painter.drawEllipse(m_CurShapes.StartPnt,
			int(sqrt(pow(m_CurShapes.StartPnt.x() - m_CurShapes.EndPnt.x(), 2)
			+ pow(m_CurShapes.StartPnt.y() - m_CurShapes.EndPnt.y(), 2))),
			int(sqrt(pow(m_CurShapes.StartPnt.x() - m_CurShapes.EndPnt.x(), 2)
			+ pow(m_CurShapes.StartPnt.y() - m_CurShapes.EndPnt.y(), 2))));
		break;
	default:
		break;
	}

	// ����Vec�е�����
	if (m_DataList.size() != 0)
	{
		for (int i = 0; i < m_DataList.size(); i++)
		{
			switch (m_DataList.at(i).nType)
			{
			case SHAPE_TYPE_CURVE:
				painter.drawLine(m_DataList.at(i).StartPnt, m_DataList.at(i).EndPnt);
				break;
			case SHAPE_TYPE_LINE:
				painter.drawLine(m_DataList.at(i).StartPnt, m_DataList.at(i).EndPnt);
				break;
			case SHAPE_TYPE_RECT:
				painter.drawRect(m_DataList.at(i).StartPnt.x(), m_DataList.at(i).StartPnt.y(),
					m_DataList.at(i).EndPnt.x() - m_DataList.at(i).StartPnt.x(),
					m_DataList.at(i).EndPnt.y() - m_DataList.at(i).StartPnt.y());
				break;
			case SHAPE_TYPE_CIRCLE:
				painter.drawEllipse(m_DataList.at(i).StartPnt,
					int(sqrt(pow(m_DataList.at(i).StartPnt.x() - m_DataList.at(i).EndPnt.x(), 2)
					+ pow(m_DataList.at(i).StartPnt.y() - m_DataList.at(i).EndPnt.y(), 2))),
					int(sqrt(pow(m_DataList.at(i).StartPnt.x() - m_DataList.at(i).EndPnt.x(), 2)
					+ pow(m_DataList.at(i).StartPnt.y() - m_DataList.at(i).EndPnt.y(), 2))));
				break;
			default:
				break;
			}
		}
	}

}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
	this->setCursor(Qt::PointingHandCursor);								// ���͹��
	isPressed = true;
	m_CurShapes.nType = CurrentShape;
	m_CurShapes.StartPnt = event->pos();									// �洢�����Ϣ
	if (m_CurShapes.nType == SHAPE_TYPE_CURVE)
	{
		m_CurShapes.EndPnt = event->pos();								// ��������ߣ��洢�յ���Ϣ
	}
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (isPressed)
	{
		m_CurShapes.EndPnt = event->pos();								// ��¼�յ�����
		update();
		if (m_CurShapes.nType == SHAPE_TYPE_CURVE)
		{
			m_CurShapes.EndPnt = event->pos();							// ��¼�յ�����(����)
			m_DataList.push_back(m_CurShapes);							// ����pushback��Vec��
			update();													// ���Ƶ�һ��
			m_CurShapes.StartPnt = m_CurShapes.EndPnt;					// ��һ�ε���������һ�ε��յ�
		}
	}
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
	this->setCursor(Qt::ArrowCursor);									// ��ͷ���
	isPressed = false;
	m_DataList.push_back(m_CurShapes);									// �洢ȫ����Ϣ
	++CurrentShapeNum;
}

// �������ݵ�mainwindow
void PaintWidget::getData(QVector<MyShape>& ShapeList)
{
	ShapeList = m_DataList;
}

void PaintWidget::getCurrentShapeNum(int& Nums)
{
	Nums = CurrentShapeNum;
}

// �������ݵ�paintwidget(һ��Ҫ��List����������ֻ����ʾһ��)
void PaintWidget::loadDataandPaint(QVector<MyShape> ShapeList)
{
	m_DataList = ShapeList;
	update();
}

void PaintWidget::ClearDraw()
{
	// �������
	m_CurShapes.nType = SHAPE_TYPE_CURVE;
	m_CurShapes.StartPnt.setX(0);
	m_CurShapes.StartPnt.setY(0);
	m_CurShapes.EndPnt.setX(0);
	m_CurShapes.EndPnt.setY(0);
	m_DataList.clear();
	CurrentShapeNum = 0;
}

PaintWidget::~PaintWidget()
{

}