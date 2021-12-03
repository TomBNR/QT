#ifndef INTERFACEACCESBDBANQUE_H
#define INTERFACEACCESBDBANQUE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>

class InterfaceAccesBDBanque
{
private:
    QSqlDatabase bdd;
public:
    InterfaceAccesBDBanque(QString hote,QString bd,QString login,QString mdp);
    float ObtenirSolde(int numCompte);
    void MettreAJourLeSolde(int numCompte,float nouveauSolde);
    void CreerCompte(int numCompte);
    bool CompteExiste(int numCompte);

};

#endif // INTERFACEACCESBDBANQUE_H
