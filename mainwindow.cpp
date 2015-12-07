#include "mainwindow.h"

MainWindow::MainWindow(QWidget*parent) : QMainWindow(parent)
{
	// ToolBar&ActionGroup
	changed = 0;
	Originpath = "untitled";
	m_ShapeNum = 0;
	QToolBar* Toobar = this->addToolBar(QString::fromLocal8Bit("工具栏"));
	QActionGroup* actionGroup1 = new QActionGroup(Toobar);					// 若没有ActionGroup，点击下沉后不会起来
	QActionGroup* actionGroup2 = new QActionGroup(Toobar);
	QActionGroup* actionGroup3 = new QActionGroup(Toobar);
	QActionGroup* actionGroup4 = new QActionGroup(Toobar);
	QActionGroup* actionGroup5 = new QActionGroup(Toobar);

	// OpenFile选项
	QAction* QOpenfile = new QAction(QString::fromLocal8Bit("打开"), Toobar);
	QOpenfile->setCheckable(false);											// 可选中，点击后图标不下沉
	QOpenfile->setChecked(false);
	actionGroup1->addAction(QOpenfile);
	Toobar->addAction(QOpenfile);
	QOpenfile->setToolTip(QString::fromLocal8Bit("打开文件"));
	QOpenfile->setStatusTip(QString::fromLocal8Bit("打开已有文件"));

	// SaveFile选项
	QAction* QSavefile = new QAction(QString::fromLocal8Bit("保存"), Toobar);
	QSavefile->setCheckable(false);
	QSavefile->setChecked(false);
	actionGroup1->addAction(QSavefile);
	Toobar->addAction(QSavefile);
	QSavefile->setToolTip(QString::fromLocal8Bit("保存文件"));
	QSavefile->setStatusTip(QString::fromLocal8Bit("保存当前文件"));

	// SaveAs选项
	QAction* QSaveAs = new QAction(QString::fromLocal8Bit("另存为"), Toobar);
	QSaveAs->setCheckable(false);
	QSaveAs->setChecked(false);
	actionGroup1->addAction(QSaveAs);
	Toobar->addAction(QSaveAs);
	QSaveAs->setToolTip(QString::fromLocal8Bit("另存为"));
	QSaveAs->setStatusTip(QString::fromLocal8Bit("另存为TXT"));

	// GetCurrrentShapeNum选项
	QAction* QGetShapeNum = new QAction(QString::fromLocal8Bit("统计"), Toobar);
	QGetShapeNum->setCheckable(false);
	QGetShapeNum->setChecked(false);
	actionGroup3->addAction(QGetShapeNum);
	Toobar->addAction(QGetShapeNum);
	QGetShapeNum->setToolTip(QString::fromLocal8Bit("统计"));
	QGetShapeNum->setStatusTip(QString::fromLocal8Bit("统计图形数目"));

	// DrawCurve选项
	QAction* drawCurveAction = new QAction(QString::fromLocal8Bit("曲线"), Toobar);
	drawCurveAction->setCheckable(true);
	drawCurveAction->setChecked(true);
	actionGroup2->addAction(drawCurveAction);
	Toobar->addAction(drawCurveAction);
	drawCurveAction->setToolTip(QString::fromLocal8Bit("绘制曲线"));
	drawCurveAction->setStatusTip(QString::fromLocal8Bit("绘制连续曲线"));

	// DrawLine选项
	QAction* drawLineAction = new QAction(QString::fromLocal8Bit("直线"), Toobar);
	drawLineAction->setCheckable(true);										 // 可选中，点击后图标下沉
	drawLineAction->setChecked(false);										 // 已选中
	actionGroup2->addAction(drawLineAction);								 // 动作组添加drawline动作
	Toobar->addAction(drawLineAction);										 // 工具栏添加drawline动作
	drawLineAction->setToolTip(QString::fromLocal8Bit("绘制直线"));			 // 工具栏提示
	drawLineAction->setStatusTip(QString::fromLocal8Bit("绘制一条直线"));	 // 状态栏提示

	// DrawRectangle选项
	QAction* drawRectAction = new QAction(QString::fromLocal8Bit("矩形"), Toobar);
	drawRectAction->setCheckable(true);
	drawRectAction->setChecked(false);
	actionGroup2->addAction(drawRectAction);
	Toobar->addAction(drawRectAction);
	drawRectAction->setToolTip(QString::fromLocal8Bit("绘制矩形"));
	drawRectAction->setStatusTip(QString::fromLocal8Bit("绘制一个矩形"));

	// DrawCircle选项
	QAction* drawCircleAction = new QAction(QString::fromLocal8Bit("圆形"), Toobar);
	drawCircleAction->setCheckable(true);
	drawCircleAction->setChecked(false);
	actionGroup2->addAction(drawCircleAction);
	Toobar->addAction(drawCircleAction);
	drawCircleAction->setToolTip(QString::fromLocal8Bit("绘制圆形"));
	drawCircleAction->setStatusTip(QString::fromLocal8Bit("绘制一个圆"));

	// ClearDraw选项
	QAction* clearUi = new QAction(QString::fromLocal8Bit("清空"), Toobar);
	clearUi->setCheckable(false);
	clearUi->setChecked(false);
	actionGroup3->addAction(clearUi);
	Toobar->addAction(clearUi);
	clearUi->setToolTip(QString::fromLocal8Bit("清空"));
	clearUi->setStatusTip(QString::fromLocal8Bit("清空当前桌面"));

	// SetPenWidth选项
	// 1
	QAction* QSetWidth1 = new QAction(QString::fromLocal8Bit("宽度:1"), Toobar);
	QSetWidth1->setCheckable(true);
	QSetWidth1->setChecked(true);
	actionGroup4->addAction(QSetWidth1);
	QSetWidth1->setStatusTip(QString::fromLocal8Bit("画笔宽度为1"));
	// 2
	QAction* QSetWidth2 = new QAction(QString::fromLocal8Bit("宽度:2"), Toobar);
	QSetWidth2->setCheckable(true);
	QSetWidth2->setChecked(false);
	actionGroup4->addAction(QSetWidth2);
	QSetWidth2->setStatusTip(QString::fromLocal8Bit("画笔宽度为2"));
	// 3
	QAction* QSetWidth3 = new QAction(QString::fromLocal8Bit("宽度:3"), Toobar);
	QSetWidth3->setCheckable(true);
	QSetWidth3->setChecked(false);
	actionGroup4->addAction(QSetWidth3);
	QSetWidth3->setStatusTip(QString::fromLocal8Bit("画笔宽度为3"));
	// 4
	QAction* QSetWidth4 = new QAction(QString::fromLocal8Bit("宽度:4"), Toobar);
	QSetWidth4->setCheckable(true);
	QSetWidth4->setChecked(false);
	actionGroup4->addAction(QSetWidth4);
	QSetWidth4->setStatusTip(QString::fromLocal8Bit("画笔宽度为4"));

	// SetPenColor选项
	// black
	QAction* QSetColorBlack = new QAction(QString::fromLocal8Bit("颜色:黑色"), Toobar);
	QSetColorBlack->setCheckable(true);
	QSetColorBlack->setChecked(true);
	actionGroup5->addAction(QSetColorBlack);
	QSetColorBlack->setStatusTip(QString::fromLocal8Bit("画笔颜色为黑色"));
	// blue
	QAction* QSetColorBlue = new QAction(QString::fromLocal8Bit("颜色:蓝色"), Toobar);
	QSetColorBlue->setCheckable(true);
	QSetColorBlue->setChecked(false);
	actionGroup5->addAction(QSetColorBlue);
	QSetColorBlue->setStatusTip(QString::fromLocal8Bit("画笔颜色为蓝色"));
	// red
	QAction* QSetColorRed = new QAction(QString::fromLocal8Bit("颜色:红色"), Toobar);
	QSetColorRed->setCheckable(true);
	QSetColorRed->setChecked(false);
	actionGroup5->addAction(QSetColorRed);
	QSetColorRed->setStatusTip(QString::fromLocal8Bit("画笔颜色为红色"));
	// green
	QAction* QSetColorGreen = new QAction(QString::fromLocal8Bit("颜色:绿色"), Toobar);
	QSetColorGreen->setCheckable(true);
	QSetColorGreen->setChecked(false);
	actionGroup5->addAction(QSetColorGreen);
	QSetColorGreen->setStatusTip(QString::fromLocal8Bit("画笔颜色为绿色"));

	// AboutSof选项
	QAction* QAbout = new QAction(QString::fromLocal8Bit("关于"), Toobar);
	QAbout->setCheckable(false);
	QAbout->setChecked(false);
	actionGroup5->addAction(QAbout);
	Toobar->addAction(QAbout);
	QAbout->setToolTip(QString::fromLocal8Bit("关于软件"));
	QAbout->setStatusTip(QString::fromLocal8Bit("关于软件"));

	// MeauBar
	QMenu* menu1 = menuBar()->addMenu(QString::fromLocal8Bit("文件"));
	menu1->addAction(QOpenfile);
	menu1->addAction(QSavefile);
	menu1->addAction(QSaveAs);
	QMenu* menu2 = menuBar()->addMenu(QString::fromLocal8Bit("绘制类型"));
	menu2->addAction(drawCurveAction);
	menu2->addAction(drawLineAction);
	menu2->addAction(drawRectAction);
	menu2->addAction(drawCircleAction);
	QMenu* menu3 = menuBar()->addMenu(QString::fromLocal8Bit("画笔宽度"));
	menu3->addAction(QSetWidth1);
	menu3->addAction(QSetWidth2);
	menu3->addAction(QSetWidth3);
	menu3->addAction(QSetWidth4);
	QMenu* menu4 = menuBar()->addMenu(QString::fromLocal8Bit("画笔颜色"));
	menu4->addAction(QSetColorBlack);
	menu4->addAction(QSetColorBlue);
	menu4->addAction(QSetColorRed);
	menu4->addAction(QSetColorGreen);
	QMenu* menu5 = menuBar()->addMenu(QString::fromLocal8Bit("工具"));
	menu5->addAction(clearUi);
	menu5->addAction(QGetShapeNum);
	QMenu* menu6 = menuBar()->addMenu(QString::fromLocal8Bit("帮助"));
	menu6->addAction(QAbout);

	// Workspace
	m_paintWidget = new PaintWidget(0);
	setCentralWidget(m_paintWidget);

	/*信号槽(信号槽要求信号和槽的参数一致，所谓一致，是参数类型一致。
	如果不一致，允许的情况是，槽函数的参数可以比信号的少，即便如此，槽
	函数存在的那些参数的顺序也必须和信号的前面几个一致起来。)*/

	QObject::connect(QOpenfile, SIGNAL(triggered()), this, SLOT(openfile()));
	QObject::connect(QSavefile, SIGNAL(triggered()), this, SLOT(savefile()));
	QObject::connect(QSaveAs, SIGNAL(triggered()), this, SLOT(saveas()));
	QObject::connect(clearUi, SIGNAL(triggered()), this, SLOT(ClearUI()));
	QObject::connect(QAbout, SIGNAL(triggered()), this, SLOT(Aboutsof()));
	QObject::connect(QGetShapeNum, SIGNAL(triggered()), this, SLOT(GetShapeNum()));

	QObject::connect(drawLineAction, SIGNAL(triggered()), this, SLOT(DrawLineActionClicked()));
	QObject::connect(drawRectAction, SIGNAL(triggered()), this, SLOT(DrawRectActionClicked()));
	QObject::connect(drawCircleAction, SIGNAL(triggered()), this, SLOT(DrawCircleActionClicked()));
	QObject::connect(drawCurveAction, SIGNAL(triggered()), this, SLOT(DrawCurveActionClicked()));
	QObject::connect(this, SIGNAL(setshape(shapetype)), m_paintWidget, SLOT(SetCurrentShape(shapetype)));

	QObject::connect(QSetWidth1, SIGNAL(triggered()), this, SLOT(SetPenWidth1Clicked()));
	QObject::connect(QSetWidth2, SIGNAL(triggered()), this, SLOT(SetPenWidth2Clicked()));
	QObject::connect(QSetWidth3, SIGNAL(triggered()), this, SLOT(SetPenWidth3Clicked()));
	QObject::connect(QSetWidth4, SIGNAL(triggered()), this, SLOT(SetPenWidth4Clicked()));
	QObject::connect(this, SIGNAL(SetPenWidth(Penwidth)), m_paintWidget, SLOT(SetCurrentWidth(Penwidth)));

	QObject::connect(QSetColorBlack, SIGNAL(triggered()), this, SLOT(SetPenColorBlackClicked()));
	QObject::connect(QSetColorBlue, SIGNAL(triggered()), this, SLOT(SetPenColorBlueClicked()));
	QObject::connect(QSetColorRed, SIGNAL(triggered()), this, SLOT(SetPenColorRedClicked()));
	QObject::connect(QSetColorGreen, SIGNAL(triggered()), this, SLOT(SetPenColorGreenClicked()));
	QObject::connect(this, SIGNAL(SetPenColor(Pencolor)), m_paintWidget, SLOT(SetCurrentColor(Pencolor)));

	QObject::connect(this, SIGNAL(paintEvent(QPaintEvent*)), this, SLOT(DataChange()));
}

