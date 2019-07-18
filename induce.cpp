#include"induce.h"
induceWidget::induceWidget(QWidget *parent) :QMainWindow(parent)
{
	this->resize(1100, 750);

	back = new QPushButton(this);
	back->setObjectName("back");
	back->setStyleSheet("QPushButton#back{border-image:url(image/back.jpg)}");
	back->setStatusTip(QString::fromLocal8Bit("����"));

	toolbar = QMainWindow::addToolBar(QString::fromLocal8Bit("������"));
	toolbar->addWidget(back);

	textBox = new QTextEdit(this);
	this->setCentralWidget(textBox);
	QString str = QString::fromLocal8Bit("����˵��");
	textBox->setPlainText(str);
	textBox->setReadOnly(1);

	connect(back, &QPushButton::clicked, this, &induceWidget::sendclose);
}
void induceWidget::sendclose()
{
	emit sonclose();
	delete this;
}