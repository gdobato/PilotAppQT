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

    //QCoreApplication::exit();
    QProcess *process = new QProcess(this);
    //QString file = QDir::homePath + "/holamundo.out";
    //process->execute("./home/holamundo.out");
   // process->start("/home/jenifer/build-Bike-Desktop_Qt_5_7_0_GCC_64bit-Release (copia)/Bike");
   // process->start("/home/jenifer/build-Bike-Desktop_Qt_5_7_0_GCC_64bit-Release/Bike");
   //process->start("../Bike/externalApp/Bike");
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
