#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{

}

void Test::start()
{
    connect(&timer, &QTimer::timeout, this, &Test::timeout);
    timer.setInterval(1000);
    timer.start();
}

void Test::timeout()
{
    qDebug() << QDateTime::currentDateTime().toString() << QThread::currentThread();
}
