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
#include<QTimer>
#include<QMessageBox>
#include<QList>
#include<QVector>
#include<QEvent>
class SnakeHead :public QObject, public QGraphicsItem
{
	Q_OBJECT
protected:
public:
	SnakeHead();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void collisionHandle();
	void advance(int derection);
	void reMove();
public slots:
	void keyPressEvent(QKeyEvent *envent);
signals:
	void snakeDied();
	void eatFood();
	void eatBigFood(double);
	void snakeTurn(int direction);
	void headMove();
	void bigFoodTimeUp();
};


class Food :public QGraphicsItem
{
protected:
	int foodScore;
public:
	enum{Type=65537};
	int type()const { return Type; }
	Food(qreal x, qreal y);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
class BigFood :public QGraphicsItem
{
protected:
	int foodScore;
public:
	enum { Type = 65538 };
	int type()const { return Type; }
	BigFood(qreal x, qreal y);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	int getFoodScore() { return foodScore; }
};


class SnakeBody :public QObject,public QGraphicsItem
{
	Q_OBJECT
protected:
	QPainterPath shape()const;
public:
	SnakeBody(QWidget *parent):QObject(parent){}
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


class SnakeTail :public QGraphicsItem
{

};

class Wall :public QGraphicsItem
{
public:
	Wall(qreal x, qreal y);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Wall(Wall&w);
};



class GamePlay:public QWidget
{
	Q_OBJECT
private:
	QGraphicsView *snakeView;
	QGraphicsScene *snakeScene;
	SnakeHead *snakeHead;
	SnakeBody *snakeBody;
	SnakeTail *snakeTail;
	Food *food;
	BigFood *bigFood;
	Wall *wallList[10];
	QTimer *addWallTime;
	QTimer *deleteWallTime;
	int refreshTime;
	int direction;
	int foodCount;
	QVector<SnakeBody*> snakeBodyList;
public:
	GamePlay(QGraphicsView *snakeView, QGraphicsScene *snakeScene,QWidget *parent=0);
	void timerEvent(QTimerEvent *event);
signals:
	void keepMove(int direction);
	void gameOver();
	void scoreChanged();
	void screenKeyValue(QKeyEvent *event);
public slots:
	void setFood();
	void sendOver();
	void setWall();
	void destroyWall();
	void setDirection(int m_direction);
	void addBody();
	void bodyMove();
	void screenControl(int);
	void bigFoodHandle(double);
	void deleteBigFood();
	
};


class gameWidget :public QWidget
{
	Q_OBJECT
protected:
	QGridLayout *mainLayout, *controlLayout;
	QGraphicsScene *snakeScene;
	QGraphicsView *snakeView;
	QPainter *paintSnake;
	GamePlay *gamePlay;
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
	QTimer *timeUp;
	QDialog *gameEndBox;
	QLineEdit *enterName;
	QPushButton *diaLogClose;
public:
	void keyPressEvent(QKeyEvent  *event);
	gameWidget(int gameDifficulty, QWidget *parent = 0);
public slots:
	void senddirection(int direction);
	void sendclose();
	void sendexit();
	void snakeOver();
	void addScore();
	void saveHistory();
signals:
	void keydiretion(int direction);
	void sonclose();
	void sonexit();
	
};
#endif // !GAME_H
