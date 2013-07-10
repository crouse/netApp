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
    static int ifRest = 0;

    while (1) {
        msleep(1000);
        QDateTime current = QDateTime::currentDateTime();
        qint8 hour = current.toString("hh").toInt();
        qint8 minute = current.toString("mm").toInt();

        switch(hour) {
        case 6:
        case 7:
        case 8:
        case 9:
            if (minute < 30 && a == 0) {
                emit alert("Have you had breakfast yet? Do not forget to sign in!");
                a = 1;
            }
            break;


        case 12:
            if (minute < 10 && b == 0) {
                emit alert("Have you had lunch yet?");
                b = 1;
            }
            break;

        case 18:
            if (minute >= 0 && c == 0) {
                emit alert("Do not forget to sign out!");
                c = 1;
            }
            break;

        default:
            a = 0, b = 0, c = 0;
            break;
        }

        if ((minute == 30 || minute == 0) && ifRest == 0 && hour > 6 && hour < 20) {
            emit alert("Need a rest, baby!");
            ifRest = 1;
        } else if (minute % 10 != 0) {
            ifRest = 0;
        }

    }
}
