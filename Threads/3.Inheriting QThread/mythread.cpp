#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{
    //Let's make some implementations:)
//    connect(this, &QThread::finished, this, &MyThread::finished);
    connect(this, &MyThread::finished2, this, &MyThread::finished);

}

void MyThread::quit()
{
    ok = false;
    QThread::quit();
}

void MyThread::finished()
{
    qDebug() << "YES!!, i finished";
}

void MyThread::run()
{
    ok = true;

    for(int i=0; i<1000; i++)
    {
        qDebug() << "Current thread with id: " << QThread::currentThread() << i;

//        this->sleep(1);
        QThread::sleep(1);

        if(!ok)
        {
            break;
        }
    }

    qDebug() << "Finished";

    exec();

    emit finished2();
}
