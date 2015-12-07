#include "mainwindow.h"

MainWindow::MainWindow(QWidget*parent) : QMainWindow(parent)
{
	// ToolBar&ActionGroup
	changed = 0;
	Originpath = "untitled";
	m_ShapeNum = 0;
	QToolBar* Toobar = this->addToolBar(QString::fromLocal8Bit("������"));
	QActionGroup* actionGroup1 = new QActionGroup(Toobar);					// ��û��ActionGroup������³��󲻻�����
	QActionGroup* actionGroup2 = new QActionGroup(Toobar);
	QActionGroup* actionGroup3 = new QActionGroup(Toobar);
	QActionGroup* actionGroup4 = new QActionGroup(Toobar);
	QActionGroup* actionGroup5 = new QActionGroup(Toobar);

	// OpenFileѡ��
	QAction* QOpenfile = new QAction(QString::fromLocal8Bit("��"), Toobar);
	QOpenfile->setCheckable(false);											// ��ѡ�У������ͼ�겻�³�
	QOpenfile->setChecked(false);
	actionGroup1->addAction(QOpenfile);
	Toobar->addAction(QOpenfile);
	QOpenfile->setToolTip(QString::fromLocal8Bit("���ļ�"));
	QOpenfile->setStatusTip(QString::fromLocal8Bit("�������ļ�"));

	// SaveFileѡ��
	QAction* QSavefile = new QAction(QString::fromLocal8Bit("����"), Toobar);
	QSavefile->setCheckable(false);
	QSavefile->setChecked(false);
	actionGroup1->addAction(QSavefile);
	Toobar->addAction(QSavefile);
	QSavefile->setToolTip(QString::fromLocal8Bit("�����ļ�"));
	QSavefile->setStatusTip(QString::fromLocal8Bit("���浱ǰ�ļ�"));

	// SaveAsѡ��
	QAction* QSaveAs = new QAction(QString::fromLocal8Bit("���Ϊ"), Toobar);
	QSaveAs->setCheckable(false);
	QSaveAs->setChecked(false);
	actionGroup1->addAction(QSaveAs);
	Toobar->addAction(QSaveAs);
	QSaveAs->setToolTip(QString::fromLocal8Bit("���Ϊ"));
	QSaveAs->setStatusTip(QString::fromLocal8Bit("���ΪTXT"));

	// GetCurrrentShapeNumѡ��
	QAction* QGetShapeNum = new QAction(QString::fromLocal8Bit("ͳ��"), Toobar);
	QGetShapeNum->setCheckable(false);
	QGetShapeNum->setChecked(false);
	actionGroup3->addAction(QGetShapeNum);
	Toobar->addAction(QGetShapeNum);
	QGetShapeNum->setToolTip(QString::fromLocal8Bit("ͳ��"));
	QGetShapeNum->setStatusTip(QString::fromLocal8Bit("ͳ��ͼ����Ŀ"));

	// DrawCurveѡ��
	QAction* drawCurveAction = new QAction(QString::fromLocal8Bit("����"), Toobar);
	drawCurveAction->setCheckable(true);
	drawCurveAction->setChecked(true);
	actionGroup2->addAction(drawCurveAction);
	Toobar->addAction(drawCurveAction);
	drawCurveAction->setToolTip(QString::fromLocal8Bit("��������"));
	drawCurveAction->setStatusTip(QString::fromLocal8Bit("������������"));

	// DrawLineѡ��
	QAction* drawLineAction = new QAction(QString::fromLocal8Bit("ֱ��"), Toobar);
	drawLineAction->setCheckable(true);										 // ��ѡ�У������ͼ���³�
	drawLineAction->setChecked(false);										 // ��ѡ��
	actionGroup2->addAction(drawLineAction);								 // ���������drawline����
	Toobar->addAction(drawLineAction);										 // ���������drawline����
	drawLineAction->setToolTip(QString::fromLocal8Bit("����ֱ��"));			 // ��������ʾ
	drawLineAction->setStatusTip(QString::fromLocal8Bit("����һ��ֱ��"));	 // ״̬����ʾ

	// DrawRectangleѡ��
	QAction* drawRectAction = new QAction(QString::fromLocal8Bit("����"), Toobar);
	drawRectAction->setCheckable(true);
	drawRectAction->setChecked(false);
	actionGroup2->addAction(drawRectAction);
	Toobar->addAction(drawRectAction);
	drawRectAction->setToolTip(QString::fromLocal8Bit("���ƾ���"));
	drawRectAction->setStatusTip(QString::fromLocal8Bit("����һ������"));

	// DrawCircleѡ��
	QAction* drawCircleAction = new QAction(QString::fromLocal8Bit("Բ��"), Toobar);
	drawCircleAction->setCheckable(true);
	drawCircleAction->setChecked(false);
	actionGroup2->addAction(drawCircleAction);
	Toobar->addAction(drawCircleAction);
	drawCircleAction->setToolTip(QString::fromLocal8Bit("����Բ��"));
	drawCircleAction->setStatusTip(QString::fromLocal8Bit("����һ��Բ"));

	// ClearDrawѡ��
	QAction* clearUi = new QAction(QString::fromLocal8Bit("���"), Toobar);
	clearUi->setCheckable(false);
	clearUi->setChecked(false);
	actionGroup3->addAction(clearUi);
	Toobar->addAction(clearUi);
	clearUi->setToolTip(QString::fromLocal8Bit("���"));
	clearUi->setStatusTip(QString::fromLocal8Bit("��յ�ǰ����"));

	// SetPenWidthѡ��
	// 1
	QAction* QSetWidth1 = new QAction(QString::fromLocal8Bit("���:1"), Toobar);
	QSetWidth1->setCheckable(true);
	QSetWidth1->setChecked(true);
	actionGroup4->addAction(QSetWidth1);
	QSetWidth1->setStatusTip(QString::fromLocal8Bit("���ʿ��Ϊ1"));
	// 2
	QAction* QSetWidth2 = new QAction(QString::fromLocal8Bit("���:2"), Toobar);
	QSetWidth2->setCheckable(true);
	QSetWidth2->setChecked(false);
	actionGroup4->addAction(QSetWidth2);
	QSetWidth2->setStatusTip(QString::fromLocal8Bit("���ʿ��Ϊ2"));
	// 3
	QAction* QSetWidth3 = new QAction(QString::fromLocal8Bit("���:3"), Toobar);
	QSetWidth3->setCheckable(true);
	QSetWidth3->setChecked(false);
	actionGroup4->addAction(QSetWidth3);
	QSetWidth3->setStatusTip(QString::fromLocal8Bit("���ʿ��Ϊ3"));
	// 4
	QAction* QSetWidth4 = new QAction(QString::fromLocal8Bit("���:4"), Toobar);
	QSetWidth4->setCheckable(true);
	QSetWidth4->setChecked(false);
	actionGroup4->addAction(QSetWidth4);
	QSetWidth4->setStatusTip(QString::fromLocal8Bit("���ʿ��Ϊ4"));

	// SetPenColorѡ��
	// black
	QAction* QSetColorBlack = new QAction(QString::fromLocal8Bit("��ɫ:��ɫ"), Toobar);
	QSetColorBlack->setCheckable(true);
	QSetColorBlack->setChecked(true);
	actionGroup5->addAction(QSetColorBlack);
	QSetColorBlack->setStatusTip(QString::fromLocal8Bit("������ɫΪ��ɫ"));
	// blue
	QAction* QSetColorBlue = new QAction(QString::fromLocal8Bit("��ɫ:��ɫ"), Toobar);
	QSetColorBlue->setCheckable(true);
	QSetColorBlue->setChecked(false);
	actionGroup5->addAction(QSetColorBlue);
	QSetColorBlue->setStatusTip(QString::fromLocal8Bit("������ɫΪ��ɫ"));
	// red
	QAction* QSetColorRed = new QAction(QString::fromLocal8Bit("��ɫ:��ɫ"), Toobar);
	QSetColorRed->setCheckable(true);
	QSetColorRed->setChecked(false);
	actionGroup5->addAction(QSetColorRed);
	QSetColorRed->setStatusTip(QString::fromLocal8Bit("������ɫΪ��ɫ"));
	// green
	QAction* QSetColorGreen = new QAction(QString::fromLocal8Bit("��ɫ:��ɫ"), Toobar);
	QSetColorGreen->setCheckable(true);
	QSetColorGreen->setChecked(false);
	actionGroup5->addAction(QSetColorGreen);
	QSetColorGreen->setStatusTip(QString::fromLocal8Bit("������ɫΪ��ɫ"));

	// AboutSofѡ��
	QAction* QAbout = new QAction(QString::fromLocal8Bit("����"), Toobar);
	QAbout->setCheckable(false);
	QAbout->setChecked(false);
	actionGroup5->addAction(QAbout);
	Toobar->addAction(QAbout);
	QAbout->setToolTip(QString::fromLocal8Bit("�������"));
	QAbout->setStatusTip(QString::fromLocal8Bit("�������"));

	// MeauBar
	QMenu* menu1 = menuBar()->addMenu(QString::fromLocal8Bit("�ļ�"));
	menu1->addAction(QOpenfile);
	menu1->addAction(QSavefile);
	menu1->addAction(QSaveAs);
	QMenu* menu2 = menuBar()->addMenu(QString::fromLocal8Bit("��������"));
	menu2->addAction(drawCurveAction);
	menu2->addAction(drawLineAction);
	menu2->addAction(drawRectAction);
	menu2->addAction(drawCircleAction);
	QMenu* menu3 = menuBar()->addMenu(QString::fromLocal8Bit("���ʿ��"));
	menu3->addAction(QSetWidth1);
	menu3->addAction(QSetWidth2);
	menu3->addAction(QSetWidth3);
	menu3->addAction(QSetWidth4);
	QMenu* menu4 = menuBar()->addMenu(QString::fromLocal8Bit("������ɫ"));
	menu4->addAction(QSetColorBlack);
	menu4->addAction(QSetColorBlue);
	menu4->addAction(QSetColorRed);
	menu4->addAction(QSetColorGreen);
	QMenu* menu5 = menuBar()->addMenu(QString::fromLocal8Bit("����"));
	menu5->addAction(clearUi);
	menu5->addAction(QGetShapeNum);
	QMenu* menu6 = menuBar()->addMenu(QString::fromLocal8Bit("����"));
	menu6->addAction(QAbout);

	// Workspace
	m_paintWidget = new PaintWidget(0);
	setCentralWidget(m_paintWidget);

	/*�źŲ�(�źŲ�Ҫ���źźͲ۵Ĳ���һ�£���νһ�£��ǲ�������һ�¡�
	�����һ�£����������ǣ��ۺ����Ĳ������Ա��źŵ��٣�������ˣ���
	�������ڵ���Щ������˳��Ҳ������źŵ�ǰ�漸��һ��������)*/

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
	// �ڴ�ʱ����Ƿ���������
	if (!shapeData.isEmpty())
	{
		QMessageBox msg(this);
		msg.setText(QString::fromLocal8Bit("�ļ��Ѿ��ı�"));
		// �Ѵ��ļ�
		if (Originpath == Openfilepath)
		{
			msg.setInformativeText(QString::fromLocal8Bit("����Ҫ���浽 ") + Openfilepath + QString::fromLocal8Bit(" ��"));
		}
		// δ���ļ�
		else
		{
			msg.setInformativeText(QString::fromLocal8Bit("����Ҫ�����ļ��� "));
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

	// ʹ��QFileDialog::getOpenFileName()����ȡ��Ҫ�򿪵��ļ���·��������������
	Openfilepath = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));
	// �򿪺�ı�Originpath
	Originpath = Openfilepath;
	if (!Openfilepath.isEmpty())
	{
		QFile file(Openfilepath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("���ļ�"), QString::fromLocal8Bit("���ܴ��ļ�\n%1").arg(Openfilepath));
			return;
		}
		QTextStream in(&file);
		while (!in.atEnd())
		{
			QString dataTemp = in.readLine();							// ��ȡһ������
			QStringList list = dataTemp.split(QRegExp(" "));			// ��ÿһ����װ��һ��QStringList��
			bool bRight;
			int nval;
			MyShape shapeTemp;
			for (int i = 0; i < list.size(); i++)
			{
				QString strTemp = list.at(i);							// list�����ַ�
				int nval = strTemp.toInt(&bRight);						// ת����int

				if (bRight && i == 0)
				{
					shapeTemp.nType = (shapetype)nval;					// ǿתΪshapetype
				}
				else if (bRight && i == 1)
				{
					shapeTemp.StartPnt.setX(nval);						// QPoint����ֱ�Ӹ�ֵ����setX����
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
					QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ݳ���"), QMessageBox::Ok);
				}
			}
			// �õ���shapeData��Ϊ�洢���ݵ������������������Ҫ�����
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
	// δ���ļ������
	if (Originpath == "untitled")
	{
		SaveAspath = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("�����ļ�"), ".", tr("Text Files(*.txt)"));
		if (!SaveAspath.isEmpty())
		{
			QFile file(SaveAspath);
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("�����ļ�"), QString::fromLocal8Bit("���ܱ����ļ�: \n%1").arg(SaveAspath));
				return;
			}
			QTextStream out(&file);
			// ������ݵ�TXT
			for (int i = 0; i < shapeData.size(); i++)
			{
				MyShape shapeTemp = shapeData.at(i);							// ��ҪTempȡ��shapeData��ֵ
				out << QString::number(shapeTemp.nType) << " "					// ������תΪ�ַ�����QString::number
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
	// �Ѵ��ļ������
	if (Originpath == Openfilepath)
	{
		QFile file(Openfilepath);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("�����ļ�"), QString::fromLocal8Bit("���ܱ����ļ�: \n%1").arg(Openfilepath));
			return;
		}
		QTextStream out(&file);
		// ������ݵ�TXT
		for (int i = 0; i < shapeData.size(); i++)
		{
			MyShape shapeTemp = shapeData.at(i);					// ��ҪTempȡ��shapeData��ֵ
			out << QString::number(shapeTemp.nType) << " "
				<< QString::number(shapeTemp.StartPnt.x()) << " "
				<< QString::number(shapeTemp.StartPnt.y()) << " "
				<< QString::number(shapeTemp.EndPnt.x()) << " "
				<< QString::number(shapeTemp.EndPnt.y()) << "\n";
		}															// ���ʱ������תΪ�ַ�����QString::number
		file.close();
		this->setWindowTitle(Openfilepath + "-TXT");
		changed = 0;
	}
}