void MainWindow::openfile()
{
	// 在打开时检查是否已有数据
	if (!shapeData.isEmpty())
	{
		QMessageBox msg(this);
		msg.setText(QString::fromLocal8Bit("文件已经改变"));
		// 已打开文件
		if (Originpath == Openfilepath)
		{
			msg.setInformativeText(QString::fromLocal8Bit("你想要保存到 ") + Openfilepath + QString::fromLocal8Bit(" 吗？"));
		}
		// 未打开文件
		else
		{
			msg.setInformativeText(QString::fromLocal8Bit("你想要保存文件吗？ "));
		}
		msg.setIcon(QMessageBox::Question);
		msg.setStandardButtons(QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
		msg.setDefaultButton(QMessageBox::Cancel);
		int ret = msg.exec();
		switch (ret)
		{
		case QMessageBox::Save:
			savefile();
			shapeData.clear();
			m_paintWidget->ClearDraw();
			update();
			break;
		case QMessageBox::No:
			shapeData.clear();
			m_paintWidget->ClearDraw();
			update();
			break;
		case QMessageBox::Cancel:
			return;
			break;
		}
	}

	// 使用QFileDialog::getOpenFileName()来获取需要打开的文件的路径。有六个参数
	Openfilepath = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));
	// 打开后改变Originpath
	Originpath = Openfilepath;
	if (!Openfilepath.isEmpty())
	{
		QFile file(Openfilepath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("打开文件"), QString::fromLocal8Bit("不能打开文件\n%1").arg(Openfilepath));
			return;
		}
		QTextStream in(&file);
		while (!in.atEnd())
		{
			QString dataTemp = in.readLine();							// 读取一行数据
			QStringList list = dataTemp.split(QRegExp(" "));			// 把每一个块装进一个QStringList中
			bool bRight;
			int nval;
			MyShape shapeTemp;
			for (int i = 0; i < list.size(); i++)
			{
				QString strTemp = list.at(i);							// list里是字符
				int nval = strTemp.toInt(&bRight);						// 转换成int

				if (bRight && i == 0)
				{
					shapeTemp.nType = (shapetype)nval;					// 强转为shapetype
				}
				else if (bRight && i == 1)
				{
					shapeTemp.StartPnt.setX(nval);						// QPoint不能直接赋值，用setX函数
				}
				else if (bRight && i == 2)
				{
					shapeTemp.StartPnt.setY(nval);
				}
				else if (bRight && i == 3)
				{
					shapeTemp.EndPnt.setX(nval);
				}
				else if (bRight && i == 4)
				{
					shapeTemp.EndPnt.setY(nval);
				}
				else if (!bRight || i<0 || i>4)
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("内容出错"), QMessageBox::Ok);
				}
			}
			// 用的是shapeData作为存储数据的容器，所以上面必须要先清空
			shapeData.push_back(shapeTemp);
		}
		m_paintWidget->loadDataandPaint(shapeData);
		file.close();
		this->setWindowTitle(Openfilepath + "-TXT");
		changed = 0;
	}
}

