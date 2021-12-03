#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <stdio.h>

#include "menu.h"

Menu::~Menu()
{
    delete [] options;
}

Menu::Menu(const string &_nom):nom(_nom), longueurMax(0)
{
    // Si il y a une erreur
    // alors Afficher un message indiquant une erreur de lecture
    // et mettre nbOptions à 0
    // Sinon calculer nbOptions, le nombre d’options dans le fichier
    // allouer dynamiquement le tableau options en fonction de nbOptions
    // Pour chaque option dans le fichier
    // Lire l’option et l’affecter dans le tableau options
    // Si la taille de l’option est plus grande que longueurMax
    // alors longueurMax reçoit la taille de l’option
    //
    ifstream leFichier(_nom);
    if (!leFichier .is_open()){
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
        nbOptions = 0;
    }
    else{
        nbOptions = static_cast<int>(count(istreambuf_iterator<char>(leFichier),istreambuf_iterator<char>(),'\n'));
        leFichier.seekg(0,ios::beg);
        options = new string[nbOptions];
        for (int a = 0; a<nbOptions;a++){
            getline(leFichier,options[a]);
            if (options[a].length() > longueurMax)
                longueurMax = options[a].length();
        }
    }
}

int Menu::Afficher()
{
    int touche;
    cout << "+--+" << setfill('-')<< setw(longueurMax+4)<<"+"<< endl;
    for(int i = 0; i < nbOptions;i++){
        cout << setfill(' ') << "|"<<setw(2)<< i+1 <<"|"<<setw(longueurMax+3) <<options[i] << "|"<< endl;

    }
    cout << "+--+" << setfill('-')<< setw(longueurMax+4)<<"+"<< endl;
    cout << "Entrez un nombre entre 1 er 5 :";
    cin >> touche;
    return touche;
}


void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin,uneChaine);
    cin.ignore( std::numeric_limits<streamsize>::max(), '\n' );
    system("clear");
}

