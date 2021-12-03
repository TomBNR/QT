#include "monthread.h"

MonThread::MonThread(QString chaine):nom(chaine)
{

}

void MonThread::run()
{
    qDebug()<<"je suis le thread"<<nom;
    qDebug()<<"min id est "<<currentThreadId();
}
