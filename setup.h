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
	void changeDifficulty(int);
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
	setupWidget(int gameDifficulty,QWidget*parent=0);
public slots:
	void sendclose();
	void sendstop(bool);
	void sendDifficultyChange(int);
};
#endif // !SETUP_H
