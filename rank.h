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
class rankWidget :public QMainWindow
{
	Q_OBJECT
signals:
	void sonclose();
private:
	QPushButton *back;
	QTextEdit *textBox;
	QToolBar *toolbar;
	QFile *file;
	QMessageBox *errorOpen;
	QTextStream *in;
public:
	rankWidget(QWidget *parent = 0);
public slots:
	void sendclose();
};

class Note
{
private:
	Note *next;
public:
	QString playTime, player;
	long score;
	Note(QString m_player, long m_score, QString m_playTime, Note *next = 0);
	void insertAfter(Note *p);
	Note *deleteAfter();
	Note *nextNote();
	const Note *nextNote() const;
};
#endif // !RANK_H
