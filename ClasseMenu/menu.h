#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Menu
{
private:
    string nom;
    string * options;
    int nbOptions;
    unsigned int longueurMax;
public:
    ~Menu();
    Menu (const string &_nom);
    static void AttendreAppuiTouche();
    int Afficher();
};

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    QUITTER
};

#endif // MENU_H