void MainWindow::savefile()
{
	// 未打开文件的情况
	if (Originpath == "untitled")
	{
		SaveAspath = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存文件"), ".", tr("Text Files(*.txt)"));
		if (!SaveAspath.isEmpty())
		{
			QFile file(SaveAspath);
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("保存文件"), QString::fromLocal8Bit("不能保存文件: \n%1").arg(SaveAspath));
				return;
			}
			QTextStream out(&file);
			// 输出数据到TXT
			for (int i = 0; i < shapeData.size(); i++)
			{
				MyShape shapeTemp = shapeData.at(i);							// 需要Temp取得shapeData的值
				out << QString::number(shapeTemp.nType) << " "					// 将数字转为字符串用QString::number
					<< QString::number(shapeTemp.StartPnt.x()) << " "
					<< QString::number(shapeTemp.StartPnt.y()) << " "
					<< QString::number(shapeTemp.EndPnt.x()) << " "
					<< QString::number(shapeTemp.EndPnt.y()) << "\n";
			}
			file.close();
			this->setWindowTitle(SaveAspath + "-TXT");
			changed = 0;
		}
	}
	// 已打开文件的情况
	if (Originpath == Openfilepath)
	{
		QFile file(Openfilepath);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("保存文件"), QString::fromLocal8Bit("不能保存文件: \n%1").arg(Openfilepath));
			return;
		}
		QTextStream out(&file);
		// 输出数据到TXT
		for (int i = 0; i < shapeData.size(); i++)
		{
			MyShape shapeTemp = shapeData.at(i);					// 需要Temp取得shapeData的值
			out << QString::number(shapeTemp.nType) << " "
				<< QString::number(shapeTemp.StartPnt.x()) << " "
				<< QString::number(shapeTemp.StartPnt.y()) << " "
				<< QString::number(shapeTemp.EndPnt.x()) << " "
				<< QString::number(shapeTemp.EndPnt.y()) << "\n";
		}															// 输出时将数字转为字符串用QString::number
		file.close();
		this->setWindowTitle(Openfilepath + "-TXT");
		changed = 0;
	}
}

