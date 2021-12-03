#include "menu.h"

using namespace std;

Menu::Menu(string &_nom):
    nom(_nom),
    longueurMax(0)
{

    // ouvrir le fichier
    ifstream fichierMenu(_nom.c_str());
    if (!fichierMenu.is_open()){                                                   // Si il y a une erreur
        cerr << "Erreur lors de l'ouverture du fichier" << endl;                   // alors Afficher un message indiquant une erreur de lecture
        nbOptions = 0;                                                             // et mettre nbOptions à 0
    }else{
        // Sinon calculer nbOptions, le nombre d’options dans le fichier
        nbOptions = static_cast<int>(count(istreambuf_iterator<char>(fichierMenu),istreambuf_iterator<char>(),'\n'));
        fichierMenu.seekg(0,ios::beg);
        // allouer dynamiquement le tableau options en fonction de nbOption
        option = new string [nbOptions];

        for(int indice=0; indice<nbOptions ; indice++){                               // Pour chaque option dans le fichier
            getline(fichierMenu,option[indice]);                                   // Lire l’option et l’affecter dans le tableau options
            if( option[indice].length() > longueurMax){                            // Si la taille de l’option est plus grande que longueurMax
                longueurMax = option[indice].length();                             // alors longueurMax reçoit la taille de l’option
            }
        }
    }
}

Menu::~Menu()
{
    delete [] option;
}

int Menu::Afficher()
{
    int choix;
    string nomDuFichier;
    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;
    Menu unMenu(nomDuFichier);
    cout << "+" << setfill('-') << setw(6) << "+" <<   setfill('-') << setw(longueurMax+2) << "+" << setfill(' ') << endl;
    for(int i=0;i<=nbOptions;i++){
        cout << "|" << setw(6) << right << nbOptions+1 << "|" <<   setfill('-') << setw(longueurMax) << "|"  << endl;
    }
    cout << "+" << setfill('-') << setw(6) << "+" <<   setfill('-') << setw(longueurMax+2) << "+" <<  setfill(' ') << endl;
    do{
        cout << "Votre choix : entre 1 et " << nbOptions << endl;
        if(!(cin >> choix)){
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            choix = -1;
        }

    }while( choix > (nbOptions));

    return choix;
}


void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin,uneChaine);
    cin.ignore( std::numeric_limits<streamsize>::max(), '\n' );
    system("clear");
}

Exception::Exception(int _code, string _message):
    code(_code),
    message(_message)
{}

int Exception::ObtenirCodeErreur() const
{
    return code;
}

string Exception::ObtenirMessage() const
{
    return message;
}
