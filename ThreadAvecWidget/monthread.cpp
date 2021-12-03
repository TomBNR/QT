#include "monthread.h"
QBuffer MonThread::ZoneCommune;
unsigned int MonThread::nbThread=0;

MonThread::MonThread(QString _nom):nom(_nom)

{
    nbThread++;
}

void MonThread::run()
{
    verrou.lock();
    qDebug()<<"je suis le thread"<<nom;
    qDebug()<<" mon id est "<<currentThread();
   /* if(nom.toInt()%2==0){
        emit monId((quint64)currentThreadId());
    }*/
    ZoneCommune.open(QIODevice::ReadWrite);
    QDataStream out(&ZoneCommune);
    out<<(qint64)QThread::currentThreadId()<<nom;
    verrou.unlock();
    afficherZone();

}

void MonThread::afficherZone()
{
    ZoneCommune.open(QIODevice::ReadWrite);
    QDataStream in(&ZoneCommune);
    qint64 ptr;
    QString chaine;
    in>>ptr>>chaine;
    qDebug()<<" thread "<<nom<<"zone commune"<<chaine<<"id : "<<QString::number<<(ptr,16);
}

