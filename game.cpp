#include"game.h"
#include<QString>
gameWidget::gameWidget(QWidget*parent) :QWidget(parent)
{
	this->resize(1100, 750);
	mainLayout = new QGridLayout(this);
	snakeView = new QGraphicsView(this);
	controlView = new QWidget(this);
	mainLayout->addWidget(snakeView, 0, 0, 1, 15);
	mainLayout->addWidget(controlView, 0, 15, 1, 7);

	controlButton = new QButtonGroup(controlView);
	controlUp = new QPushButton(controlView);
	controlDown = new QPushButton(controlView);
	controlLeft = new QPushButton(controlView);
	controlRight = new QPushButton(controlView);
	controlButton->addButton(controlUp, 1);
	controlButton->addButton(controlDown, 2);
	controlButton->addButton(controlLeft, 3);
	controlButton->addButton(controlRight, 4);

	controlUp->setObjectName("up");
	controlDown->setObjectName("down");
	controlLeft->setObjectName("left");
	controlRight->setObjectName("right");
	controlUp->setFixedSize(80, 80);
	controlDown->setFixedSize(80, 80);
	controlLeft->setFixedSize(80, 80);
	controlRight->setFixedSize(80, 80);
	controlUp->setStyleSheet("QPushButton#up{border-image:Resources/up.jpg}");
	controlDown->setStyleSheet("QPushButton#down{border-image:Resources/down.jpg}");
	controlLeft->setStyleSheet("QPushButton#left{border-image:Resources/left.jpg}");
	controlUp->setStyleSheet("QPushButton#right{border-image:Resources/right.jpg}");

	controlBack = new QPushButton(controlView);
	controlBack->setFixedSize(100, 500);
	controlBack->setText(QString::fromLocal8Bit("返回"));

	controlExit = new QPushButton(controlView);
	controlExit->setFixedSize(100, 50);
	controlBack->setText(QString::fromLocal8Bit("退出"));

	scoreLabel = new QLabel(controlView);
	diffLabel = new QLabel(controlView);
	scoreLabel->setText(QString::fromLocal8Bit("得分"));
	diffLabel->setText(QString::fromLocal8Bit("难度"));
	scoreView = new QLineEdit(controlView);
	diffView = new QLineEdit(controlView);

	controlLayout = new QGridLayout(controlView);
}