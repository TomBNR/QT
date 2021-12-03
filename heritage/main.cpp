#include <iostream>
#include "carton.h"
#include "contenant.h"
#include "caissedebouteilles.h"

using namespace std;

int main()
{
 cout<<"Heritage"<<endl;
 Contenant c1(10,20,20);
 cout <<"Volume de c1 :" << c1.CalculerVolume() << endl;


 CaisseDeBouteilles c2(6,75,10,20,20);
 cout <<"Volume de c2 :" << c2.CalculerVolume() << endl;

}
