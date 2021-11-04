#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "comserial.h"
#include <QTime>
#include <QTimer>

namespace Ui {
	class home;
}

class home : public QWidget
{
    Q_OBJECT

	public:
		explicit home(QWidget *parent = 0);
		~home();


	private slots:
		void on_pushButton_reset_clicked();
		void ReadData();
		void on_pushButton_enviar_clicked();
		void atualizaDados();

	private:
		Ui::home *ui;
		QSerialPort *devSerial;
		comserial *connSerial;
		QTimer *tempo;
};

#endif // HOME_H
