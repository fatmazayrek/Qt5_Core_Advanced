#include <QCoreApplication>
#include "manager.h"
#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");

    manager m;
    m.start();

    return a.exec();
}

/* Output will be:
        Created:  "Thread 0"
        Created:  "Thread 1"
        Created:  "Thread 2"
        Created:  "Thread 3"
        Created:  "Thread 4"
        Starting..
        Starting:  "Thread 0"
        Starting:  "Thread 1"
        Starting:  "Thread 2"
        Starting:  "Thread 3"
        "Thread 0" :  0
        Starting:  "Thread 4"
        "Thread 1" :  0
        "Thread 2" :  0
        "Thread 3" :  0
        "Thread 4" :  0
        Started.. "Thread 0"
        Started.. "Thread 1"
        Started.. "Thread 2"
        Started.. "Thread 3"
        Started.. "Thread 4"
        "Thread 1" :  1
        "Thread 2" :  1
        "Thread 0" :  1
        "Thread 4" :  1
        "Thread 2" :  2
        "Thread 1" :  2
        "Thread 0" :  2
        "Thread 3" :  1
        "Thread 0" :  3
        "Thread 4" :  2
        "Thread 1" :  3
        "Thread 2" :  3
        "Thread 0" :  4
        "Thread 3" :  2
        "Thread 1" :  4
        "Thread 2" :  4
        "Thread 3" :  3
        "Thread 4" :  3
        "Thread 0" :  5
        "Thread 2" :  5
        "Thread 3" :  4
        "Thread 1" :  5
        "Thread 4" :  4
        "Thread 2" :  6
        "Thread 3" :  5
        "Thread 0" :  6
        "Thread 4" :  5
        "Thread 1" :  6
        "Thread 0" :  7
        "Thread 3" :  6
        "Thread 3" :  7
        "Thread 2" :  7
        "Thread 4" :  6
        "Thread 1" :  7
        "Thread 0" :  8
        "Thread 4" :  7
        "Thread 1" :  8
        "Thread 3" :  8
        "Thread 2" :  8
        "Thread 3" :  9
        "Thread 0" :  9
        "Thread 4" :  8
        Finished.. "Thread 3"
        Finished.. "Thread 0"
        "Thread 2" :  9
        "Thread 1" :  9
        "Thread 4" :  9
        Finished.. "Thread 4"
        Finished.. "Thread 1"
        Finished.. "Thread 2"
*/
