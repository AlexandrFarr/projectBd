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
    ui->lineEdit_6->setEchoMode(QLineEdit::Password);

    connectPost *bd = new connectPost();
    vec = QVector<QString>(6,"");

    //get data for bd from ui(line_edit) in QVECTOR and call  bd.creacConnection(&QVECTOR);
    connect(ui->buttonQuery, &QPushButton::clicked, [this,bd](){

        this->setDataBd();
        bd->creatConnect(vec);

    });

    connect(ui->buttonQuery, &QPushButton::clicked, bd, &connectPost::enterQueryButton);
    connect(bd, &connectPost::sendTableVie,this, &MainWindow::showTableVie);   
}

//vecotr[[Type Data Based],[hostname],[DatabaseName],[username],[password]]
void MainWindow::setDataBd()
{

     this->vec[0] = ui->lineEdit->text();
     this->vec[1] = ui->lineEdit_2->text();
     this->vec[2] = ui->lineEdit_3->text();
     this->vec[3] = ui->lineEdit_4->text();
     this->vec[4] = ui->lineEdit_5->text();
     this->vec[5] = ui->lineEdit_6->text();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTableVie(QSqlQueryModel &model)
{
    ui->tableView->setModel(std::move(&model));
}





