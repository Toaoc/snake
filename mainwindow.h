#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QWidget>
#include"game.h"
#include"setup.h"
#include"induce.h"
#include"rank.h"
#include<QPushButton>
#include<QMediaPlayer>
#include<QMediaPlaylist>
class mainWidget :public QWidget
{
	Q_OBJECT
protected:
signals:
	void closeAll();
public:
	mainWidget(QWidget *parent=0);
	QPushButton *mGame;
	QPushButton *mSetup;
	QPushButton *mInduce;
	QPushButton *mRank;
	QPushButton *mExit;
	QMediaPlayer *player;
	QMediaPlaylist *playlist;
public slots:
	void musicControl(bool);
private slots:
	void pressGame();
	void pressSetup();
	void pressInduce();
	void pressRank();
	void pressExit();
};
class Button :public QPushButton
{
	Q_OBJECT
public:
	Button(QWidget *parent) :QPushButton(parent)
	{
		this->resize(100, 50);
	}
};
#endif // !MAINWINDOW_H
