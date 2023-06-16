#ifndef CONNECTPOST_H
#define CONNECTPOST_H

#include <QObject>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>


class connectPost : public QObject
{
    Q_OBJECT

public:
    explicit connectPost(QObject *parent = nullptr);
    void showTable(QString nameTable);

public slots:
    void enterQueryButton();

signals:
    void sendTableVie(QSqlQueryModel *model);

private:
    QSqlDatabase db;


};

#endif // CONNECTPOST_H
