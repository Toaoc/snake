#include"mainwindow.h"
#include<QPalette>
#include<QPixmap>
#include<QString>
mainWidget::mainWidget(QWidget *parent) :QWidget(parent)
{
	this->resize(1100, 750);

	this->setAutoFillBackground(true);
	QPalette palette;
	QPixmap pixmap("image/fengmian.jpg");
	palette.setBrush(QPalette::Window, QBrush(pixmap));
	this->setPalette(palette);

	player = new QMediaPlayer(this);
	playlist = new QMediaPlaylist(this);
	playlist->addMedia(QUrl::fromLocalFile("Resources/play1.mp3"));
	playlist->setCurrentIndex(1);
	playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
	player->setPlaylist(playlist);
	player->play();

	mGame = new Button(this);
	mSetup = new Button(this);
	mInduce = new Button(this);
	mRank = new Button(this);
	mExit = new Button(this);

	mGame->move(900, 400);
	mGame->setText(QString::fromLocal8Bit("开始游戏"));
	mSetup->move(900, 470);
	mSetup->setText(QString::fromLocal8Bit("设置"));
	mInduce->move(900, 540);
	mInduce->setText(QString::fromLocal8Bit("操作说明"));
	mRank->move(900, 610);
	mRank->setText(QString::fromLocal8Bit("排行榜"));
	mExit->move(900, 680);
	mExit->setText(QString::fromLocal8Bit("退出"));

	connect(mGame, &QPushButton::clicked, this, &mainWidget::pressGame);
	connect(mSetup, &QPushButton::clicked, this, &mainWidget::pressSetup);
	connect(mInduce, &QPushButton::clicked, this, &mainWidget::pressInduce);
	connect(mRank, &QPushButton::clicked, this, &mainWidget::pressRank);
	connect(mExit, &QPushButton::clicked, this, &mainWidget::pressExit);
}
void mainWidget::pressGame()
{
	GameWidget *Game;
	Game = new GameWidget;
	Game->show();
	this->close();
}
void mainWidget::pressSetup()
{
	setupWidget *setup;
	setup = new setupWidget;
	setup->show();
	this->close();
	connect(setup, &setupWidget::stopMusic, player, &QMediaPlayer::pause);
	connect(setup, &setupWidget::sonclose, this, &mainWidget::show);
}
void mainWidget::pressInduce()
{
	induceWidget *induce;
	induce = new induceWidget;
	induce->show();
	this->close();
	connect(induce, &induceWidget::sonclose, this, &mainWidget::show);
}
void mainWidget::pressRank()
{
	rankWidget *rank;
	rank = new rankWidget;
	rank->show();
	this->close();
	connect(rank, &rankWidget::sonclose, this, &mainWidget::show);
}
void mainWidget::pressExit()
{
	this->close();
	emit closeAll();
}