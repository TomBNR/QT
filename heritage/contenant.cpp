#include "carton.h"
#include <iostream>

using namespace std;

Contenant::Contenant(const int _largeur, const int _hauteur, const int _profondeur):
largeur(_largeur),
hauteur(_hauteur),
profondeur(_profondeur)
{
    cout << "constructeur de la classe Contenant" << endl ;
}
Contenant::~Contenant(){

}

int Contenant::CalculerVolume()
{
    return largeur * hauteur * profondeur ;
}

