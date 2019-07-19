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
public:
	gameWidget(QWidget *parent = 0);
public slots:
	void sendclose();
signals:
	void sonclose();
	
};
#endif // !GAME_H
