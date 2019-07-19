#pragma once
#ifndef RANK_H
#define RANK_H
#include<QMainWindow>
#include<QPushButton>
#include<QString>
#include<QTextEdit>
#include<QToolBar>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
class rankWidget :public QMainWindow
{
	Q_OBJECT
signals:
	void sonclose();
private:
	QPushButton *back;
	QTextEdit *textBox;
	QToolBar *toolbar;
	QFile *file;
	QMessageBox *errorOpen;
	QTextStream *in;
public:
	rankWidget(QWidget *parent = 0);
public slots:
	void sendclose();
};
#endif // !RANK_H
