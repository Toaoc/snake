#pragma once
#ifndef RANK_H
#define RANK_H
#include<QMainWindow>
#include<QPushButton>
#include<QString>
#include<QTextEdit>
#include<QToolBar>
class rankWidget :public QMainWindow
{
	Q_OBJECT
signals:
	void sonclose();
private:
	QPushButton *back;
	QTextEdit *textBox;
	QToolBar *toolbar;
public:
	rankWidget(QWidget *parent = 0);
public slots:
	void sendclose();
};
#endif // !RANK_H
