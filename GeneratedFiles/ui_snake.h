/********************************************************************************
** Form generated from reading UI file 'snake.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

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

class Ui_snakeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *snakeClass)
    {
        if (snakeClass->objectName().isEmpty())
            snakeClass->setObjectName(QStringLiteral("snakeClass"));
        snakeClass->resize(600, 400);
        menuBar = new QMenuBar(snakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        snakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(snakeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        snakeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(snakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        snakeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(snakeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        snakeClass->setStatusBar(statusBar);

        retranslateUi(snakeClass);

        QMetaObject::connectSlotsByName(snakeClass);
    } // setupUi

    void retranslateUi(QMainWindow *snakeClass)
    {
        snakeClass->setWindowTitle(QApplication::translate("snakeClass", "snake", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class snakeClass: public Ui_snakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
