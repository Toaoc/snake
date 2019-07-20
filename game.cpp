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

	controlView->setFixedWidth(300);
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

	connect(controlBack, &QPushButton::clicked, this, &gameWidget::sendclose);
	connect(controlExit, &QPushButton::clicked, this, &gameWidget::sendexit);
	
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