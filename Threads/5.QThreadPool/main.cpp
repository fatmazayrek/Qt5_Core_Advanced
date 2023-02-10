#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include <QDebug>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");

    QThreadPool *pool = QThreadPool::globalInstance();

    for(int i=0; i<5; i++)
    {
        counter *c = new counter;
        c->setAutoDelete(true);

        pool->start(c);
    }

    qDebug() << "Hello world from thread" << QThread::currentThread();

    return a.exec();
}
