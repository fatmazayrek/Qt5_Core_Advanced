#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QRandomGenerator>
#include <QThread>
#include <QDebug>

class counter : public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);

signals:

public slots:
    void start();
};

#endif // COUNTER_H
