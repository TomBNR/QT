#include "clientmainwindow.h"
#include "ui_clientmainwindow.h"

ClientMainWindow::ClientMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientMainWindow)
{
    ui->setupUi(this);
    socketClientBanque = new QTcpSocket();
    ui->radioButtonSolde->setChecked(true);
    ui->groupBoxOperationBanque->setEnabled(false);
    connect(socketClientBanque,&QTcpSocket::connected,this,&ClientMainWindow::onQtcpSocket_connected);
    connect(socketClientBanque,&QTcpSocket::disconnected,this,&ClientMainWindow::onQtcpSocket_disconnected);
    connect(socketClientBanque,&QTcpSocket::readyRead,this,&ClientMainWindow::onQtcpSocket_readyRead);
    connect(socketClientBanque,&QTcpSocket::connected,this,&ClientMainWindow::onQtcpSocket_connected);
    connect(socketClientBanque,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&ClientMainWindow::onQtcpSocket_error);
}

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}


void ClientMainWindow::on_pushButtonConnexion_clicked()
{
    if(ui->pushButtonConnexion->text()=="Connexion"){
        socketClientBanque->connectToHost(ui->lineEditAdresse->text(),ui->lineEditPort->text().toInt());
        ui->pushButtonConnexion->setText("Deconnexion");
        ui->groupBoxOperationBanque->setEnabled(true);
    }
    else {
        ui->pushButtonConnexion->setText("Connexion");
        socketClientBanque->disconnectFromHost();
        ui->groupBoxOperationBanque->setEnabled(false);
    }

}

void ClientMainWindow::on_pushButtonNumeroCompte_clicked()
{
    quint16 taille=0;
    QChar commande ='N';
    int compte=ui->lineEditNumeroCompte->text().toInt();
    QBuffer tampon;
    //association du tampon au flux de sortie
    tampon.open(QIODevice::WriteOnly);
    //association du tampon au flux de sortie
    QDataStream out(&tampon);
    if(compte != 0){
        //construction de la trame
        out << taille << commande << compte;
        //calcul de la taille de la trame
        taille = tampon.size()-sizeof(taille);
        //placement sur la première position du flux pour pouvoir modifier la taille
        tampon.seek(0);
        //modification de la trame avec la taille réel de la trame
        out << taille;
        //envoi du QByteArray du tampon via la socket
        socketClientBanque->write(tampon.buffer());
        ui->textEditEtatConnexion->append("Numéro de compte envoyé");
    }
    else{
        ui->textEditEtatConnexion->append("Numéro de compte vaut 0");
    }
}

void ClientMainWindow::on_pushButtonEnvoi_clicked()
{
    QBuffer tampon;
    quint16 taille=0;
    float montant = ui->lineEditMontant->text().toFloat();
    QChar commande;
    if(ui->radioButtonSolde->isChecked() == true){
        commande = 'S';
        //association du tampon au flux de sortie
        tampon.open(QIODevice::WriteOnly);
        //association du tampon au flux de sortie
        QDataStream out(&tampon);
        //construction de la trame
        out << taille << commande;
        //calcul de la taille de la trame
        taille = tampon.size()-sizeof(taille);
        //placement sur la première position du flux pour pouvoir modifier la taille
        tampon.seek(0);
        //modification de la trame avec la taille réel de la trame
        out << taille;
        //envoi du QByteArray du tampon via la socket
        socketClientBanque->write(tampon.buffer());

    }
    if(ui->radioButtonDepot->isChecked() == true){
        commande = 'D';
        //association du tampon au flux de sortie
        tampon.open(QIODevice::WriteOnly);
        //association du tampon au flux de sortie
        QDataStream out(&tampon);
        //construction de la trame
        out << taille << commande << montant;
        //calcul de la taille de la trame
        taille = tampon.size()-sizeof(taille);
        //placement sur la première position du flux pour pouvoir modifier la taille
        tampon.seek(0);
        //modification de la trame avec la taille réel de la trame
        out << taille;
        //envoi du QByteArray du tampon via la socket
        socketClientBanque->write(tampon.buffer());

    }
    if(ui->radioButtonRetrait->isChecked() == true){
        commande = 'R';
        //association du tampon au flux de sortie
        tampon.open(QIODevice::WriteOnly);
        //association du tampon au flux de sortie
        QDataStream out(&tampon);
        //construction de la trame
        out << taille << commande << montant;
        //calcul de la taille de la trame
        taille = tampon.size()-sizeof(taille);
        //placement sur la première position du flux pour pouvoir modifier la taille
        tampon.seek(0);
        //modification de la trame avec la taille réel de la trame
        out << taille;
        //envoi du QByteArray du tampon via la socket
        socketClientBanque->write(tampon.buffer());
    }
}

void ClientMainWindow::onQtcpSocket_connected()
{

        ui->textEditEtatConnexion->append("Connecté");


}

void ClientMainWindow::onQtcpSocket_disconnected()
{
    ui->textEditEtatConnexion->append("Déconnexion du client");

}

void ClientMainWindow::onQtcpSocket_error(QAbstractSocket::SocketError socketError)
{
 ui->textEditEtatConnexion->append(socketClientBanque->errorString());
 ui->groupBoxOperationBanque->setEnabled(false);
 ui->pushButtonConnexion->setText("Connexion");
}

void ClientMainWindow::onQtcpSocket_readyRead()
{
    quint16 taille=0;
    QString message;
    //si le nombre d'octers recu est au moin egal a celui de la taille de que l'on doit recevoir
    if(socketClientBanque->bytesAvailable()>=(quint64)sizeof (taille)){
        //association de la socket au flux d'entree
        QDataStream in(socketClientBanque);
        //extraire la taille de ce que l'on doit recevoir
        in >> taille;
        //si le nombre d'octets recu est au moin egal a celui  de ce que l'on foit recevoir
        if(socketClientBanque->bytesAvailable()>=(quint64)taille){
            //extraire le message de la banque et le mettre dans message
            in >> message;
        }
    }
    ui->lineEditMessageBanque->setText(message);
}
