#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase bd;
    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName("172.18.58.7");
    bd.setDatabaseName("france2018");
    bd.setUserName("snir");
    bd.setPassword("snir");
    if (!bd.open())
    {
        qDebug()<<"pb acces bd "<<bd.lastError();
    }
    else
    {
        qDebug()<<"acces bd ok";
    }

    QSqlQuery requete1("select code, name from regions order by name;" );
        if (!requete1.exec()){
            qDebug()<<"pb requete "<<requete1.lastError();
        }
        QString nom;
        QString id;

        while(requete1.next())
        {
            nom=requete1.value("name").toString();
            id=requete1.value("code").toString();
            ui->comboBoxRegions->addItem(nom,id);
        }

     QSqlQuery requete2("select departement_nom from departements;" );
     if (!requete2.exec()){
         qDebug()<<"pb requete "<<requete2.lastError();
     }

     int nbLignes=requete2.size();
     qDebug()<<"nombre departements  : "<<nbLignes;
     QString nomDepartement;
     while(requete2.next())
     {
         nomDepartement=requete2.value("departement_nom").toString();
         qDebug()<<nomDepartement;
     }
}


Widget::~Widget()
{
    delete ui;
}

