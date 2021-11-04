#ifndef COMXML_H
#define COMXML_H


#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QDebug>


#define VERSAO   "1.0.0"
#define AUTOR    "@Luciano Maran"
#define DATA_LIB "02 de Agosto de 2018"


class comXML
{
	public:
		comXML(QString _caminhoXML);
		comXML();
		QStringList eventos();
		void readXML();
		void writeXML();

	private:
		QXmlStreamReader *_XML;
		QString _dir_XML;
};

#endif // COMXML_H
