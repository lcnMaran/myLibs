#ifndef COMSERIAL_H
#define COMSERIAL_H


#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


#define VERSAO   "1.0.0"


class comserial
{
	public:
		comserial(QSerialPort *myDev);
		~comserial();

		QStringList CarregarDispositivos();

		bool Conectar(QString Port, u_int32_t bd);
		bool Desconectar(void);

		qint64 Write(const char *cmd);
		QString Read();
		QString Read(int TamanhoBuffer);


		//TESTE DAS FUNÇÕES DE ESCRITA E LEITURA
		void escreveSerial(QSerialPort *port, const QByteArray &writeData);
		QByteArray recebeSerial(QSerialPort *port);

	protected:
		QSerialPort *devSerial;
};

#endif // COMSERIAL_H
