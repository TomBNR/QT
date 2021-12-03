#include "serveur.h"
#include "ui_serveur.h"

ServeurCrawler::ServeurCrawler(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServeurCrawler)
{
    ui->setupUi(this);
}

ServeurCrawler::~ServeurCrawler()
{
    delete ui;
}



void ServeurCrawler::onQTcpServer_newConnection()
{
    QProcess *p = new QProcess(this);;
    QTcpSocket *client;
    client = socketEcoute->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&ServeurCrawler::onQTcpSocket_readyRead);
    QHostAddress adresseClient = client->peerAddress();
    ui->textEdit->append(adresseClient.toString());
    listeSocketsClient.append(client);
    connect(p,&QProcess::readyReadStandardOutput,this,&ServeurCrawler::onQProcess_readyReadStandardOutput);
    listeProcess.append(p);

}

void ServeurCrawler::onQTcpSocket_readyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    int indexProcess = listeSocketsClient.indexOf(client);

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
            listePositions.at(indexProcess)->start("uname");
        case 'a' :
            listePositions.at(indexProcess)->start("uname",QStringList("-p"));
        }
        qDebug()<<"reponse : "<<reponse;
    }
}

void ServeurCrawler::on_pushButtonLancementServeur_clicked()
{
    if(!socketEcoute->listen(QHostAddress::Any,static_cast<quint16>(ui->spinBox->value()))){
        QString message = "impossible de démarrer le serveur" + socketEcoute->errorString();
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
        connect(socketEcoute,&QTcpServer::newConnection,this,&ServeurCrawler::onQTcpServer_newConnection);
        ui->pushButtonServeur->setEnabled(false);
        ui->spinBoxPort->setEnabled(false);
    }
}




QPoint ServeurCrawler::DonnerPositionUnique()
{
    QRandomGenerator gen;
        QPoint pt;
        gen.seed(QDateTime::currentMSecsSinceEpoch());
        int ligne;
        int colonne;
        do
        {
            ligne = gen.bounded(TAILLE);
           QThread::usleep(20000);// attendre 20ms
            colonne = gen.bounded(TAILLE);
           QThread::usleep(20000);// attendre 20ms
            pt = QPoint(colonne,ligne);
        }while (listePositions.contains(pt));
        return pt;
    }


double ServeurCrawler::CalculerDistance(QPoint pos)
{
    double distance;
    int xVecteur = tresor.x()-pos.x();
    int yVecteur = tresor.y()-pos.y();
    distance = sqrt((xVecteur*xVecteur + yVecteur*yVecteur));
    return distance;
}
