#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    socketDeDialogueAvecServeur=new QTcpSocket();
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::connected,this,&ClientWidget::onQTcpSocket_connected);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::disconnected,this,&ClientWidget::onQTcpSocket_disconnected);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::hostFound,this,&ClientWidget::onQTcpSocket_hostFound);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::bytesWritten,this,&ClientWidget::onQTcpSocket_bytesWritten);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::readyRead,this,&ClientWidget::onQTcpSocket_readyRead);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::aboutToClose,this,&ClientWidget::onQTcpSocket_aboutToClose);
    connect(socketDeDialogueAvecServeur,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&ClientWidget::onQTcpSocket_error);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::stateChanged,this,&ClientWidget::onQTcpSocket_stateChanged);
    QObject::connect(socketDeDialogueAvecServeur,&QTcpSocket::readChannelFinished,this,&ClientWidget::onQTcpSocket_readChannelFinished);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}


void ClientWidget::on_pushButtonConnexion_clicked()
{
    socketDeDialogueAvecServeur->connectToHost(ui->lineEditAdresseIPServeur->text(),ui->lineEditPort->text().toInt());
}

void ClientWidget::on_pushButtonNomOrdinateur_clicked()
{
    typeDeDemande="c";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonNomUtilisateur_clicked()
{
    typeDeDemande="u";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonArchitectureProcesseur_clicked()
{
    typeDeDemande="a";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonOSOrdinateur_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::onQTcpSocket_connected()
{
    ui->textEditEtat->append("Connecté au serveur");
}

void ClientWidget::onQTcpSocket_disconnected()
{
    ui->textEditEtat->append("Déconnecté du serveur");
}

void ClientWidget::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
    ui->textEditEtat->append(socketDeDialogueAvecServeur->errorString());
}
void ClientWidget::onQTcpSocket_hostFound()
{

}

void ClientWidget::onQTcpSocket_stateChanged(QAbstractSocket::SocketState socketState)
{
    QString etat;
    switch (socketState) {
    case QAbstractSocket::UnconnectedState: etat="The socket isn't connected.";break;

    }
}

void ClientWidget::onQTcpSocket_aboutToClose()
{

}

void ClientWidget::onQTcpSocket_bytesWritten(qint64 bytes)
{

}

void ClientWidget::onQTcpSocket_readChannelFinished()
{

}

void ClientWidget::onQTcpSocket_readyRead()
{
    QByteArray buffer;
    if (socketDeDialogueAvecServeur->bytesAvailable()> 0) {
        buffer = socketDeDialogueAvecServeur->readAll();
    }
    if (typeDeDemande=="u") {
        ui->lineEditNomUtilisateur->setText(buffer.data()); // QString::fromUtf8(buffer.data())
    }
    if (typeDeDemande=="c") {
        ui->lineEditNomOrdinateur->setText(buffer.data()); // QString::fromUtf8(buffer.data())
    }
    if (typeDeDemande=="o") {
        ui->lineEditOSOrdinateur->setText(buffer.data()); // QString::fromUtf8(buffer.data())
    }
    if (typeDeDemande=="a") {
        ui->lineEditArchitectureProcesseur->setText(buffer.data()); // QString::fromUtf8(buffer.data())
    }





}
