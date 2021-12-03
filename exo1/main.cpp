#include <iostream> // pour cout
#include <fstream>
#include <iomanip>
using namespace std; //évite d'écrire std::cout

int main()
{
    string motCle;
    int valeur1;
    int valeur2;
    int valeur3;

    fstream fichier("config.txt", fstream::in | fstream::out);
    if (!fichier.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else
    {
        do
                {
                    // le fichier contient sur chaque ligne des couples mot clé + valeur
                    fichier >> motCle >> valeur1 >> valeur2 >> valeur3 ;
                    if (fichier.good())//Si les valeurs ont bien été lues
                    {

                        cout <<  '+' << setw(5) << setfill('-') << '+' ;

                    }
                } while(!fichier.eof());
    }
}
