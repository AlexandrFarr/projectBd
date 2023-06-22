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
    void creatConnect(QVector<QString> &dataConnectBd);
    void disconected();

public slots:
    void enterQueryButton();



signals:
    void sendTableVie(QSqlQueryModel &arg);

private:
    QSqlDatabase db;

};

#endif // CONNECTPOST_H
