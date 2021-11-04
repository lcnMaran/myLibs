#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_loadXML_clicked()
{
    QStringList logs;

    //Cria novo objeto da classe comXML() e envia uma String com o caminho do arquivo.xml
    _comXML = new comXML("/home/user/Qt/Projetos/XML/connXML/log.xml");

    //Recebe uma lista de todos os eventos e alarmes registrados
    logs << _comXML->eventos();

    //Corre a lista escrevendo os dados no TextEdit
    for(int i=0 ; i < logs.size() ; i++){

        if(logs.value(i) == "Externo" || logs.value(i) == "Interno"){
            ui->textEdit_visorXML->append("--------" + logs.at(i) + "--------");
        }else{
            ui->textEdit_visorXML->append(logs.at(i));
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    _comXML = new comXML();
    _comXML->writeXML();

}
