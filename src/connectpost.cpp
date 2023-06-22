#include "connectpost.h"


connectPost::connectPost(QObject *parent)
    : QObject{parent}
{}

void connectPost::creatConnect(QVector<QString> &dataConnectBd)
{

    if(!dataConnectBd.empty() && !db.isOpen()){

        //if(db.isOpen()){
          //  db.close();
         //   QMessageBox::warning(0, "База данных уже подключена"," Отключение старой базы данных и подключееие новой");
       // }

        db = QSqlDatabase::addDatabase(dataConnectBd[0]);

        db.setHostName(dataConnectBd[1]);
        db.setDatabaseName(dataConnectBd[2]);
        db.setUserName(dataConnectBd[3]);
        db.setPassword(dataConnectBd[4]);

        if (!db.open()){
            QMessageBox::warning(0, "Ошибка подключения",db.lastError().text());
        }else{
             QMessageBox::information(0,"успешно ","соединение установленно");
        }
    }else{
         QMessageBox::warning(0, "некоррентые данные"," введите данные для подклчюения к базе данных");
    }
}


void connectPost::enterQueryButton()
{
    //реализоать новое подключение к другой базе данных

    if(db.isOpen()){
        QSqlQuery *query = new QSqlQuery(db);
        QSqlQueryModel *model = new QSqlQueryModel();

        query->prepare("SELECT * FROM users1");
        query->exec();
        model->setQuery(std::move(*query));

        emit (this->sendTableVie(*model));
    }

}

void connectPost::disconected()
{
    if(db.isOpen()){
        db.close();
    }else{
        QMessageBox::warning(0, "Ошибка отключения","нет активных подключений");
    }


}


