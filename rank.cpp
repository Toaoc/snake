#include"rank.h"
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

	file = new QFile("Resources/rank.txt",textBox);
	if (!(file->open(QIODevice::ReadOnly | QIODevice::Text)))
	{
		QMessageBox::warning(this,tr("Read File"), tr("Cannot open file Resources/rank.txt"));
		sendclose();
	}
	in = new QTextStream(file);
	textBox->append(in->readAll());
	file->close();
	textBox->setReadOnly(1);

	connect(back, &QPushButton::clicked, this, &rankWidget::sendclose);
}
void rankWidget::sendclose()
{
	emit sonclose();
	delete this;
}