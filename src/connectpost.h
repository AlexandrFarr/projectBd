#ifndef CONNECTPOST_H
#define CONNECTPOST_H

#include <QObject>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

class connectPost : public QObject
{
    Q_OBJECT
public:
    explicit connectPost(QObject *parent = nullptr);

signals:

};

#endif // CONNECTPOST_H
