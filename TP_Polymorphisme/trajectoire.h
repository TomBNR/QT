#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include "element.h"
using namespace std;

class Trajectoire : public Element
{
private:
    int nbEtapesMax;
    int prochaineEtape;
public:
    Trajectoire(int _nbEtapesMaxi);
    ~Trajectoire();
    bool Ajouter(Element *_pElement);
    void afficher();
};

#endif // TRAJECTOIRE_H
