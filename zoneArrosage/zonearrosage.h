#ifndef ZONEARROSAGE_H
#define ZONEARROSAGE_H
#include "vanne.h"
#include <string>
#include "capteurhumidite.h"
using namespace std;
/*class ZoneArrosage
{
private:
    Vanne laVanne;
    int numZone;
public:
    ZoneArrosage(int _numZone,
                 const gpio_num_t _commandeVanne,
                 const gpio_num_t _senseAVanne,
                 const gpio_num_t _senseBVanne,
                 const gpio_num_t _brocheHumidite);
    void Piloter();
};*/

class ZoneArrosage
{
private:
    Vanne *laVanne;
    int numZone;
    CapteurHumidite *leCapteur;
public:
    ZoneArrosage(const string _initialisationZone);
    ~ZoneArrosage();
    void Piloter();
};
#endif // ZONEARROSAGE_H
