#include <iostream>
#include "Saisie.h"

using namespace std;

int main()
{
    int choix2;
	int thend = 0;
	Saisie la_saisie;

    cout << "\n\n***Bienvenue sur Expression project le programme calculatrice du futur***\n\n";

	while(thend!=1)
	{
        if(la_saisie.GetExpSaisie() == NULL)
        {
            cout << "Aucune expression n'a encore été saisie, veuillez en saisir une" << endl << endl;
        }
        else
        {
            cout << "L'Expression actuellement saisie est : " << endl;

            la_saisie.GetExpSaisie()->afficher(cout << endl << "L'Expression actuellement saisie est : " << endl);
            cout << " = " << la_saisie.GetExpSaisie()->calculer() << endl;
            cout << endl;
        }

        int choix2;
        cout << "Voulez vous :\n\n";

        cout << "	0 - Quitter.\n";
        cout << "	1 - Saisir une expression\n";
        cout << "	2 - Enregistrer l'expression\n";
        cout << "	3 - Sauvegarder l'expression\n";
        cout << "	4 - Regarder un clip de JuL\n";

        cout << "\n";
        cin >> choix2;

        //while (getchar () != '\n');

		switch(choix2)
		{
			case 1:
			{
                la_saisie.saisir();
				break;
			}

			case 2:
			{

				break;
			}

			case 3:
			{

				break;
			}

			case 4:
			{

				break;
			}

			case 0:
			{
                thend = 1;
				break;
			}

			default :
			{

				break;
			}
		}
    }

    return 0;
}
