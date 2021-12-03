
#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include "qtcpsocket.h"

class CompteClient : public QTcpSocket
{
public:
    CompteClient(QObject *parent = nullptr);
    bool Retirer(float montant);
    void Deposer(float montant);
    float ObtenirSolde();
    void DefinirNumCompte(int nc);
    int ObtenirNumCompte();

private:
    int numCompte;
    float solde;

};

#endif // COMPTECLIENT_H

