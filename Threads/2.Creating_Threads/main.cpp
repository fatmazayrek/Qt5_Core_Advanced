#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include "test.h"

static QSharedPointer<QThread> sptr;

void timeout()
{
    if(!sptr.isNull())
    {
        qDebug() << "Time out! Stopped thread is: " << QThread::currentThread();
        sptr.data()->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test t;

    qDebug() << "Current Thread: " << QThread::currentThread();

    QThread thread;

    // t'yi işaret edecek şekilde bu QSharedPointer nesnesini sıfırlar
    sptr.reset(&thread);

    t.moveToThread(&thread);

    t.start();
    thread.start();

    QTimer timer;
    timer.singleShot(5000, &timeout);

    return a.exec();
}

/* Output will be:
        Current Thread:  QThread(0x2282e220fc0)
        "Çar Şub 8 22:39:13 2023" QThread(0x398f8ffc18)
        "Çar Şub 8 22:39:14 2023" QThread(0x398f8ffc18)
        "Çar Şub 8 22:39:15 2023" QThread(0x398f8ffc18)
        "Çar Şub 8 22:39:16 2023" QThread(0x398f8ffc18)
        Time out! Stopped thread is:  QThread(0x2282e220fc0)
*/
