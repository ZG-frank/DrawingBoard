/********************************************************************************
** Form generated from reading UI file 'drawingboard.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWINGBOARD_H
#define UI_DRAWINGBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawingBoardClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DrawingBoardClass)
    {
        if (DrawingBoardClass->objectName().isEmpty())
            DrawingBoardClass->setObjectName(QStringLiteral("DrawingBoardClass"));
        DrawingBoardClass->resize(600, 400);
        menuBar = new QMenuBar(DrawingBoardClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DrawingBoardClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DrawingBoardClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DrawingBoardClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DrawingBoardClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DrawingBoardClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DrawingBoardClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DrawingBoardClass->setStatusBar(statusBar);

        retranslateUi(DrawingBoardClass);

        QMetaObject::connectSlotsByName(DrawingBoardClass);
    } // setupUi

    void retranslateUi(QMainWindow *DrawingBoardClass)
    {
        DrawingBoardClass->setWindowTitle(QApplication::translate("DrawingBoardClass", "DrawingBoard", 0));
    } // retranslateUi

};

namespace Ui {
    class DrawingBoardClass: public Ui_DrawingBoardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGBOARD_H
