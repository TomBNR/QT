#include "barre.h"
#include <iostream>

using namespace std;


Barre::Barre(string _reference,int _longueur,float _densite,float _mVolumique,float _taille):
    reference(_reference),longueur(_longueur),densite(_densite),mVolumique(_mVolumique),taille(_taille)
{
    cout << "Constructeur de la classe Barre" << endl;
}

Barre::~Barre()
{
    cout << "Destructeur de la classe Barre" << endl;
}

void Barre::AfficherCaracteristiques()
{
    cout << "Reférence : " << reference << endl << "Type : " << endl;
    cout << "Masse volumique : " << mVolumique << " Kg/m3" << endl;
    cout << "Longueur : " << taille/1000 << " m" << endl;
}
