#include "zonearrosage.h"
#include "capteurhumidite.h"

/*ZoneArrosage::ZoneArrosage(const int _numZone, const int _commandeVanne, const int _senseAVanne,
     const  int _senseBVanne, const int _brocheHumidite):
    laVanne(_commandeVanne,_senseAVanne,_senseBVanne),
    numZone(_numZone)//,
    //leCapteurHumidite(_brocheHumidite)
{
    // reste du code pour le constructeur
}*/

ZoneArrosage::ZoneArrosage(const string _initialisationZone)
{
    int parametres[5];
    size_t prec = 0;
    size_t pos = 0;
    for (int indice = 0;indice < 5;indice++)
    {
        pos = _initialisationZone.find(' ',prec);
        parametres[indice] = atoi(_initialisationZone.substr(prec,pos).c_str());
        prec = pos + 1; // on incrémente pos pour le tour d'après.
    }
    numZone = parametres[0];
    laVanne = new Vanne(parametres[1],parametres[2],parametres[3]);
    leCapteur = new CapteurHumidite(parametres[4]);
    cout << "Objet zone arrosage"<<endl;
    cout <<" Impulsion : "<< parametres[1] <<" sensA : "<<parametres[2]<<" sensB : "<<parametres[3]<<" broche : "<<parametres[4]<<endl;
}


ZoneArrosage::~ZoneArrosage()
{
    delete laVanne;
    delete leCapteur;
}
