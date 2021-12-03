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
    Barre(string _ref,string _nom,float _mVolumique,float _taille);
    ~Barre();

    void AfficherCaracteristiques();

protected:
    string ref;
    string nom;
    float mVolumique;
    float taille;
};

#endif // BARRE_H
