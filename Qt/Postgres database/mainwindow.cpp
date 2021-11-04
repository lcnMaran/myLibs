#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB = new QSqlDatabase();
    dataBase = new comDatabase(DB);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
	ui->pushButton->setEnabled(!true);
	ui->pushButton_fecharDB->setEnabled(true);
	dataBase->openDB();
}


void MainWindow::on_pushButton_fecharDB_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_fecharDB->setEnabled(!true);

    dataBase->closeDB();
}


void MainWindow::on_pushButton_load_clicked()
{
    QString dados= "null";

    dados = dataBase->dados("select * from users where username=? and passwd=?");
    ui->lineEdit_name->setText(dados);
}

void MainWindow::on_pushButton_load_combo_clicked()
{
    QStringList dados;

    dados = dataBase->array("select * from users");
    ui->comboBox_names->clear();
    ui->comboBox_names->addItems(dados);
}
