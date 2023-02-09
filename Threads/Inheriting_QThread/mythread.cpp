#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{

}

void MyThread::quit()
{
    ok = false;
    QThread::quit();
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
}

/* Output will be:
        Current thread with id:  MyThread(0x601e77f6b8) 0
        Current thread with id:  MyThread(0x601e77f6b8) 1
        Current thread with id:  MyThread(0x601e77f6b8) 2
        Current thread with id:  MyThread(0x601e77f6b8) 3
        Current thread with id:  MyThread(0x601e77f6b8) 4
        Timeout stopping this thread QThread(0x16b3cb51bc0)
        Finished
*/
