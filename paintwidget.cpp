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
	// 创建绘画工具(可以只创建一次吗)
	QPainter painter(this);
	QPen pen;
	// 改变线条大小
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
	// 改变颜色
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
	// 抗锯齿
	painter.setRenderHint(QPainter::Antialiasing, true);

	// 为了实时绘制直线，矩形和圆
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

	// 绘制Vec中的数据
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
	this->setCursor(Qt::PointingHandCursor);								// 手型光标
	isPressed = true;
	m_CurShapes.nType = CurrentShape;
	m_CurShapes.StartPnt = event->pos();									// 存储起点信息
	if (m_CurShapes.nType == SHAPE_TYPE_CURVE)
	{
		m_CurShapes.EndPnt = event->pos();								// 如果是曲线，存储终点信息
	}
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (isPressed)
	{
		m_CurShapes.EndPnt = event->pos();								// 记录终点坐标
		update();
		if (m_CurShapes.nType == SHAPE_TYPE_CURVE)
		{
			m_CurShapes.EndPnt = event->pos();							// 记录终点坐标(曲线)
			m_DataList.push_back(m_CurShapes);							// 马上pushback到Vec里
			update();													// 绘制第一段
			m_CurShapes.StartPnt = m_CurShapes.EndPnt;					// 下一段的起点就是上一段的终点
		}
	}
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
	this->setCursor(Qt::ArrowCursor);									// 箭头鼠标
	isPressed = false;
	m_DataList.push_back(m_CurShapes);									// 存储全部信息
	++CurrentShapeNum;
}

// 复制数据到mainwindow
void PaintWidget::getData(QVector<MyShape>& ShapeList)
{
	ShapeList = m_DataList;
}

void PaintWidget::getCurrentShapeNum(int& Nums)
{
	Nums = CurrentShapeNum;
}

// 复制数据到paintwidget(一定要用List来画，否则只会显示一个)
void PaintWidget::loadDataandPaint(QVector<MyShape> ShapeList)
{
	m_DataList = ShapeList;
	update();
}

void PaintWidget::ClearDraw()
{
	// 清空数据
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