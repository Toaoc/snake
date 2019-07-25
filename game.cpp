#include"game.h"
#include<QString>
#include<QCoreApplication>
#include<QDateTime>
#include<QTextStream>
#include<QFile>
#include<QIODevice>
QVector<QPointF> snakePosition;
int snakeLength;
int addWall = 0;
int totalWall = 0;
int deleteWall = 0;
int perScore = 5;
int totalScore = 0;
int difficultLevel = 5;
long start, end;
bool bigFoodIsSet;
void addPosition(QPointF point)//��̬������ͷǰ�߳���λ�õĺ���
{
	snakePosition.push_back(point);
	if (snakePosition.size() > snakeLength)
		snakePosition.erase(snakePosition.begin());
}
SnakeHead::SnakeHead()//��ͷ�Ĺ��캯��
{
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemIsMovable);
}
QRectF SnakeHead::boundingRect()const//��ͷ�����κ���
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void SnakeHead::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//������ͷ�ĺ���
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::green);
	painter->drawRect(0, 0, 20, 20);
}
void SnakeHead::keyPressEvent(QKeyEvent *event)//��ͷ������ƶ��ĺ���
{
	qDebug() << "Button: " << event->key();
	switch (event->key())
	{
	case 16777235:
	case 87:this->moveBy(0, -21); addPosition(this->scenePos()); emit snakeTurn(1); emit headMove(); break;//�����ƶ�
	case 16777237:
	case 83:this->moveBy(0, 21); addPosition(this->scenePos()); emit snakeTurn(2); emit headMove(); break;//�����ƶ�
	case 16777234:
	case 65:this->moveBy(-21, 0); addPosition(this->scenePos()); emit snakeTurn(3); emit headMove(); break;//�����ƶ�
	case 16777236:
	case 68:this->moveBy(21, 0);  addPosition(this->scenePos()); emit snakeTurn(4); emit headMove(); break;//�����ƶ�
	default:
		break;
	}
}
void SnakeHead::reMove()//����Ƿ񵽱߽�,���߽������һ�߳���
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
void SnakeHead::advance(int direction)//ʹ�߲�ͣ�ƶ��ĺ���
{
	switch (direction)
	{
	case 0:this->clearFocus(); break;//ȡ������
	case 1:moveBy(0, -21); emit headMove(); break;
	case 2:moveBy(0, 21); emit headMove(); break;
	case 3:moveBy(-21, 0); emit headMove(); break;
	case 4:moveBy(21, 0); emit headMove(); break;
	default:
		break;
	}
	//qDebug() << this->scenePos().x() << "," << this->scenePos().y();
	if(direction!=0)
		collisionHandle();//������ײ
	if (bigFoodIsSet)
	{
		start += 500 / difficultLevel;
		if (start > (35000 / difficultLevel))
		{
			emit bigFoodTimeUp();
		}
	}
	reMove();//����Ƿ񵽱߽�
}
void SnakeHead::collisionHandle()//������ͷ��������Ʒ��ײ�ĺ���
{
	QList<QGraphicsItem*> items = collidingItems();
	foreach(QGraphicsItem *item, items)
	{
		if (item->type() == 65537)
		{
			totalScore += difficultLevel;
			emit eatFood();
		}
		else if(item->type()==65538)
		{
			emit eatBigFood(start);
		}
		else
		{
			snakeTurn(0);
			emit snakeDied();
		}
	}
}



QRectF SnakeBody::boundingRect()const//ÿ������������εĺ���
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void SnakeBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//����ÿ��������ĺ���
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::blue);
	painter->drawRect(0, 0, 20, 20);
}
QPainterPath SnakeBody::shape()const//�����εĺ�������ʱû����
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(QRectF(0, 0, 20, 20));
	return path;
}

