#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    //connect(socketDeDialogueAvecServeur,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&ClientWidget::onQTcpSocket_error);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}


void ClientWidget::on_pushButtonConnexion_clicked()
{

}

void ClientWidget::on_pushButtonOrdinateur_clicked()
{
    typeDeDemande="c";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonUtilisateur_clicked()
{
    typeDeDemande="u";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonArchitecture_clicked()
{
    typeDeDemande="a";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonOs_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void ClientWidget::onQTcpSocket_connected()
{
    socketDeDialogueAvecServeur = new QTcpSocket;
}

void ClientWidget::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
    ui->textEdit->append(socketDeDialogueAvecServeur->errorString());
}
