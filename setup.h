#pragma once
#ifndef SETUP_H
#define SETUP_H
#include<QWidget>
#include<QToolBar>
#include<QAction>
#include<QPushButton>
#include<QTextEdit>
#include<QGridLayout>
#include<QSlider>
#include<QRadioButton>
#include<QSpinBox>
#include<QLabel>
class setupWidget :public QWidget
{
	Q_OBJECT
signals:
	void sonclose();
	void stopMusic(bool);
protected:
	QGridLayout *setupLayout, *setupOpLayout;
	QWidget *setupOp;
	QWidget *fill1, *fill2, *fill3, *fill4;
	QPushButton *back, *sClose;
	QSlider *difficult;
	QSpinBox *diff;
	QLabel *diffText;
	QRadioButton *silence;
public:
	setupWidget(QWidget*parent=0);
public slots:
	void sendclose();
	void sendstop(bool);
};
#endif // !SETUP_H
