#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("To do"));
    QIcon icon = QIcon(":/pics/pencil.png");
    setWindowIcon(icon);

    thread = new MyThread();
    createActions();
    thread->start();
    createTray();
    trayIcon->setIcon(icon);
    trayIcon->show();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::doAlert(QString message)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

void MainWindow::createTray()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(quitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

void MainWindow::createActions()
{
    quitAction = new QAction(tr("exit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(thread, SIGNAL(alert(QString)), this, SLOT(doAlert(QString)));
}

void MainWindow::showMessage(QString title, QString message)
{
    trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 10000);
}
