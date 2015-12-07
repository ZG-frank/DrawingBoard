#include "drawingboard.h"
#include <QtWidgets/QApplication>
#include <mainwindow.h>
#include <QSplashScreen>  
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// 启动动画，cool
	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap("G://TX/TX1.jpg"));
	splash->show();
	// 让对话框延迟一段时间显示  
	for (int i = 0; i < 2000; i++)
	{
		splash->repaint();
	}

	MainWindow* mainwindow = new MainWindow(NULL);
	mainwindow->setWindowTitle(QString::fromLocal8Bit("画板---版本1.5"));
	mainwindow->showMaximized();
	mainwindow->show();
	return a.exec();
}
