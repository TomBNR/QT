#include "segment.h"

using namespace std;
Segment::Segment(double _longueur, double _angle):
    longueur(_longueur),
    angle(_angle)
{
}

void Segment::afficher()
{

    cout << "SEGMENT L = " << longueur << "     A = " << angle << endl;
    cout << "SEGMENT L = " << longueur << "     A = " << angle << endl;
    cout << endl;

}


Segment::~Segment()
{

}
