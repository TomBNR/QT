#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Element
{
public:
    Element();
    virtual ~Element();
    virtual void afficher();
};

#endif // ELEMENT_H
