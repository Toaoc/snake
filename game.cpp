#include"game.h"
#include<QString>
#include<QCoreApplication>
QVector<QPointF> snakePosition;
int snakeLength;
int addWall = 0;
int totalWall = 0;
int deleteWall = 0;
int perScore = 5;
int totalScore = 0;
void addPosition(QPointF point)
{
	snakePosition.push_back(point);
	if (snakePosition.size() > snakeLength)
		snakePosition.erase(snakePosition.begin());
}
SnakeHead::SnakeHead()
{
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemIsMovable);
}
QRectF SnakeHead::boundingRect()const
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void SnakeHead::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::green);
	painter->drawRect(0, 0, 20, 20);
}
void SnakeHead::keyPressEvent(QKeyEvent *event)
{
	qDebug() << "Button: " << event->key();
	switch (event->key())
	{
	case 16777235:
	case 87:this->moveBy(0, -21); addPosition(this->scenePos()); emit snakeTurn(1); emit headMove(); break;//向上移动
	case 16777237:
	case 83:this->moveBy(0, 21); addPosition(this->scenePos()); emit snakeTurn(2); emit headMove(); break;//向下移动
	case 16777234:
	case 65:this->moveBy(-21, 0); addPosition(this->scenePos()); emit snakeTurn(3); emit headMove(); break;//向左移动
	case 16777236:
	case 68:this->moveBy(21, 0);  addPosition(this->scenePos()); emit snakeTurn(4); emit headMove(); break;//向右移动
	default:
		break;
	}
}
void SnakeHead::reMove()//检测是否到边界,到边界则从另一边出来
{
	qreal x1 = 0, x2 = 790, y1 = 0, y2 = 740;
	if (this->scenePos().x() < x1)
		this->setPos(x2, this->scenePos().y());
	else if (this->scenePos().x() > x2)
		this->setPos(x1, this->scenePos().y());
	else if(this->scenePos().y() < y1)
		this->setPos(this->scenePos().x(),y2);
	else if(this->scenePos().y() > y2)
		this->setPos(this->scenePos().x(), y1);
}
void SnakeHead::advance(int direction)
{
	switch (direction)
	{
	case 0:this->clearFocus(); break;//取消焦点
	case 1:moveBy(0, -21); emit headMove(); break;
	case 2:moveBy(0, 21); emit headMove(); break;
	case 3:moveBy(-21, 0); emit headMove(); break;
	case 4:moveBy(21, 0); emit headMove(); break;
	default:
		break;
	}
	//qDebug() << this->scenePos().x() << "," << this->scenePos().y();
	if(direction!=0)
		collisionHandle();//处理碰撞
	reMove();//检测是否到边界
}
void SnakeHead::collisionHandle()
{
	QList<QGraphicsItem*> items = collidingItems();
	foreach(QGraphicsItem *item, items)
	{
		if (item->type() == 65537)
		{
			emit eatFood();
			totalScore += perScore;
		}
		else
		{
			snakeTurn(0);
			emit snakeDied();
		}
	}
}



QRectF SnakeBody::boundingRect()const
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void SnakeBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::blue);
	painter->drawRect(0, 0, 20, 20);
}
QPainterPath SnakeBody::shape()const
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(QRectF(0, 0, 20, 20));
	return path;
}

Food::Food(qreal m_x, qreal m_y)
{
	this->setPos(m_x, m_y);
}
QRectF Food::boundingRect()const
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::yellow);
	painter->drawRect(0, 0, 20, 20);
}


QRectF Wall::boundingRect()const
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::red);
	painter->drawRect(0, 0, 20, 20);
}
Wall::Wall(qreal x, qreal y)
{
	this->setPos(x, y);
}
Wall::Wall(Wall&w)
{
	
}


