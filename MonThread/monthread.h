#ifndef MONTHREAD_H
#define MONTHREAD_H
#include <QThread>
#include <QDebug>

class MonThread : public QThread
{
public:
    MonThread(QString chaine);
    void run();

private:
    QString nom;

};
#endif // MONTHREAD_H
