#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{


    QProcess *process = new QProcess(this);

    process->start(EXTERNALAPPPATH);

    if (process->waitForStarted() == false) {
            qDebug() << "Error starting cmd.exe process";
            qDebug() << process->errorString();
        }

        // Show process output
        process->waitForReadyRead();
        qDebug() << process->readAllStandardOutput();

       // process->write("dir");

       // process->waitForBytesWritten();
        //process->waitForReadyRead();

      //  qDebug() << process->readAllStandardOutput();
      //process->execute("/home/holamundo.out");
}
