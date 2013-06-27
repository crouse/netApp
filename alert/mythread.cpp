#include "mythread.h"
#include <QDebug>
#include <QDateTime>

MyThread::MyThread()
{
}

void MyThread::run()
{
    static int a = 0;
    static int b = 0;
    static int c = 0;
    static int d = 0;

    while (1) {
        msleep(1000);
        QDateTime current = QDateTime::currentDateTime();
        qint8 hour = current.toString("hh").toInt();
        qint8 minute = current.toString("mm").toInt();

        if (hour == 8 && minute <= 30 && d == 0) {
            emit alert("Attention: Do you want to have a breakfast?");
            d = 1;
        }

        if (hour <= 10 && a == 0) {
            a = 1;
            QString now = current.toString();
            emit alert("Attention: " + now + " do not forget to sign in!!!");
        } else if (hour >= 18 && b == 0) {
            b = 1;
            QString now = current.toString();
            emit alert("Attention: " + now + " do not forget to sign out!!!");
        }

        if ((minute == 30 || minute == 0) && c == 0) {
            emit alert("Need a rest, baby!");
            c = 1;
        } else if (minute % 10 != 0) {
            c = 0;
        }

    }
}
