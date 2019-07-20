#pragma once
#ifndef GAME_H
#define GAME_H
#include<QWidget>
#include<QGraphicsView>
#include<QButtonGroup>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QPalette>
#include<QPixmap>
#include<QGridLayout>
class gameWidget :public QWidget
{
	Q_OBJECT
protected:
	QGridLayout *mainLayout, *controlLayout;
	QGraphicsView *snakeView;
	QWidget *controlView;
	QLabel *scoreLabel;
	QLabel *diffLabel;
	QButtonGroup *controlButton;
	QPushButton *controlLeft;
	QPushButton *controlRight;
	QPushButton *controlUp;
	QPushButton *controlDown;
	QPushButton *controlBack;
	QPushButton *controlExit;
	QLineEdit *scoreView;
	QLineEdit *diffView;
	QWidget *fill1;
	QWidget *fill2;
	QWidget *fill3;
	QWidget *fill4;
public:
	gameWidget(QWidget *parent = 0);
public slots:
	void sendclose();
	void sendexit();
signals:
	void sonclose();
	void sonexit();
	
};
#endif // !GAME_H
