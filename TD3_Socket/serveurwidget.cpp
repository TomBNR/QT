#include "serveurwidget.h"
#include "ui_serveurwidget.h"

ServeurWidget::ServeurWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServeurWidget)
{
    ui->setupUi(this);
    socketEcouteServeur = new QTcpServer(this);
    socketEcouteServeur->setMaxPendingConnections(10);
}

ServeurWidget::~ServeurWidget()
{
    delete ui;
    delete socketEcouteServeur;
}

void ServeurWidget::onQTcpServer_newConnection()
{
    QProcess *p = new QProcess(this);;
    QTcpSocket *client;
    client = socketEcouteServeur->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&ServeurWidget::onQTcpSocket_readyRead);
    QHostAddress adresseClient = client->peerAddress();
    ui->textEdit->append(adresseClient.toString());
    listeSocketDialogueClient.append(client);
    connect(p,&QProcess::readyReadStandardOutput,this,&ServeurWidget::onQProcess_readyReadStandardOutput);
    listeProcess.append(p);


}

void ServeurWidget::onQTcpSocket_readyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    int indexProcess = listeSocketDialogueClient.indexOf(client);

    if(client->bytesAvailable() )
    {
        QByteArray temps = client->readAll();
        QChar  commande = temps.at(0);
        QString message = "com recu de "+client->peerAddress().toString()+" : ";
        message += commande;
        ui->textEdit->append(message);
        QString reponse;
        switch(commande.toLatin1()){

        case 'u' : reponse = getenv("USER");
            client->write(reponse.toLatin1());
            break;

        case 'c' : reponse = QHostInfo::localHostName();
            client->write(reponse.toLatin1());
            break;

        case 'o' :
            listeProcess.at(indexProcess)->start("uname");
        case 'a' :
            listeProcess.at(indexProcess)->start("uname",QStringList("-p"));
        }
        qDebug()<<"reponse : "<<reponse;
    }


}

void ServeurWidget::onQTcpSocket_disconnected()
{

}

void ServeurWidget::onQProcess_readyReadStandardOutput()
{
    QProcess *p=qobject_cast<QProcess*>(sender());
    int indexClient=listeProcess.indexOf(p);

    QString reponse = p->readAllStandardOutput();
    if(!reponse.isEmpty())
    {
        QString message = "Réponse envoyée à " + listeSocketDialogueClient.at(indexClient)->peerAddress().toString() + " : " + reponse;
        ui->textEdit->append(message);
        listeSocketDialogueClient.at(indexClient)->write(reponse.toLatin1());
    }

}


void ServeurWidget::on_pushButtonServeur_clicked()
{
    if(!socketEcouteServeur->listen(QHostAddress::Any,static_cast<quint16>(ui->spinBoxPort->value()))){
        QString message = "impossible de démarrer le serveur" + socketEcouteServeur->errorString();
        ui->textEdit->append(message);
        close();
    }
    else{

        QList<QHostAddress> listeAdresse = QNetworkInterface::allAddresses();

        for(int i = 0; i < listeAdresse.size(); i++){
            if(listeAdresse.at(i).toIPv4Address())
                ui->textEdit->append((listeAdresse.at(i).toString()));
        }

        ui->textEdit->append("Numero du port : " + QString::number(socketEcouteServeur->serverPort()));
        connect(socketEcouteServeur,&QTcpServer::newConnection,this,&ServeurWidget::onQTcpServer_newConnection);
        ui->pushButtonServeur->setEnabled(false);
        ui->spinBoxPort->setEnabled(false);
    }

}
