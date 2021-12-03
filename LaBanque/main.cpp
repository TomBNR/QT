#include <iostream>
#include "menu.h"
#include "comptebancaire.h"

using namespace std;

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2 = 2,
    OPTION_3 = 3,
    QUITTER = 4,
};

int main()
{
try{

        int choix;
        int montant;
        CompteBancaire monCompte(50);
        Menu leMenu("/home/USERS/ELEVES/SNIR2020/tbernier/Documents/Snir2/Qt/LaBanque/compteBancaire.txt");

        do {
            choix = leMenu.Afficher();
            switch (choix)
            {
            case OPTION_1:
                cout << "Consultation du solde" << endl;
                leMenu.AttendreAppuiTouche();
                break;
            case OPTION_2:
                cout << "Combien souhaitez-vous déposer : ";
                cin >> montant;
                monCompte.Deposer(montant);
                cout << endl;
                break;
            case OPTION_3:
                cout << "Combien souhaitez-vous retirer : ";
                cin >> montant;
                monCompte.Retirer(montant);
                cout <<endl;
                break;
            }

        }while(choix != QUITTER);

} catch (Exception erreur) {
    erreur.ObtenirMessage();
    erreur.ObtenirCodeErreur();
    exit(EXIT_FAILURE);
}
    return 0;
}
