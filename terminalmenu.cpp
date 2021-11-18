#include "terminalmenu.h"

TerminalMenu::TerminalMenu()
{

}

int TerminalMenu::main_boucle()
{
    int choix2 = 1;
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
            la_saisie.GetExpSaisie()->afficher(cout << endl << "L'Expression actuellement saisie est : " << endl);
            //cout << " = " << la_saisie.GetExpSaisie()->calculer() << endl;
            cout << endl;
        }

        int choix2;
        cout << "Voulez vous :\n\n";

        cout << "	0 - Quitter.\n";
        cout << "	1 - Saisir une expression\n";
        cout << "	2 - Lire une expression depuis un fichier\n";
        if(la_saisie.GetExpSaisie() != NULL)
        {
            cout << "	3 - Sauvegarder l'expression\n";
            cout << "	4 - Faire le calcul de l'expression\n";
            cout << "	5 - Afficher l'expression en notation classique\n";
            cout << "	6 - Afficher l'expression en notation polonaise inversee\n";
            cout << "	7 - Simplifier l'expression\n";
            cout << "	8 - Afficher le graphique 2D\n";
        }

        cout << "\n";
        cin >> choix2;

        //while (getchar () != '\n');

        switch(choix2)
        {
            case 1:
            {
                la_saisie.saisir(cin, cout << "");
                break;
            }

            case 2:
            {
                if(la_saisie.charger(cin, cout, "sauvegarde.txt") != FILE_OK);
                {
                    cout << "Erreur a l'ouverture de la sauvegarde" << endl;
                }
                break;
            }

            case 3:
            {
                if(la_saisie.sauvegarder(cin, cout, "sauvegarde.txt", la_saisie.GetExpSaisie()) != FILE_OK);
                {
                    cout << "Erreur a l'ouverture de la sauvegarde" << endl;
                }
                break;
            }

            case 4:
            {
                cout << "    Calcul de l'expression : " << endl << "        ";
                la_saisie.GetExpSaisie()->afficher(cout << "");
                cout << " = " << la_saisie.GetExpSaisie()->calculer() << endl;
                cout << endl;
                break;
            }

            case 5:
            {
                cout << "    Expression en notation classique : " << endl << "        ";
                la_saisie.GetExpSaisie()->afficher(cout << "");
                cout << endl;
                break;
            }

            case 6:
            {
                cout << "    Expression en notation polonaise inversee : " << endl << "        ";
                la_saisie.GetExpSaisie()->afficherNPI(cout << "");
                cout << endl;
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
