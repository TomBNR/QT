#ifndef CAPTEURHUMIDITE_H
#define CAPTEURHUMIDITE_H
#define gpio_num_t  int
#include<iostream>
using namespace std;
class CapteurHumidite
{
private:
   gpio_num_t brocheCapteur;
public:
    CapteurHumidite(const gpio_num_t _brocheCapteur);
    int MesurerHumiditeDuSol();
};

#endif // CAPTEURHUMIDITE_H
