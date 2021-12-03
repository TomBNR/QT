#include <iostream>
#include "barrecarre.h"
using namespace  std;
int main(int argc, char *argv[])
{
    BarreCarre uneBarre("Barre 2x2 en Cuivre", 200, 8.920, 2,50,40);
    uneBarre.afficher();
    cout << "Le poids de la barre est : " ;
    cout << uneBarre.CalculerMasse() / 1000.0;
    cout << " kg" << endl;
    cout << endl;
    return 0;
}