void MainWindow::saveas()
{
	SaveAspath = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存文件"), ".", tr("Text Files(*.txt)"));
	if (!SaveAspath.isEmpty())
	{
		QFile file(SaveAspath);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("保存文件"), QString::fromLocal8Bit("不能保存文件: \n%1").arg(SaveAspath));
			return;
		}
		QTextStream out(&file);
		// 输出数据到TXT
		for (int i = 0; i < shapeData.size(); i++)
		{
			MyShape shapeTemp = shapeData.at(i);							// 需要Temp取得shapeData的值
			out << QString::number(shapeTemp.nType) << " "					// 将数字转为字符串用QString::number
				<< QString::number(shapeTemp.StartPnt.x()) << " "
				<< QString::number(shapeTemp.StartPnt.y()) << " "
				<< QString::number(shapeTemp.EndPnt.x()) << " "
				<< QString::number(shapeTemp.EndPnt.y()) << "\n";
		}
		file.close();
		this->setWindowTitle(SaveAspath + "-TXT");
		changed = 0;
	}
}

void MainWindow::ClearUI()
{
	m_paintWidget->ClearDraw();
	update();
	this->setWindowTitle(QString::fromLocal8Bit("画板---版本1.5"));
}

void MainWindow::Aboutsof()
{
	QMessageBox::information(this, QString::fromLocal8Bit("关于软件"), QString::fromLocal8Bit(
		"软件名称：画板\n"
		"版本：1.5\n"
		"完成日期：2015.12.07"));
}

