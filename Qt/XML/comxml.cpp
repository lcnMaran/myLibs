#include "comxml.h"


comXML::comXML()
{

}


comXML::comXML(QString _caminhoXML)
{
    _dir_XML = _caminhoXML;
}

void comXML::readXML()
{
    _XML = new QXmlStreamReader();
    QFile file(_dir_XML);

    if(!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Falha ao abrir LOG.xml";


    _XML->setDevice(&file);

    while(!_XML->atEnd())
    {
        if(_XML->isStartElement())
        {
            QString name = _XML->name().toString();
            qDebug() << name;
            if(name == "evento"){

                for(int i=0 ; i <_XML->attributes().size(); i++)
                {
                    qDebug() << "Evento: " << _XML->attributes().at(i).value();
                }
            }

            if(name == "sensor" || name == "data" || name == "hora")
            {
                QString text = _XML->readElementText();
                qDebug() << name << text;
            }
        }

        if(_XML->isEndElement())
        {
            QString name = _XML->name().toString();
            if(name== "evento")
            {
                qDebug() << "--------------------------------------";
            }
        }

            _XML->readNext();

       }
        if(_XML->hasError())
        {
            qDebug() << "Error loading XML, função read_LOG():" << _XML->errorString();
        }
}

void comXML::writeXML()
{
    qDebug() << "Hello world...";
}


QStringList comXML::eventos()
{
    QStringList logs;

    _XML = new QXmlStreamReader();
    QFile file(_dir_XML);

    if(!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Falha ao abrir LOG.xml";


    _XML->setDevice(&file);

        while(!_XML->atEnd()){

			if(_XML->isStartElement())
			{
				QString name = _XML->name().toString();


				if(name == "evento"){
					logs << _XML->attributes().at(0).value().toString();
				}

				if(name == "sensor" || name == "data" || name == "hora"){
					QString text = _XML->readElementText();
					logs << text;
					//qDebug() << text;
				}
			}

            _XML->readNext();
		}
		
        if(_XML->hasError()){
			qDebug() << "Error loading XML, função read_LOG():" << _XML->errorString();
        }

    return logs;
}


/*  FUNÇÃO QUE RETORNA TODOS VALORES EM UMA QSTRINGLIST
 *
 * QStringList logs;

    _XML = new QXmlStreamReader();
    QFile file(_dir_XML);

    if(!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Falha ao abrir LOG.xml";


    _XML->setDevice(&file);

    while(!_XML->atEnd())
    {
        if(_XML->isStartElement())
        {
            QString name = _XML->name().toString();


            if(name == "evento"){

                for(int i=0 ; i <_XML->attributes().size(); i++)
                {
                    logs << _XML->attributes().at(i).value().toString();
                }
            }

            if(name == "sensor" || name == "data" || name == "hora")
            {
                QString text = _XML->readElementText();
                logs << text;
            }
        }

            _XML->readNext();

       }
        if(_XML->hasError())
        {
            qDebug() << "Error loading XML, função read_LOG():" << _XML->errorString();
        }

        qDebug() << logs;
*/

