#ifndef EXAMPLETHREADS_H
#define EXAMPLETHREADS_H

#include <QThread>
#include <QTime>

class ExampleThreads : public QThread
{
public:
    explicit ExampleThreads(QString threadName);

    // �������������� ����� run(), � ������� �����
    // ������������� ����������� ���
    void run();
private:
    QString name;   // ��� ������
    QTime* timer;
};

#endif // EXAMPLETHREADS_H
