#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_snake.h"

class snake : public QMainWindow
{
	Q_OBJECT

public:
	snake(QWidget *parent = Q_NULLPTR);

private:
	Ui::snakeClass ui;
};
