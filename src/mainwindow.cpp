#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectpost.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectPost bd;

}

MainWindow::~MainWindow()
{
    delete ui;
}