void MainWindow::GetShapeNum()
{
	m_paintWidget->getCurrentShapeNum(m_ShapeNum);
	QMessageBox::information(this, QString::fromLocal8Bit("图形数目统计"), QString::fromLocal8Bit("当前绘制了: ") + QString::number(m_ShapeNum) + QString::fromLocal8Bit(" 个图形"));
}

void MainWindow::DrawCurveActionClicked()
{
	emit setshape(SHAPE_TYPE_CURVE);
}

void MainWindow::DrawLineActionClicked()
{
	emit setshape(SHAPE_TYPE_LINE);
}

void MainWindow::DrawRectActionClicked()
{
	emit setshape(SHAPE_TYPE_RECT);
}

void MainWindow::DrawCircleActionClicked()
{
	emit setshape(SHAPE_TYPE_CIRCLE);
}

void MainWindow::SetPenWidth1Clicked()
{
	emit SetPenWidth(WIDTH_ONE);
}

void MainWindow::SetPenWidth2Clicked()
{
	emit SetPenWidth(WIDTH_TWO);
}

void MainWindow::SetPenWidth3Clicked()
{
	emit SetPenWidth(WIDTH_THREE);
}

void MainWindow::SetPenWidth4Clicked()
{
	emit SetPenWidth(WIDTH_FOUR);
}

void MainWindow::SetPenColorBlackClicked()
{
	emit SetPenColor(COLOR_BLACK);
}

void MainWindow::SetPenColorBlueClicked()
{
	emit SetPenColor(COLOR_BLUE);
}

void MainWindow::SetPenColorRedClicked()
{
	emit SetPenColor(COLOR_RED);
}

void MainWindow::SetPenColorGreenClicked()
{
	emit SetPenColor(COLOR_GREEN);
}

void MainWindow::DataChange()
{
	m_paintWidget->getData(shapeData);
	if (shapeData.isEmpty()) changed = 0;
	else changed = 1;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if (changed == 1)
	{
		QMessageBox msg(this);
		msg.setText(QString::fromLocal8Bit("文件已经改变"));
		// 已打开文件
		if (Originpath == Openfilepath)
		{
			msg.setInformativeText(QString::fromLocal8Bit("你想要保存到 ") + Openfilepath + QString::fromLocal8Bit(" 吗？"));
		}
		// 未打开文件
		else
		{
			msg.setInformativeText(QString::fromLocal8Bit("你想要保存文件吗？ "));
		}
		msg.setIcon(QMessageBox::Question);
		msg.setStandardButtons(QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
		msg.setDefaultButton(QMessageBox::Save);
		int ret = msg.exec();
		switch (ret)
		{
		case QMessageBox::Save:
			savefile();
			break;
		case QMessageBox::No:
			event->accept();										// accept the closeevent
			break;
		case QMessageBox::Cancel:
			event->ignore();										// ignore the closeevent
			break;
		}
	}
	else
		event->accept();
}

MainWindow :: ~MainWindow()
{

}

