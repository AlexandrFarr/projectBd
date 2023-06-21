#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectpost.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("connectedDb");

    connectPost *bd = new connectPost();
    //QVector<QString> vec[5];

    //QVector<QString> vec(5,"");
    vec = QVector<QString>(5,"");

    connect(ui->buttonQuery, &QPushButton::clicked, this, &MainWindow::setDataBd);
    connect(ui->buttonQuery, &QPushButton::clicked, bd, &connectPost::enterQueryButton);
    connect(bd, &connectPost::sendTableVie,this, &MainWindow::showTableVie);

    connect(ui->ButtonClose, &QPushButton::clicked, bd, &connectPost::disconected);
    connect(ui->ButtonClose, &QPushButton::clicked, this, &MainWindow::clearTable);

}

void MainWindow::setDataBd()
{

     this->vec[0] = ui->lineEdit->text();
     this->vec[1] = ui->lineEdit_2->text();
     this->vec[2] = ui->lineEdit_3->text();
     this->vec[3] = ui->lineEdit_4->text();
    this->vec[4] = ui->lineEdit_5->text();

    for(int i = 0; i < 5; i++){

        QString str1 = vec[i];
        qDebug() << str1;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTableVie(QSqlQueryModel &model)
{
    ui->tableView->setModel(std::move(&model));
}

void MainWindow::clearTable()
{
   // if( ui->tableView->model()->rowCount() > 0)
  //  {
   //     ui->tableView->setModel(nullptr);
   // }

}



