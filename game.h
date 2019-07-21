#pragma once
#ifndef GAME_H
#define GAME_H
#include<QObject>
#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QStyleOption>
#include<QButtonGroup>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QPainter>
#include<QPalette>
#include<QPixmap>
#include<QGridLayout>
#include<QRect>
#include<QKeyEvent>
#include<QDebug>
class SnakeHead :public QGraphicsItem
{
	//Q_OBJECT
protected:
	void keyPressEvent(QKeyEvent *envent);
public:
	SnakeHead();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
class gameWidget :public QWidget
{
	Q_OBJECT
protected:
	QGridLayout *mainLayout, *controlLayout;
	QGraphicsScene *snakeScene;
	QGraphicsView *snakeView;
	QPainter *paintSnake;
	SnakeHead *snakeHead;
	QGraphicsItem  *snakeBody, *snaketail;
	QGraphicsItem *food, *wall;
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
	void keyPressEvent(QKeyEvent  *event);
	gameWidget(QWidget *parent = 0);
public slots:
	void senddirection(int direction);
	void sendclose();
	void sendexit();
signals:
	void keydiretion(int direction);
	void sonclose();
	void sonexit();
	
};
#endif // !GAME_H
