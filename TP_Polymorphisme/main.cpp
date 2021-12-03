#include <iostream>
#include "element.h"
#include "segment.h"
#include "trajectoire.h"

using namespace std;

int main()
{
    Trajectoire traj(1);
    Segment seg(9,0);
    Segment seg1(5,0.927295);
    traj.afficher();
    cout << endl;
    seg.afficher();
    cout << endl;
    cout << endl;

    return 0;
}
