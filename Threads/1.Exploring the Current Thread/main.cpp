#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "App Thread:" << a.thread();
    qDebug() << "Current Thread: " << QThread::currentThread();
    qDebug() << "Running: " << QThread::currentThread()->isRunning();
    qDebug() << "Finished: " << QThread::currentThread()->isFinished();
    qDebug() << "Before: " << QDateTime::currentDateTime();

    QThread::sleep(10);

    qDebug() << "After: " << QDateTime::currentDateTime();

    return a.exec();
}

/* Output will be:
        App Thread: QThread(0x270f51801f0)
        Current Thread:  QThread(0x270f51801f0)
        Running:  true
        Finished:  false
        Before:  QDateTime(2023-02-08 18:24:52.009 Türkiye Standart Saati Qt::LocalTime)
        After:  QDateTime(2023-02-08 18:25:02.012 Türkiye Standart Saati Qt::LocalTime)
*/
