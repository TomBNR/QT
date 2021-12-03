#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->groupBoxConnexion_infoComptes->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;

}


void Widget::on_pushButton_clicked() //Connexion
{
    QSqlDatabase bdd;
    bdd=QSqlDatabase::addDatabase("QMYSQL");

    bdd.setHostName(ui->lineEdit_IP->text());
    bdd.setDatabaseName(ui->lineEdit_nomBdd->text());
    bdd.setUserName(ui->lineEdit_login->text());
    bdd.setPassword(ui->lineEdit_mdp->text());

    if(!bdd.open()){

        QMessageBox msg;
        msg.setText(bdd.lastError().text());
        msg.exec();
    }
    else
    {
        qDebug()<<"acces bdd";
        ui->groupBoxConnexion_infoComptes->setEnabled(true);
        ui->groupBoxConnexion->setEnabled(false);
    }

}

void Widget::on_pushButton_infosCompte_clicked()
{
    QString nom ,prenom,solde,idCompte;

    QSqlQuery requete("select solde, nom, prenom, idCompte from comptes");
    while(requete.next()){


        solde = requete.value("solde").toString();
        prenom = requete.value("prenom").toString();
        nom = requete.value("nom").toString();
        idCompte = requete.value("idCompte").toString();
        // ajouter une ligne au tableau
          ui->tableWidgetInfos->insertRow(ui->tableWidgetInfos->rowCount());
          int ligne=0;    // numero de la ligne
          int col=0;      // numero de la colonne
          // ajouter un nom
          QTableWidgetItem *nomItem = new QTableWidgetItem("bidochon");
          ui->tableWidgetInfos->setItem(ligne,col,nomItem);
          col++;
          // ajouter un prenom
          QTableWidgetItem *prenomItem = new QTableWidgetItem("robert");
          ui->tableWidgetInfos->setItem(ligne,col,prenomItem);
          col++;
          // ajouter le numero de compte
          QTableWidgetItem *idCompteItem = new QTableWidgetItem(QString::number(1234));
          ui->tableWidgetInfos->setItem(ligne,col,idCompteItem);
          col++;
          // ajouter le solde
          QTableWidgetItem *soldeItem = new QTableWidgetItem(QString::number(518.68));
          ui->tableWidgetInfos->setItem(ligne,col,soldeItem);

}
}
