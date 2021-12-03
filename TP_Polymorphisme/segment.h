#ifndef SEGMENT_H
#define SEGMENT_H

#include "element.h"

class Segment : public Element
{
private:
    double longueur;
    double angle;
public:
    Segment(double _longueur, double _angle);
    ~Segment();
    void afficher();
};

#endif // SEGMENT_H
