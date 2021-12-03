#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
    int choix;
    Menu leMenu("/home/USERS/ELEVES/SNIR2020/tbernier/Documents/Snir2/Qt/menu/menu.txt");

    do
    {
        choix = leMenu.Afficher();
        switch (choix)
        {
        case OPTION_1:
            cout << "Vous avez choisi l'option n°1" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_2:
            cout << "Vous avez choisi l'option n°2" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_3:
            cout << "Vous avez choisi l'option n°3" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_4:
            cout << "Vous avez choisi l'option n°4" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case QUITTER:
            cout << "Vous avez choisi l'option n°5 qui est de quitter" << endl;
            break;
        }
    } while(choix != QUITTER);

    return 0;
}
