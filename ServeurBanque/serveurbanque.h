#ifndef SERVEURBANQUE_H
#define SERVEURBANQUE_H
#include <QMainWindow>
#include <QObject>
#include <QProcess>
#include <QList>
#include <QTcpServer>
#include <QMessageBox>
#include <QBuffer>
#include "compteclient.h"


class ServeurBanque : public QTcpServer
{
public:
    ServeurBanque(QObject *parent = nullptr);
    void EnvoyerMessage(QString msg, CompteClient  *client);
    void Start();
    void Stop();

private slots:
    void onServeurBanque_newConnection();
    void onCompteClient_disconnected();
    void onCompteClient_readyRead();

private:
    QList <CompteClient *>lesConnexionsClients;

};

#endif // SERVEURBANQUE_H
