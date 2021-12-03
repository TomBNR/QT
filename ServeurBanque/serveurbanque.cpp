#include "serveurbanque.h"
#include "banquemainwindow.h"


ServeurBanque::ServeurBanque(QObject *parent):QTcpServer(parent)

{
    if(!QObject::connect(this,&ServeurBanque::newConnection,this,&ServeurBanque::onServeurBanque_newConnection)){
        QMessageBox msgBox;
        msgBox.setText("erreur association signal/slot");
        msgBox.exec();
    }
}

void ServeurBanque::EnvoyerMessage(QString msg, CompteClient *client)
{
    quint16 taille = 0;
        QBuffer tampon;
        tampon.open(QIODevice::WriteOnly);
        //association du tampon au flux de sortie
        QDataStream out(&tampon);
        //construction de la trame
        out<<taille<<msg;
        //calcul de la taille de la trame
        taille = tampon.size()-sizeof (taille);
        //placement sur la premiere position du flux pour pouvoir modifier la taille
        tampon.seek(0);
        //modification de la taille de la trame
        out << taille;
        //envoie du QByteArray du tampon via la socket
        client->write(tampon.buffer());
        //lesConnexionsClients.at(lesConnexionsClients.indexOf(client))->write(msg.toLatin1());
}

void ServeurBanque::Start()
{
    if (!this->listen(QHostAddress::Any,8888))
    {
        QMessageBox msgBox;
        msgBox.setText("erreur listen "+this->errorString());
        msgBox.exec();
    }
}

void ServeurBanque::Stop()
{
    this->close();
}

void ServeurBanque::onServeurBanque_newConnection()
{
    CompteClient * client;
        //while(this->nextPendingConnection() != nullptr){
        while(hasPendingConnections()){
            client = static_cast<CompteClient * >(this->nextPendingConnection());
            connect(client,&QTcpSocket::readyRead,this,&ServeurBanque::onCompteClient_readyRead);
            connect(client,&QTcpSocket::disconnected,this,&ServeurBanque::onCompteClient_disconnected);
            lesConnexionsClients.append(client);
            qDebug() <<"client connecté";
            EnvoyerMessage("Entrez votre numero de compte",client);
        }
}

void ServeurBanque::onCompteClient_disconnected()
{
    CompteClient *client=(CompteClient*)sender();
    if (!client)
    {
        QMessageBox msg;
        msg.setText("erreur deconnexion : "+client->errorString());
        msg.exec();
    }
    else
    {
        lesConnexionsClients.removeOne(client);
        client->deleteLater();
    }
}

void ServeurBanque::onCompteClient_readyRead()
{
    CompteClient *client=(CompteClient*)sender();
        quint16 taille = 0;
        QChar commande;
        int numCompte;
        float montant;
        int index;
        if (!client)
        {
            QMessageBox msg;
            msg.setText("erreur de lecture : "+client->errorString());
            msg.exec();
        }
        else
        {
            index=lesConnexionsClients.indexOf(client);
            //si le nombre d'octets reçu est au moins égal à celui de la taille de ce que l'on doit recevoir
            if(client->bytesAvailable() >= (qint64)sizeof (taille)){
                //association de la socket au flux d'entrée
                QDataStream in(client);
                //extraire la taille de ce que l'on doit recevoir
                in >> taille;
                //si le nombre d'octets reçu est au moins égal à celui de ce que l'on doit recevoir
                if(client->bytesAvailable() >= (qint64)taille){
                    //extraire la demande du client
                    in >> commande;
                    //extraire le numéro de compte ou le montant
                    switch (commande.toLatin1()) {
                    case 'N' :
                        in >> numCompte;
                        client->DefinirNumCompte(numCompte);
                        EnvoyerMessage("Bienvenue sur le compte "+QString::number(numCompte), client);
                        qDebug() << "NumCompte envoyé";
                        break;
                    case 'R' :
                        bool x;
                        in >> montant;
                        if(montant >= 0){
                            x= client->Retirer(montant);
                            if(x==true){
                                EnvoyerMessage("Retrait de " +QString::number(montant)+ " nouveau solde "+QString::number(client->ObtenirSolde()), client);
                                qDebug() << "retrait";
                            }
                            else {
                                EnvoyerMessage("Découvert refusé",client);
                            }
                        }
                        else {
                            EnvoyerMessage("Impossible",client);
                        }
                        break;
                    case 'D' :
                        in >> montant;
                        client->Deposer(montant);
                        EnvoyerMessage("nouveau solde "+QString::number(client->ObtenirSolde()), client);
                        qDebug() << "dépot";
                        break;
                    case 'S':
                        EnvoyerMessage("Solde : "+QString::number(lesConnexionsClients.at(index)->ObtenirSolde()), client);
                        qDebug() << "Solde envoyé";
                        break;
                    }
                }
            }
        }
    }



