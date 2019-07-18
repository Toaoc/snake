#pragma once
#ifndef INDUCE_H
#define INDUCE_H
#include<QMainWindow>
#include<QPushButton>
#include<QTextEdit>
#include<QToolBar>
#include<QString>
class induceWidget :public QMainWindow
{
	Q_OBJECT
private:
	QPushButton *back;
	QTextEdit *textBox;
	QToolBar *toolbar;
signals:
	void sonclose();
public:
	induceWidget(QWidget *parent = 0);
public slots:
	void sendclose();
};
#endif // !INDUCE_H
