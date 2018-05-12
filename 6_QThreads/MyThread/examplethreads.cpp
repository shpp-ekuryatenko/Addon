#include "examplethreads.h"
#include <QDebug>
#include <QTime>


ExampleThreads::ExampleThreads(QString threadName) :
    name(threadName)
{
  timer = new QTime();
}

void ExampleThreads::run()
{

    timer->start();
    for (int i = 0; i <= 100; i++ ) {
        QDateTime thisTime = QDateTime::currentDateTime();
        qDebug() << name << " " << i << " after:" << timer->elapsed();
    }
}
