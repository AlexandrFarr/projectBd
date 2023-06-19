#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectpost.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("connectedDb");

    connectPost *bd = new connectPost();

    connect(ui->buttonQuery, &QPushButton::clicked, bd, &connectPost::enterQueryButton);
    connect(bd, &connectPost::sendTableVie,this, &MainWindow::showTableVie);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTableVie(QSqlQueryModel &model)
{
     ui->tableView->setModel(std::move(&model));
}




