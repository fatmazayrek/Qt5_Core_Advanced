#include <QCoreApplication>
#include "mythread.h"
#include <QThread>
#include <QSharedPointer>
#include <QTimer>

static QSharedPointer<MyThread> sptr;

void timeout()
{
    if(!sptr.isNull())
    {
        qDebug() << "Timeout stopping this thread" << QThread::currentThread();
        sptr.data()->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mythred;

    sptr.reset(&mythred);

    mythred.start();

    QTimer timer;

    timer.singleShot(5000, &timeout);

    return a.exec();
}
