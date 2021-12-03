#include "compteclient.h"


CompteClient::CompteClient(QObject *parent):QTcpSocket(parent)
{
    solde = 0;
}



bool CompteClient::Retirer(float montant)
{
    bool ret=false;
    if(montant>0)
    {
        if(solde>=montant)
        {
            solde=solde-montant;
            ret=true;
        }
    }
    return ret;
}

void CompteClient::Deposer(float montant)
{
    if(montant>0){
        solde = solde + montant;
    }

}

float CompteClient::ObtenirSolde()
{
    return solde;
}

void CompteClient::DefinirNumCompte(int nc)
{
    solde = 200;
    numCompte = nc;
}

int CompteClient::ObtenirNumCompte()
{
    return numCompte;
}
