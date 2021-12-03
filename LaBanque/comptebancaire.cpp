#include "comptebancaire.h"
#include <iostream>

using namespace std;


CompteBancaire::CompteBancaire(float _solde):
    solde(_solde)
{

;}

CompteBancaire::~CompteBancaire(){

}

void CompteBancaire::Deposer(float _montant){
    cout << "compte crédité de : " << _montant << "€" << endl;
    solde = solde + _montant;;
}
void CompteBancaire::Retirer(float _montant){

    cout << "compte débité de : " << _montant << "€" << endl;
    solde = solde - _montant;
}

float CompteBancaire::ConsulterSolde(){
    return solde;
}
