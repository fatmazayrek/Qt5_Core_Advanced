#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QDebug>
#include <QRandomGenerator>

class counter : public QRunnable
{
public:
    void run();
};

#endif // COUNTER_H
