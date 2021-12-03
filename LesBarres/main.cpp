#include <iostream>
#include "barre.h"
#include "barrecarree.h"
#include "barrerectangle.h"

using namespace std;

int main()
{
    Barre b1("145","acier",7850,1000);
    cout << endl;
    b1.AfficherCaracteristiques();
    cout << endl;
    cout << endl;
    BarreCarree barreCarre("145","acier",7850,1000,10);
    cout << "Section carre : " << barreCarre.CalculerSection()*1000000<< " mm2" << endl;
    cout << "Masse de la barre : " << barreCarre.CalculerMasse() << "Kg" << endl;
    cout << endl;
    BarreRectangle barrerectangle("145","aluminium",785,100,40,50);
    cout << "Section rectangle : " << barrerectangle.CalculerSection()*1000000 << " mm2" << endl;
    cout << "Masse de la barre : " << barrerectangle.CalculerMasse() << "Kg" << endl;
    cout << endl;
    cout << endl;
}
