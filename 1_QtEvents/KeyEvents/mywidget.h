#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QApplication>

class MyWidget : public QWidget
{
  Q_OBJECT
  public:
      explicit MyWidget(QWidget *parent = 0);
      ~MyWidget() {}

  protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYWIDGET_H
