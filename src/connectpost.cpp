#include "connectpost.h"

connectPost::connectPost(QObject *parent)
    : QObject{parent}
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("skansict272");

    if (!db.open()){
        QMessageBox::warning(0, "Ошибка подключения",db.lastError().text());
    }else{
         QMessageBox::information(0,"успешно ","соединение установленно");
    }


}
