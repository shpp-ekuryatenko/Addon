#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QApplication>

class MyWidget : public QObject
{
  Q_OBJECT
  public:
      explicit MyWidget(QObject *parent = 0);
      ~MyWidget() {}

  protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MYWIDGET_H