Food::Food(qreal m_x, qreal m_y)//ʳ��Ĺ��캯��
{
	this->setPos(m_x, m_y);
	foodScore = difficultLevel;
}
QRectF Food::boundingRect()const//��������δ�С
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//����ʳ��ĺ���
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::yellow);
	painter->drawRect(0, 0, 20, 20);
}
BigFood::BigFood(qreal x, qreal y)
{
	this->setPos(x, y);
	foodScore = difficultLevel * 64;
}
QRectF BigFood::boundingRect()const//ʳ������δ�С
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 35 + penWidth, 35 + penWidth);
}
void BigFood::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//����ʳ��ĺ���
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::yellow);
	painter->drawRect(0, 0, 35, 35);
}


QRectF Wall::boundingRect()const//ǽ�����κ���
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}
void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//����ǽ�ĺ���
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::red);
	painter->drawRect(0, 0, 20, 20);
}
Wall::Wall(qreal x, qreal y)//ǽ�Ĺ��캯��
{
	this->setPos(x, y);
}


void gameWidget::keyPressEvent(QKeyEvent *event)
{
	senddirection(event->key());
	qDebug() << event->key() << "hello";
}

gameWidget::gameWidget(QWidget*parent) :QWidget(parent)//�����ں���
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
	bigFoodIsSet = false;
	start = 0;

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
	controlBack->setText(QString::fromLocal8Bit("����"));

	controlExit = new QPushButton(controlView);
	controlExit->setFixedSize(100, 50);
	controlExit->setText(QString::fromLocal8Bit("�˳�"));

	scoreLabel = new QLabel(controlView);
	diffLabel = new QLabel(controlView);
	scoreLabel->setText(QString::fromLocal8Bit("�÷�"));
	diffLabel->setText(QString::fromLocal8Bit("�Ѷ�"));
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

void gameWidget::saveHistory()//����Ϸ���ݴ���
{
	gameEndBox->close();
	QString playerName, playerScore, playTime;
	playerName = enterName->text();
	qDebug() << "platerLength:" << playerName.size();
	if (playerName.size() == 0)
		playerName = "Toao";
	playerScore = QString::number(totalScore);
	QDateTime currentTime = QDateTime::currentDateTime();
	playTime = currentTime.toString("yyyy.MM.dd-hh:mm");
	QFile file("Resources/rank.txt");
	if (!file.open(QIODevice::Append | QIODevice::Text))
	{
		QMessageBox::critical(NULL, "��ʾ", "�޷������ļ�");
		return ;
	}
	QTextStream out(&file);
	out << playerName << "\t\t" << playerScore << "\t\t" << playTime << "\n" << flush;
	file.close();
}
void GamePlay::screenControl(int screenKey)//ģ���������ҵļ�������
{
	qDebug() << "��Ļ������" << screenKey;
	QKeyEvent keyPressEvent(QEvent::KeyPress, screenKey, Qt::NoModifier);
	//QCoreApplication::sendEvent(snakeHead, &keyPressEvent);
	emit screenKeyValue(&keyPressEvent);

}
void gameWidget::addScore()//��������ʾ��������
{
	scoreView->setText(QString::number(totalScore));
}
void gameWidget::sendclose()//���͹رոô��ڵ��źţ���������һ��
{
	emit sonclose();
	delete this;
}
void gameWidget::sendexit()//�����˳����ź�
{
	emit sonexit();
	delete this;
}
void  gameWidget::senddirection(int direction)
{
	emit keydiretion(direction);
}
void gameWidget::snakeOver()//��Ϸ����������
{
	gameEndBox = new QDialog(this);
	gameEndBox->resize(500, 300);

	QLabel *message;
	message = new QLabel(gameEndBox);
	message->setText(QString::fromLocal8Bit("�÷֣�").append(QString::number(totalScore)).append("\n").append(QString::fromLocal8Bit("�����")));
	message->move(200, 80);

	QLabel *player;
	player = new QLabel(gameEndBox);
	player->setText(QString::fromLocal8Bit("��Ϸ��"));
	player->move(100, 150);

	enterName = new QLineEdit(gameEndBox);
	enterName->move(170, 150);
	enterName->setPlaceholderText("Toao");

	diaLogClose = new QPushButton(gameEndBox);
	diaLogClose->setText(QString::fromLocal8Bit("ȷ��"));
	diaLogClose->resize(300, 40);
	diaLogClose->move(100, 200);

	gameEndBox->show();
	connect(diaLogClose, &QPushButton::clicked, this, &gameWidget::saveHistory);
}


