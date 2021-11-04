#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "comxml.h"

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
		void on_pushButton_loadXML_clicked();
		void on_pushButton_clicked();

	private:
		Ui::MainWindow *ui;
		comXML *_comXML;
};

#endif // MAINWINDOW_H