void gameWidget::keyPressEvent(QKeyEvent *event)
{
	senddirection(event->key());
	qDebug() << event->key() << "hello";
}
gameWidget::gameWidget(QWidget*parent) :QWidget(parent)
{
	this->resize(1100, 750);
	mainLayout = new QGridLayout(this);
	snakeScene = new QGraphicsScene(this);
	snakeView = new QGraphicsView(snakeScene,this);
	controlView = new QWidget(this);
	snakeScene->setSceneRect(snakeView->rect());
	mainLayout->addWidget(snakeView, 0, 0, 1, 15);
	mainLayout->addWidget(controlView, 0, 15, 1, 7);

	totalScore = 0;
	snakeLength = 1;
	snakePosition.clear();
	addWall = 0;
	totalWall = 0;
	deleteWall = 0;

	controlButton = new QButtonGroup(controlView);
	controlUp = new QPushButton(controlView);
	controlDown = new QPushButton(controlView);
	controlLeft = new QPushButton(controlView);
	controlRight = new QPushButton(controlView);
	controlButton->addButton(controlUp, 87);
	controlButton->addButton(controlDown, 83);
	controlButton->addButton(controlLeft, 65);
	controlButton->addButton(controlRight, 68);

	controlUp->setObjectName("up");
	controlDown->setObjectName("down");
	controlLeft->setObjectName("left");
	controlRight->setObjectName("right");
	controlUp->setFixedSize(60, 60);
	controlDown->setFixedSize(60, 60);
	controlLeft->setFixedSize(60, 60);
	controlRight->setFixedSize(60, 60);
	controlUp->setStyleSheet("QPushButton#up{border-image:url(image/up.jpg)}");
	controlDown->setStyleSheet("QPushButton#down{border-image:url(image/down.jpg)}");
	controlLeft->setStyleSheet("QPushButton#left{border-image:url(image/left.jpg)}");
	controlRight->setStyleSheet("QPushButton#right{border-image:url(image/right.jpg)}");

	controlBack = new QPushButton(controlView);
	controlBack->setFixedSize(100, 50);
	controlBack->setText(QString::fromLocal8Bit("返回"));

	controlExit = new QPushButton(controlView);
	controlExit->setFixedSize(100, 50);
	controlExit->setText(QString::fromLocal8Bit("退出"));

	scoreLabel = new QLabel(controlView);
	diffLabel = new QLabel(controlView);
	scoreLabel->setText(QString::fromLocal8Bit("得分"));
	diffLabel->setText(QString::fromLocal8Bit("难度"));
	scoreView = new QLineEdit(controlView);
	diffView = new QLineEdit(controlView);

	diffView->setText(QString::number(perScore));
	scoreView->setText(QString::number(totalScore));
	diffView->setReadOnly(1);
	scoreView->setReadOnly(1);

	controlView->setFixedWidth(300);
	snakeView->setMinimumHeight(750);
	snakeView->setMinimumWidth(this->width() - 300);
	snakeScene->setSceneRect(0, 0, snakeView->width()-10, snakeView->height()-10);
	mainLayout->addWidget(snakeView, 0, 0);
	mainLayout->addWidget(controlView, 0, 75 );
	controlLayout = new QGridLayout(controlView);
	fill1 = new QWidget(controlView);
	fill2 = new QWidget(controlView);
	fill3 = new QWidget(controlView);
	fill4 = new QWidget(controlView);
	controlLayout->addWidget(fill1, 0, 0, 5, 30);
	controlLayout->addWidget(fill2, 70, 0, 5, 30);
	controlLayout->addWidget(controlUp, 5, 13, 6, 6);
	controlLayout->addWidget(controlLeft, 13, 5, 6, 6);
	controlLayout->addWidget(controlRight, 13, 20, 6, 6);
	controlLayout->addWidget(controlDown, 21, 13, 6, 6);
	controlLayout->addWidget(scoreLabel, 36, 10, 8, 5);
	controlLayout->addWidget(scoreView, 36, 15, 8, 10);
	controlLayout->addWidget(diffLabel, 45, 10, 8, 5);
	controlLayout->addWidget(diffView, 45, 15, 8, 10);
	controlLayout->addWidget(controlBack, 57, 12, 5, 10);
	controlLayout->addWidget(controlExit, 65, 12, 5, 10);

	gamePlay = new GamePlay(snakeView, snakeScene,this);
	qDebug() << snakeView->height() << " " << snakeView->width();
	qDebug() << snakeScene->height() << " " << snakeScene->width();

	void(QButtonGroup::*whichButton)(int) = &QButtonGroup::buttonClicked;
	connect(controlButton, whichButton, gamePlay, &GamePlay::screenControl);
	connect(controlBack, &QPushButton::clicked, this, &gameWidget::sendclose);
	connect(controlExit, &QPushButton::clicked, this, &gameWidget::sendexit);
	connect(gamePlay, &GamePlay::gameOver, this, &gameWidget::snakeOver);
	connect(gamePlay, &GamePlay::scoreChanged, this, &gameWidget::addScore);
}
void GamePlay::screenControl(int screenKey)//模拟上下左右的键盘输入
{
	qDebug() << "屏幕按键：" << screenKey;
	QKeyEvent keyEvent(QEvent::KeyPress, screenKey, Qt::NoModifier);
	QCoreApplication::sendEvent(snakeHead, &keyEvent);
}
void gameWidget::addScore()
{
	scoreView->setText(QString::number(totalScore));
}
void gameWidget::sendclose()
{
	emit sonclose();
	delete this;
}
void gameWidget::sendexit()
{
	emit sonexit();
	delete this;
}
void  gameWidget::senddirection(int direction)
{
	emit keydiretion(direction);
}
void gameWidget::snakeOver()//游戏结束处理函数
{
	gameEndBox = new QMessageBox;
	gameEndBox->setText(QString::fromLocal8Bit("得分：").append(QString::number(totalScore)).append("\n").append(QString::fromLocal8Bit("你真棒")));
	gameEndBox->addButton(QString::fromLocal8Bit("确定"), QMessageBox::RejectRole);
	gameEndBox->addButton(QString::fromLocal8Bit("取消"), QMessageBox::AcceptRole);
	gameEndBox->show();
}


