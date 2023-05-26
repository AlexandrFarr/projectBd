#include "connectpost.h"




connectPost::connectPost(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("127.0.0.1");
    db.setDatabaseName("testdb");
    db.setUserName("postgres");
    db.setPassword("skansict272");

    if (!db.open()){
        QMessageBox::warning(0, "Ошибка подключения",db.lastError().text());
    }else{
         QMessageBox::information(0,"успешно ","соединение установленно");


    }


}

void connectPost::showTable(QString nameTable)
{
    QSqlQuery query = QSqlQuery(db);
    if( !query.exec("SELECT * FROM users1")){
         QMessageBox::information(0,"Неуспешно ","неудачный запрос");
         return;
    }

    while( query.next()){
        qDebug() << query.record();
    }
}

void connectPost::enterQueryButton()
{
    this->showTable("users1");
}
