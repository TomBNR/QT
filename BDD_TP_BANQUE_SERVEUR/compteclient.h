#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include <QTcpSocket>
#include <interfaceaccesbdbanque.h>

class CompteClient : public QTcpSocket
{
private :
    int numCompte;
    float solde;
public:
    static InterfaceAccesBDBanque bc;
    CompteClient(QObject* parent=nullptr);
    bool Retirer(float montant);
    void Deposer(float montant);
    float ObtenirSolde();
    void DefinirNumcompte(int nc);
    int ObtenirNumCompte();
};

#endif // COMPTECLIENT_H
