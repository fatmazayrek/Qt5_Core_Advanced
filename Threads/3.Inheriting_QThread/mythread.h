#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

signals:
    void finished2();

public slots:
    void quit();
    void finished();

protected:
    void run();

private:
    bool ok;
};

#endif
