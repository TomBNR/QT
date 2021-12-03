#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QScriptEngine>
#include <QString>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
    int colonne = 0, ligne = 0;
    grille = new QGridLayout();
    afficheur = new QLineEdit();
    afficheur ->setReadOnly(true);
    afficheur ->setAlignment(Qt::AlignRight);
    grille->addWidget(afficheur,ligne,colonne,1,4);
    ligne = 3;

    for (int i = 0; i < 16; ++i) {
        touches[i] = new QPushButton();
        connect(touches[i],&QPushButton::clicked,this,&Calculatrice::onQPushButtonClicked);
        touches[i]->setText(tableDesSymboles[i]);
        if((i>0) && (i<10)){
            grille->addWidget(touches[i],ligne,colonne);
            colonne++;
            if(colonne==3){
                colonne=0;
                ligne--;
            }
        }
    }
    ligne = 4;

}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QPushButton *touches;
    touches = qobject_cast<QPushButton*>(sender());
    QString val=touches->text();
    if(val =="c"){
        afficheur->clear();
    }else{
        if(val == "="){
            QScriptEngine script;
            afficheur->setText(script.evaluate(afficheur->text()).toString());
        }
        afficheur->insert(val);
    }
}
