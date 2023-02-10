#include "counter.h"

void counter::run()
{
    qDebug() << "Starting...." << QThread::currentThread();

    for(int i=0; i<10; i++)
    {
        qDebug() << QThread::currentThread() << ": " << i;

        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(100));

        QThread::currentThread()->msleep(value);
    }

    qDebug() << "Finished.." << QThread::currentThread();
}
