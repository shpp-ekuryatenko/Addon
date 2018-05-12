#include "mywidget.h"
#include <QWidget>
#include <iostream>
#include <QApplication>

MyWidget::MyWidget(QObject *parent) :
    QObject(parent)
{
    startTimer(1000);
}

void MyWidget::timerEvent(QTimerEvent *event)
{
     std::cout << event->timerId() <<  std::endl;
}
