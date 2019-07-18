#include"mainwindow.h"
#include <QtWidgets/QApplication>
#include<QTextEdit>
#include<QPushButton>
#include<QGridlayout>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainWidget *m;
	m = new mainWidget;
	m->show();
	QObject::connect(m, &mainWidget::closeAll, &a, &QApplication::quit);
	return a.exec();
}
