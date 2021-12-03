#include "barrecarre.h"
#include <iostream>

using namespace std;


BarreCarre::BarreCarre(string _reference,int _longueur,float _densite,float _mVolumique,float _taille, int _cote):
    Barre(_reference,_longueur,_densite,_mVolumique,_taille),
    cote(_cote)
{
    cout << "Constructeur BarreCarre" << endl;
}

BarreCarre::~BarreCarre()
{
    cout << "Destructeur BarreCarre" << endl;
}

float BarreCarre::CalculerSection()
{
    return (longueur/1000) * (longueur/1000);
}

float BarreCarre::CalculerMasse()
{
    return (taille/1000) * BarreCarre::CalculerSection() * mVolumique;
}

void BarreCarre::afficher()
{
    cout << "Reférence : " << reference << endl << "Type : " << endl;
    cout << "Masse volumique : " << mVolumique << " Kg/m3" << endl;
    cout << "Longueur : " << taille/1000 << " m" << endl;
    cout << "coté du carré : " << cote << " cm" << endl;

}
