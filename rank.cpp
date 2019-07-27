#include"rank.h"
#include<fstream>
#include<iostream>
#include<string>
#include<QDebug>
rankWidget::rankWidget(QWidget *parent) :QMainWindow(parent)
{
	this->resize(1100, 750);

	back = new QPushButton(this);
	back->setObjectName("back");
	back->setStyleSheet("QPushButton#back{border-image:url(image/back.jpg)}");
	back->setStatusTip(QString::fromLocal8Bit("返回"));


	toolbar = QMainWindow::addToolBar(QString::fromLocal8Bit("工具栏"));
	toolbar->addWidget(back);


	textBox = new QTextEdit(this);
	this->setCentralWidget(textBox);
	QString str = QString::fromLocal8Bit("游戏者\t\t分数\t\t时间");
	textBox->setText(str);


	std::ifstream fin;
	fin.open("Resources/rank.txt");
	linkList inList;
	std::string m_player, m_time;
	long m_score;


	while (fin >> m_player)
	{
		fin  >> m_score >> m_time;
		qDebug() << QString::fromStdString(m_player);
		inList.linkAdd(m_player, m_score, m_time);
	}
	fin.close();
	inList.linkSort();


	for (Node *p = inList.getHead(); p->next != nullptr; p = p->next)
	{
		QString temPlayer, temTime, temScore;
		temPlayer = QString::fromStdString(p->player);
		temTime = QString::fromStdString(p->playTime);
		temScore = QString::number(p->score);
		textBox->append(temPlayer.append("\t\t").append(temScore).append("\t\t").append(temTime).append("\n"));
	}
	textBox->setReadOnly(1);

	connect(back, &QPushButton::clicked, this, &rankWidget::sendclose);
}
void rankWidget::sendclose()
{
	emit sonclose();
	delete toolbar;
	delete this;
}
linkList::linkList()
{
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
	head->prev = nullptr;
	tail->next = nullptr;
	length = 0;
}
void linkList::linkAdd(std::string m_player, long m_score, std::string m_playTime)
{
	tail->player = m_player;
	tail->score = m_score;
	tail->playTime = m_playTime;
	Node *tem =  tail;
	tail->next = new Node;
	tail = tail->next;

	tail->prev = tem;//问题所在

	tail->next = nullptr;
	length++;
}
void linkList::linkSort()
{
	if (length <= 1)
		return;
	Node *p = head->next;
	for (int i = 0; i < length-1; i++)
	{
		Node *q = p->next;
		for (int j = i + 1; j < length; j++)
		{
			if (p->score < q->score)
			{
				std::string temPlayer, temTime;
				long temScore;
				temScore = p->score;
				p->score = q->score;
				q->score = temScore;
				temPlayer = p->player;
				p->player = q->player;
				q->player = temPlayer;
				temTime = p->playTime;
				p->playTime = q->playTime;
				q->playTime = temTime;
			}
			q = q->next;
		}
		p = p->next;
	}
}
bool linkList::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}
linkList::~linkList()
{
	if (length == 0)
	{
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while (head->next != nullptr)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
}