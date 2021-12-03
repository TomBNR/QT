#include "dietetique.h"
#include "ui_dietetique.h"

dietetique::dietetique(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dietetique)
{
    ui->setupUi(this);
}

dietetique::~dietetique()
{
    delete ui;
}

void dietetique::afficherInfos()
{
    double imcs[NBIMC] = {16.5, 18.5, 25, 30, 35, 40};
    QString corpulences [NBCORPULENCE] = {"Famine", "Maigreur", "Normale", "Surpoids",
                                          "Obésité modérée", "Obésité sévère", "Obésité morbide"};
    double imc=0;
    // initialisation de poids, taille, âge, nom et prenom
        nom = ui->lineEditNom->text();
        prenom = ui->lineEditPrenom->text();
        age = ui->spinBoxAge->value();
        poids = ui->doubleSpinBoxPoids->value();
        taille = ui->doubleSpinBox_Taille->value();
        // affichage message de bienvenue
        ui->textEditAfficheur->append("Bonjour\n");
        // calcul de l'imc
            imc = poids/(taille*taille);
        // affichage de l'imc
            ui->textEditAfficheur->append("Votre indice de masse corporel est de : "+QString::number(imc));
                int indiceCorpulence = 0;
                for (int i = 0; i < NBIMC - 1; i++) {
                    if (imc > imcs[i] && imc <= imcs[i + 1]) {
                        indiceCorpulence = i + 1;
                    }
                }
                // cas extreme
                if (imc < 16.5) {
                    indiceCorpulence = 0;
                }
                if (imc > 40) {
                   indiceCorpulence = NBCORPULENCE - 1;
                }
                // affichage de la corpulence: corpulences[indiceCorpulence]
                 ui->textEditAfficheur->append("\nVotre corpulence est qualifiée de "+corpulences[indiceCorpulence]);

}
