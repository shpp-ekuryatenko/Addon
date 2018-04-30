#include "mywidget.h"
#include <QWidget>
#include <iostream>
#include <QApplication>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
     std::cout << event->text().toStdString()  <<  std::endl;
}
