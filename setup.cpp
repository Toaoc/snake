#include"setup.h"
#include<QString>
#include<QPalette>
#include<QPixmap>
#include<QObject>
setupWidget::setupWidget(QWidget *parent) :QWidget(parent)
{
	this->resize(1100, 750);
	setupOp = new QWidget(this);

	back = new QPushButton(this);
	back->setObjectName("back");
	back->setStyleSheet("QPushButton#back{border-image:url(image/back.jpg)}");
	back->setStatusTip(QString::fromLocal8Bit("·µ»Ø"));

	setupOp->setAutoFillBackground(true);
	QPalette palette;
	QPixmap pixmap("image/fengmian.jpg");
	palette.setBrush(QPalette::Window, QBrush(pixmap));
	setupOp->setPalette(palette);

	diffText = new QLabel(setupOp);
	diffText->setText(QString::fromLocal8Bit("ÄÑ¶È"));

	diff = new QSpinBox(setupOp);
	diff->setMinimum(1);
	diff->setMaximum(8);
	diff->setValue(5);
	diff->setMaximumWidth(50);
	void (QSpinBox::*valueAlter)(int) = &QSpinBox::valueChanged;

	difficult = new QSlider(setupOp);
	difficult->setOrientation(Qt::Horizontal);
	difficult->setMinimum(1);
	difficult->setMaximum(8);
	difficult->setValue(5);
	difficult->setSingleStep(1);
	difficult->setMaximumWidth(600);

	silence = new QRadioButton(setupOp);
	silence->setText(QString::fromLocal8Bit("¾²Òô"));

	fill1 = new QWidget(setupOp);
	fill2 = new QWidget(setupOp);
	fill3 = new QWidget(setupOp);
	fill4 = new QWidget(setupOp);

	setupOpLayout = new QGridLayout(setupOp);
	setupOpLayout->addWidget(fill1, 0, 0, 10, 3);
	setupOpLayout->addWidget(fill2, 0, 3, 4, 14);
	setupOpLayout->addWidget(fill3, 0, 17, 10, 3);
	setupOpLayout->addWidget(fill4, 16, 3, 4, 14);
	setupOpLayout->addWidget(diffText, 4, 3,1 ,1 );
	setupOpLayout->addWidget(diff, 4, 4, 1, 1);
	setupOpLayout->addWidget(difficult, 4, 5, 1, 12);
	setupOpLayout->addWidget(silence, 6, 3);

	setupLayout = new QGridLayout(this);
	setupLayout->addWidget(back, 0, 0, 1, 1);
	setupLayout->addWidget(setupOp, 1, 0, 9, 20);
	
	connect(silence, &QRadioButton::toggled, this, &setupWidget::sendstop);
	connect(back, &QPushButton::clicked, this, &setupWidget::sendclose);
	connect(difficult, &QSlider::valueChanged, diff, &QSpinBox::setValue);
	QObject:connect(diff, valueAlter, difficult, &QSlider::setValue);
}
void setupWidget::sendclose()
{
	emit sonclose();
	delete this;
}
void setupWidget::sendstop(bool isStop)
{
	emit stopMusic(isStop);
}