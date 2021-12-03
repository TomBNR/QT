#ifndef MONTHREAD_H
#define MONTHREAD_H
#include <QThread>
#include <QWidget>
#include <QtDebug>
#include <QBuffer>
#include <QMutex>
#include <QString>


class MonThread : public QThread
{
public:
    MonThread(QString _nom);
    void run();
    static unsigned int nbThread;

private:
    QString nom;
    static QBuffer ZoneCommune;
    void afficherZone();
    static QMutex verrou;

signals:
    void monId(quint64 id);

};
#endif // MONTHREAD_H
