#pragma once
#ifndef RANK_H
#define RANK_H
#include<QMainWindow>
#include<QPushButton>
#include<QString>
#include<QTextEdit>
#include<QToolBar>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>

class Node
{
public:
	std::string playTime, player;
	long score;
	Node *next, *prev;
};
class linkList
{
public:
	linkList();
	~linkList();
	Node* getHead() { return head->next; }
	void linkSort();
	void linkAdd(std::string m_player, long m_score, std::string m_playtime);
	bool isEmpty();
private:
	Node *head, *tail;
	int length;
};
class rankWidget :public QMainWindow
{
	Q_OBJECT
signals:
	void sonclose();
private:
	QPushButton *back;
	QTextEdit *textBox;
	QToolBar *toolbar;
	QMessageBox *errorOpen;
public:
	rankWidget(QWidget *parent = 0);
public slots:
	void sendclose();
};
#endif // !RANK_H
