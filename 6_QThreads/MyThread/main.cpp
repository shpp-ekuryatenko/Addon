#include <QCoreApplication>
#include "examplethreads.h"
#include <QTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ExampleThreads threadA("thread A");
    ExampleThreads threadB("thread B");
    ExampleThreads threadC("thread C");



    threadA.start();    // ��������� ������
    threadB.start();    // � ��������� �� ������������ ������
    threadC.start();    // � ������ qDebug

    QTime timer;

    timer.start();
    for (int i = 0; i <= 100; i++ ) {
        QDateTime thisTime = QDateTime::currentDateTime();
        qDebug() << "MAIN" << i << " after:" << timer.elapsed();
    }

    return a.exec();
}
