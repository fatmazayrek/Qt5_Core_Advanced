#include "manager.h"

manager::manager(QObject *parent)
    : QObject{parent}
{
    for(int i=0; i<5; i++)
    {
        QThread *thread = new QThread(this);

        thread->setObjectName("Thread " + QString::number(i));

        qDebug() << "Created: " << thread->objectName();

        connect(thread, &QThread::started, this, &manager::started);
        connect(thread, &QThread::finished, this, &manager::finished);

        threads.append(thread);
    }
}

void manager::start()
{
    qDebug() << "Starting..";

    foreach(QThread *thread, threads)
    {
        qDebug() << "Starting: " << thread->objectName();

        counter *c = new counter(); //No parent
        c->moveToThread(thread);

        connect(thread, &QThread::started, c, &counter::start);

        thread->start();
    }
}

void manager::started()
{
    QThread *thread = reinterpret_cast<QThread*>(sender());

    if(!thread)
    {
        return;
    }
    else
    {
        qDebug() << "Started.." << thread->objectName();
    }
}

void manager::finished()
{
    QThread *thread = reinterpret_cast<QThread*>(sender());

    if(!thread)
    {
        return;
    }
    else
    {
        qDebug() << "Finished.." << thread->objectName();
    }
}