GamePlay::GamePlay(QGraphicsView *m_snakeView, QGraphicsScene *m_snakeScene,QWidget *parent):QWidget(parent)
{
	snakeBodyList.clear();
	snakeView = m_snakeView;
	snakeScene = m_snakeScene;
	snakeHead = new SnakeHead;
	food = new Food(100, 100);
	snakeLength = 1;

	snakeBody = new SnakeBody(this);
	snakeScene->addItem(snakeBody);
	snakeBodyList.push_back(snakeBody);
	snakeBody->setPos(280, 300);

	snakeScene->addItem(food);
	snakeScene->addItem(snakeHead);
	snakeHead->setPos(300, 300);
	snakePosition.push_back(snakeBody->scenePos());
	snakeView->show();
	snakeView->setEnabled(1);
	snakeHead->setFocus();
	snakeScene->setFocusItem(snakeHead);
	setWall();
	setWall();
	direction = 4;

	if(direction!=0)
		this->startTimer(100);

	connect(snakeHead, &SnakeHead::snakeTurn, this, &GamePlay::setDirection);
	connect(this, &GamePlay::keepMove, snakeHead, &SnakeHead::advance);
	connect(snakeHead, &SnakeHead::eatFood, this, &GamePlay::setFood);
	connect(snakeHead, &SnakeHead::snakeDied, this, &GamePlay::sendOver);
	connect(snakeHead, &SnakeHead::snakeTurn, this, &GamePlay::setWall);
	connect(snakeHead, &SnakeHead::headMove, this, &GamePlay::bodyMove);
	connect(snakeHead, &SnakeHead::eatFood, this, &GamePlay::addBody);

	/*addWallTime = new QTimer;
	thread = new QThread;
	addWallTime->moveToThread(thread);
	connect(addWallTime, &QTimer::timeout, this, &GamePlay::setWall);
	addWallTime->start(1000);*/
}
void GamePlay::addBody()
{
	emit scoreChanged();
	snakeLength++;
	qDebug() << "snakeLength:" << snakeLength;
	SnakeBody *newBody;
	newBody = new SnakeBody(this);
	snakeScene->addItem(newBody);
	newBody->setPos(*snakePosition.begin());
	snakeBodyList.push_back(newBody);
}
void GamePlay::bodyMove()
{
	for (int i = 0; i < snakeLength; i++)
	{
		QPointF tem = snakePosition[i];
		(snakeBodyList[i])->setPos(tem);
	}
}
void GamePlay::setDirection(int m_direction)
{
	this->direction = m_direction;
}
void GamePlay::timerEvent(QTimerEvent *event)
{
	emit keepMove(this->direction);
	snakePosition.push_back(snakeHead->scenePos());
	if (snakePosition.size() > snakeLength)
		snakePosition.erase(snakePosition.begin());
}
void GamePlay::setFood()
{
	qreal x, y;
	if (snakeView->width() < 810)
	{
		x = qrand() % (snakeView->width() - 10);
		y = qrand() % (snakeView->height() - 10);
	}
	else
	{
		snakeScene->setSceneRect(0, 0, snakeView->width() - 10, snakeView->height() - 10);
		qDebug() << "screen-width: " << snakeView->width();
		qDebug() << "scene-width: " << snakeScene->width();
		x = qrand() % (snakeView->width() - 100);
		y = qrand() % (snakeView->height() - 100);
	}
	delete food;
	qDebug() << "x: " << x << "  y:" << y;
	food = new Food(x, y);
	snakeScene->addItem(food);
	destroyWall();
}
void GamePlay::setWall()
{
	if (totalWall!=10)
	{
		qreal x, y;
		if (snakeView->width() < 810)
		{
			x = qrand() % (snakeView->width() - 10);
			y = qrand() % (snakeView->height() - 10);
		}
		else
		{
			snakeScene->setSceneRect(0, 0, snakeView->width() - 10, snakeView->height() - 10);
			qDebug() << "screen-width: " << snakeView->width();
			qDebug() << "scene-width: " << snakeScene->width();
			x = qrand() % (snakeView->width() - 100);
			y = qrand() % (snakeView->height() - 100);
		}
		if (addWall == 10)
			addWall = 0;
		wallList[addWall] = new Wall(x, y);
		snakeScene->addItem(wallList[addWall]);
		qDebug() << "addWall: " << addWall;
		qDebug() << "totalWall: " << totalWall;
		addWall++;
		totalWall++;
	}
}
void GamePlay::destroyWall()
{
	qDebug() << "deleteWall: " << deleteWall;
	if (totalWall != 0)
	{
		if (deleteWall == 9)
		{
			delete wallList[deleteWall];
			deleteWall = 0;
		}
		else
		{
			delete wallList[deleteWall];
			deleteWall++;
		}
		totalWall--;
	}
}
void GamePlay::sendOver()
{
	emit gameOver();
}