#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "comdatabase.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void on_pushButton_clicked();
		void on_pushButton_fecharDB_clicked();
		void on_pushButton_load_clicked();
		void on_pushButton_load_combo_clicked();

	private:
		Ui::MainWindow *ui;

		QSqlDatabase *DB;
		QSqlQuery    *RS;
		comDatabase  *dataBase;
};

#endif // MAINWINDOW_H
