#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"zaglagy","default tex in zeglagy",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::No){
        qDebug() << "No";
    }
    else{
        QApplication::quit();
    }
}

