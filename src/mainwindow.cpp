#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectpost.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectPost *bd = new connectPost();
    //bd->showTable("users1");

    connect(ui->buttonQuery, &QPushButton::clicked, bd, &connectPost::enterQueryButton);
   // connect(, &MainWindow::mySignaltoBd, bd, &connectPost::enterQueryButton);
    //connect(ui->pushButton, SIGNAL(mySignaltoBd()), bd , SLOT(enterQueryButton()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

