#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectpost.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectPost *bd = new connectPost();

    connect(ui->buttonQuery, &QPushButton::clicked, bd, &connectPost::enterQueryButton);
     connect(ui->buttonQuery, &connectPost::sendTableVie(),
             bd,this->showTableVie());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTableVie(QSqlQueryModel *model)
{
    ui->tableView->setModel(model);
}




