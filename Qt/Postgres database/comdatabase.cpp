#include "comdatabase.h"

comDatabase::comDatabase(QSqlDatabase *db)
{
    DB = db;
}

void comDatabase::openDB()
{
   *DB = QSqlDatabase::database("name_db");
   *DB = QSqlDatabase::addDatabase("QPSQL", "name_db");
    DB->setHostName("127.0.0.1");
    DB->setUserName("postgres");
    DB->setPassword("123456");
    DB->setDatabaseName("name");

    if(DB->open())
        qDebug() << "...DB aberto com sucesso.";
    else
        qDebug() << "...DB não foi inicializado.";
}


void comDatabase::closeDB()
{
   DB->close();
   QSqlDatabase::removeDatabase("name_db"); //QLatin1String

    if(DB->isOpen())
        qDebug() << "...falha ao encerrar DB.";
    else
        qDebug() << "...DB fechado com sucesso.";
}


QString comDatabase::dados(QString SQL)
{
    RS = new QSqlQuery(*DB);
    qDebug() << "Versão: " << VERSAO << " - Autor: " << AUTOR;
    int senha = 1234;
    QString user = "admin";

    RS->prepare(SQL);
    RS->bindValue(0, user);
    RS->bindValue(1, senha);
    RS->exec();
    if(RS->first())
        return RS->value("username").toString();
    else
        return "NULL";
}


QStringList comDatabase::array(QString SQL)
{
    RS = new QSqlQuery(*DB);
    QStringList dados;

    RS->prepare(SQL);
    RS->exec();
    if(RS->first()){

        do{
            dados << RS->value("username").toString();
        }while(RS->next());

        return dados;

    }else{
      qDebug() << "nenhum dado encontrado";
    }
}
















