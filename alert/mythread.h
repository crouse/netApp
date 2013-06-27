#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
protected:
    void run();
signals:
    void alert(QString message);
};

#endif // MYTHREAD_H
