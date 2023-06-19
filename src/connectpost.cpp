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


void connectPost::enterQueryButton()
{
    QSqlQuery *query = new QSqlQuery(db);
    QSqlQueryModel *model = new QSqlQueryModel();

    query->prepare("SELECT * FROM users1");
    query->exec();
    model->setQuery(std::move(*query));

    emit (this->sendTableVie(*model));
}


