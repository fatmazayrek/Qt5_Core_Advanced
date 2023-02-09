#include "counter.h"

counter::counter(QObject *parent)
    : QObject{parent}
{

}

void counter::start()
{
    for(int i=0; i<10; i++)
    {
        qDebug() << QThread::currentThread()->objectName() << ": " << i;

        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(500));

        QThread::currentThread()->msleep(value);
    }

    QThread::currentThread()->quit();
}