void MainWindow::saveas()
{
	SaveAspath = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("�����ļ�"), ".", tr("Text Files(*.txt)"));
	if (!SaveAspath.isEmpty())
	{
		QFile file(SaveAspath);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("�����ļ�"), QString::fromLocal8Bit("���ܱ����ļ�: \n%1").arg(SaveAspath));
			return;
		}
		QTextStream out(&file);
		// ������ݵ�TXT
		for (int i = 0; i < shapeData.size(); i++)
		{
			MyShape shapeTemp = shapeData.at(i);							// ��ҪTempȡ��shapeData��ֵ
			out << QString::number(shapeTemp.nType) << " "					// ������תΪ�ַ�����QString::number
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
	this->setWindowTitle(QString::fromLocal8Bit("����---�汾1.5"));
}

void MainWindow::Aboutsof()
{
	QMessageBox::information(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit(
		"������ƣ�����\n"
		"�汾��1.5\n"
		"������ڣ�2015.12.07"));
}

void MainWindow::GetShapeNum()
{
	m_paintWidget->getCurrentShapeNum(m_ShapeNum);
	QMessageBox::information(this, QString::fromLocal8Bit("ͼ����Ŀͳ��"), QString::fromLocal8Bit("��ǰ������: ") + QString::number(m_ShapeNum) + QString::fromLocal8Bit(" ��ͼ��"));
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
		msg.setText(QString::fromLocal8Bit("�ļ��Ѿ��ı�"));
		// �Ѵ��ļ�
		if (Originpath == Openfilepath)
		{
			msg.setInformativeText(QString::fromLocal8Bit("����Ҫ���浽 ") + Openfilepath + QString::fromLocal8Bit(" ��"));
		}
		// δ���ļ�
		else
		{
			msg.setInformativeText(QString::fromLocal8Bit("����Ҫ�����ļ��� "));
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