//��Ϸ���Ƶĺ���
GamePlay::GamePlay(QGraphicsView *m_snakeView, QGraphicsScene *m_snakeScene,QWidget *parent):QWidget(parent)
{
	snakeBodyList.clear();
	snakeView = m_snakeView;
	snakeScene = m_snakeScene;
	snakeHead = new SnakeHead;
	food = new Food(100, 100);
	foodCount = 1;
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
	snakeView->setFocusPolicy(Qt::StrongFocus);
	setWall();
	setWall();
	direction = 4;
	refreshTime = 500 / difficultLevel;

	if(direction!=0)
		this->startTimer(refreshTime);

	connect(snakeHead, &SnakeHead::snakeTurn, this, &GamePlay::setDirection);
	connect(this, &GamePlay::keepMove, snakeHead, &SnakeHead::advance);
	connect(snakeHead, &SnakeHead::eatFood, this, &GamePlay::setFood);
	connect(snakeHead, &SnakeHead::snakeDied, this, &GamePlay::sendOver);
	connect(snakeHead, &SnakeHead::snakeTurn, this, &GamePlay::setWall);
	connect(snakeHead, &SnakeHead::headMove, this, &GamePlay::bodyMove);
	connect(snakeHead, &SnakeHead::eatFood, this, &GamePlay::addBody);
	connect(this, &GamePlay::screenKeyValue, snakeHead, &SnakeHead::keyPressEvent);
	connect(snakeHead, &SnakeHead::eatBigFood, this, &GamePlay::bigFoodHandle);
	connect(snakeHead, &SnakeHead::bigFoodTimeUp, this, &GamePlay::deleteBigFood);

}

void GamePlay::addBody()//�߳�ʳ��֮������䳤�ĺ���
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
void GamePlay::bodyMove()//�������ƶ��ĺ���
{
	for (int i = 0; i < snakeLength; i++)
	{
		QPointF tem = snakePosition[i];
		(snakeBodyList[i])->setPos(tem);
	}
}
void GamePlay::setDirection(int m_direction)//�߸���ͷ�����ƶ�����ȷ��������ƶ�����
{
	this->direction = m_direction;
}
void GamePlay::timerEvent(QTimerEvent *event)//ˢ��ҳ��ĺ���
{
	emit keepMove(this->direction);
	snakePosition.push_back(snakeHead->scenePos());
	if (snakePosition.size() > snakeLength)
		snakePosition.erase(snakePosition.begin());
}
void GamePlay::setFood()//����ʳ��ĺ���
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
	foodCount++;
	if (foodCount % 5 == 0)
	{
		x = qrand() % (snakeView->width() - 10);
		y = qrand() % (snakeView->height() - 10);
		bigFood = new BigFood(x, y);
		snakeScene->addItem(bigFood);
		bigFoodIsSet = true;
		start = 0;
	}
	snakeScene->addItem(food);
	destroyWall();
}
void GamePlay::setWall()//����ǽ�ĺ���
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
void GamePlay::destroyWall()//ɾ��ǽ�ĺ���
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
void GamePlay::bigFoodHandle(double totalTime)
{
	double bigFoodScore = (double)(bigFood->getFoodScore()) * (totalTime / (50000 / difficultLevel));
	bigFoodScore -= (int)bigFoodScore % difficultLevel;
	totalScore += (int)bigFoodScore;
	delete bigFood;
	emit scoreChanged();
	bigFoodIsSet = false;

}
void GamePlay::sendOver()//�������������źŸ���ҳ��
{
	emit gameOver();
}
void GamePlay::deleteBigFood()
{
	delete bigFood;
	bigFoodIsSet = false;
}