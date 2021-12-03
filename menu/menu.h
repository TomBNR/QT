#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Menu
{
private:
    string nom;
    string * option;
    int nbOptions;
    unsigned int longueurMax;

public:
    Menu(string &_nom);
    ~Menu();

    int Afficher();
    void AttendreAppuiTouche();

};

class Exception
{
public:
    Exception(int _code,string _message);
    int ObtenirCodeErreur() const;
    string ObtenirMessage() const;
private:
    int code;
    string message;

};

#endif // MENU_H
