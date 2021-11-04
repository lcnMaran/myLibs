#include "home.h"
#include "ui_home.h"


home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

    devSerial  = new QSerialPort();
    connSerial = new comserial(devSerial);

    tempo = new QTimer(this);
    QObject::connect(tempo, SIGNAL(timeout()), this, SLOT(atualizaDados()));
    tempo->start(500);
}


home::~home()
{
    delete ui;
}


void home::on_pushButton_reset_clicked()
{
    if(devSerial->isOpen()){
        devSerial->close();
    }

       // QStringList nome = connSerial->CarregarDispositivos();

        bool statusOpenSerial;

        statusOpenSerial = connSerial->Conectar("ttyACM0",9600);
        if (statusOpenSerial){
        }
        else{
        }
}


void home::ReadData(){
        QString data = connSerial->Read();
        qDebug() << "Input: " << data;
}


void home::on_pushButton_enviar_clicked()
{
    //ENVIA O TEXTO DO lineEdit_RX PARA A SERIAL
    QByteArray dados_TX = ui->lineEdit_RX->text().toUtf8();
    //QByteArray dados_TX = "hardware";

    connSerial->escreveSerial(devSerial,dados_TX+"\n");

    //RECEBE O TEXTO DA SERIAL
    QByteArray dados_RX = connSerial->recebeSerial(devSerial);
    qDebug() << "RX: " << dados_RX;

}

/*
 * Função criada para ser chamada toda vez que acontecer
 * o estouro da variavel TEMPO
 */
void home::atualizaDados(){
    
    QByteArray dados_TX  = "sensor";
    QByteArray dados2_TX = "sensor2";

    connSerial->escreveSerial(devSerial,dados_TX+"\n");
    QByteArray dados_RX = connSerial->recebeSerial(devSerial);
    ui->label_corrente->setText(dados_RX);

    connSerial->escreveSerial(devSerial,dados2_TX+"\n");
    QByteArray dados2_RX = connSerial->recebeSerial(devSerial);
    ui->label_tensao->setText(dados2_RX);

    int aux = dados_RX.toInt() * dados2_RX.toInt() ;
    QString potencia = QString::number(aux);

    ui->label_potencia->setText(potencia);
}



