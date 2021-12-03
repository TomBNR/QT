#ifndef BARRECARRE_H
#define BARRECARRE_H

#include "barre.h"

class BarreCarre : public Barre
{
public:
    BarreCarre(string _reference,int _longueur,float _densite,float _mVolumique,float _taille,int _cote);
    ~BarreCarre();

    float CalculerSection();
    float CalculerMasse();
    void afficher();
private:
    int cote;
};

#endif // BARRECARRE_H
