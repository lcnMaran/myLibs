#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "QDebug"


#ifndef COMDATABASE_H
#define COMDATABASE_H


#define VERSAO   "1.0.0"
#define AUTOR    "@lcn"
#define DATA_LIB "02 de Agosto de 2018"


class comDatabase
{
	public:
		comDatabase(QSqlDatabase *db);
		void openDB();
		void closeDB();

		QString dados(QString SQL);
		QStringList array(QString SQL);


	protected:
		QSqlDatabase *DB;
		QSqlQuery    *RS;
};

#endif // COMDATABASE_H
