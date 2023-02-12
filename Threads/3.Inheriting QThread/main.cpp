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

/* Output will be: 
        Current thread with id:  MyThread(0xcfae33f698) 0
        Current thread with id:  MyThread(0xcfae33f698) 1
        Current thread with id:  MyThread(0xcfae33f698) 2
        Current thread with id:  MyThread(0xcfae33f698) 3
        Current thread with id:  MyThread(0xcfae33f698) 4
        Timeout stopping this thread QThread(0x2c7e8670170)
        Finished
        YES!!, i finished
*/
