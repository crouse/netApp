#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QApplication>

#include <QIcon>
#include <QMenuBar>
#include "mythread.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *quitAction;
    MyThread *thread;

    void createActions();
    void createTray();
    void showMessage(QString title, QString message);
private slots:
    void doAlert(QString message);
};

#endif // MAINWINDOW_H
