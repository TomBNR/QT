#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class CompteBancaire
{
public:
    CompteBancaire(float _solde);
    void Deposer(float _montant);
    void Retirer(float _montant);
    float ConsulterSolde();
    ~CompteBancaire();

protected:
    float solde;
};


#endif // COMPTEBANCAIRE_H
