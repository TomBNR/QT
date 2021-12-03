#include "barrecarree.h"
#include <iostream>

using namespace std;


BarreCarree::BarreCarree(string _ref,string _nom,const float _mVolumique , const float _taille ,const float _longueur):
    Barre(_ref,_nom,_mVolumique,_taille),
    longueur(_longueur)
{
    cout << "Constructeur BarreCarre" << endl;
}

BarreCarree::~BarreCarree()
{
    cout << "Destructeur BarreCarre" << endl;
}

float BarreCarree::CalculerSection()
{
    return (longueur/1000) * (longueur/1000);
}

float BarreCarree::CalculerMasse()
{
    return (taille/1000) * BarreCarree::CalculerSection() * mVolumique;
}
