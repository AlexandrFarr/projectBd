#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QTableView>
#include <QString>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setDataBd();

    QVector<QString> vec;
    ~MainWindow();

signals:
    void mySignaltoBd();

public slots:
    void showTableVie( QSqlQueryModel &arg);



private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
