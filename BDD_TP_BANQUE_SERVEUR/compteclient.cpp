#include "compteclient.h"
InterfaceAccesBDBanque CompteClient::bc("172.18.58.14","banque","snir","snir");

CompteClient::CompteClient(QObject *parent):QTcpSocket(parent)
{
    //    *parent = nullptr;
    solde =0;
    //  numCompte = 1234;

}

bool CompteClient::Retirer(float montant)
{
    bool x;
    int y = solde;
    solde = solde - montant;

    if (solde < 0 ){
        solde = y;
        x =false;
    } else{

        x= true;
    }
    return  x;
}

void CompteClient::Deposer(float montant)
{
   bc.MettreAJourLeSolde(numCompte, montant);
}

float CompteClient::ObtenirSolde()
{
    return bc.ObtenirSolde(numCompte);
}

void CompteClient::DefinirNumcompte(int nc)
{
    numCompte = nc;
    qDebug()<<"numero de compte DefinirNumcompt "<<nc;
    bc.CreerCompte(nc);
}

int CompteClient::ObtenirNumCompte()
{
    return numCompte;
}
