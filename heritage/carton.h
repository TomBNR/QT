#ifndef CARTON_H
#define CARTON_H
#include "contenant.h"
class Carton : public Contenant
{
public:
    Carton(const int in_largeur, const int in_hauteur, const int in_profondeur, const float in_poidsMaxi);
    float ObtenirPoidsMaxi();
    ~Carton();
private:
    float poidsMaxi;
};

#endif // CARTON_H
