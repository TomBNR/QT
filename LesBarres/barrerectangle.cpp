#include "barrerectangle.h"
#include <iostream>

using namespace std;



BarreRectangle::BarreRectangle(string _ref,string _nom,const float _mVolumique , const float _taille ,const float _longueur,const float _largeur):
    Barre(_ref,_nom,_mVolumique,_taille),
    longueur(_longueur),
    largeur(_largeur)
{
    cout << "Constructeur BarreRectangle" << endl;
}

BarreRectangle::~BarreRectangle()
{
    cout << "Destructeur BarreRectangle" << endl;
}

float BarreRectangle::CalculerSection()
{
    return (largeur/1000) * (longueur/1000);
}

float BarreRectangle::CalculerMasse()
{
    return (taille/1000) * BarreRectangle::CalculerSection() * mVolumique;
}
