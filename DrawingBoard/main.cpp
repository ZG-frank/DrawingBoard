#include "drawingboard.h"
#include <QtWidgets/QApplication>
#include <mainwindow.h>
#include <QSplashScreen>  
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// ����������cool
	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap("G://TX/TX1.jpg"));
	splash->show();
	// �öԻ����ӳ�һ��ʱ����ʾ  
	for (int i = 0; i < 2000; i++)
	{
		splash->repaint();
	}

	MainWindow* mainwindow = new MainWindow(NULL);
	mainwindow->setWindowTitle(QString::fromLocal8Bit("����---�汾1.5"));
	mainwindow->showMaximized();
	mainwindow->show();
	return a.exec();
}
