#ifndef BARRE_H
#define BARRE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

class Barre
{
public:
    Barre();
    Barre(string _reference,int _longueur,float _densite,float _mVolumique,float _taille);
    virtual~Barre();
    virtual void AfficherCaracteristiques();
    virtual float CalculerMasse() {return 0;}

protected:
    //string ref;
    //string nom;
    float mVolumique;
    float taille;
    string reference;
    int longueur;
    float densite;
};

#endif // BARRE_H
