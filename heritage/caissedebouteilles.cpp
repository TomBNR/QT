#include "caissedebouteilles.h"
#include <iostream>

using namespace std;


CaisseDeBouteilles::CaisseDeBouteilles(const int in_largeur, const int in_hauteur, const int in_profondeur, const int in_nbBouteilles, const int in_contenance):

    Contenant(in_largeur, in_hauteur, in_profondeur),
    nbBouteilles(in_nbBouteilles),
    contenance(in_contenance)
{
    cout<<"constructeur de CaissedeBouteille"<<endl;

}

    CaisseDeBouteilles::~CaisseDeBouteilles()
    {
        cout<<"destructeur de CaisseDeBouteille"<<endl;
    }

