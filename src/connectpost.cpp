#include "connectpost.h"


connectPost::connectPost(QObject *parent)
    : QObject{parent}
{}

void connectPost::creatConnect(QVector<QString> &dataConnectBd)
{
    if(db.isOpen() && this->table != dataConnectBd[0]){
        this->table = dataConnectBd[4];
    }

    else{
        if(db.isOpen() &&  db.hostName() != dataConnectBd[0]){
            db.close();

            db.setHostName(dataConnectBd[1]);
            db.setDatabaseName(dataConnectBd[2]);
            db.setUserName(dataConnectBd[3]);
            db.setPassword(dataConnectBd[5]);

            this->table = dataConnectBd[4];

            if (!db.open()){
                QMessageBox::warning(0, "Ошибка подключения",db.lastError().text());
            }else{
                 qDebug()<< "успешно соединение установленно";
            }
        }

    else{
        if(!dataConnectBd.empty() && db.hostName()!= dataConnectBd[0]){

             db = QSqlDatabase::addDatabase(dataConnectBd[0]);

             db.setHostName(dataConnectBd[1]);
             db.setDatabaseName(dataConnectBd[2]);
             db.setUserName(dataConnectBd[3]);
             db.setPassword(dataConnectBd[5]);


             this->table = dataConnectBd[4];
            }
        }
    }



    if (!db.open()){
        QMessageBox::warning(0, "Ошибка подключения",db.lastError().text());
    }else{
         QMessageBox::information(0,"успешно ","соединение установленно");
    }
}


void connectPost::enterQueryButton()
{
    //реализоать новое подключение к другой базе данных

    if(db.isOpen()){
        QSqlQuery *query = new QSqlQuery(db);
        QSqlQueryModel *model = new QSqlQueryModel();

        QString issue = "SELECT * FROM "+this->table;
        query->prepare(issue);
        query->exec();
        model->setQuery(std::move(*query));

        emit (this->sendTableVie(*model));
    }
}




