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

public slots:
    void enterQueryButton();
    void disconected();

signals:
    void sendTableVie(QSqlQueryModel &arg);

private:
    QSqlDatabase db;

};

#endif // CONNECTPOST_H
