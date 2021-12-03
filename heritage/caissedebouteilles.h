#ifndef CAISSEDEBOUTEILLES_H
#define CAISSEDEBOUTEILLES_H
#include "contenant.h"

class CaisseDeBouteilles : public Contenant
{
public:
    CaisseDeBouteilles(const int in_largeur, const int in_hauteur, const int in_profondeur, const int nbBouteilles, const int contenance);
    int CalculerVolume();
    ~CaisseDeBouteilles();
private:
    int nbBouteilles;
    int contenance;
};
#endif // CAISSEDEBOUTEILLES_H
