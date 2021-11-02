#include "Saisie.h"
#include <iostream>

using namespace std;

//enum { "+", "-", "*", "/"};

Saisie::Saisie()
{
    //ctor
}

Saisie::~Saisie()
{
    //dtor
}

void Saisie::saisir()
{
    string truc_saisie = "2";
	int i = 0;

    cout << endl << "**Veuillez entrer votre expression, nombre par nombre, operande par operande, en notation polonaise inversee**" << endl;
    cout << "Appuyer sur entree entre chaque saisi, entrez 'P' pour terminer" << endl;
    cout << endl <<" : " << endl;

	while (truc_saisie != "p")
	{
		cin >> truc_saisie;
		m_exp_str.push_back(truc_saisie);
	}

    //while(((m_exp_str[i] == "+") || (m_exp_str[i] == "-") || (m_exp_str[i] == "*") || (m_exp_str[i] == "/")) && (i < m_exp_str.size()))
    /*while((m_exp_str[i] == "+") || (m_exp_str[i] == "-"))
	{
        cout << "   l'element : "<< i <<"est : "<<m_exp_str[i]<<endl;
        i ++;
	}*/

	for(i = 0; i < m_exp_str.size(); i ++)
	{
        cout << "   l'element : "<< i <<"est : "<<m_exp_str[i]<<endl;
        if ((m_exp_str[i] == "+") || (m_exp_str[i] == "-"))
        {
            break;
        }
        if ((m_exp_str[i] == "*") || (m_exp_str[i] == "/"))
        {
            break;
        }
	}
	//cout << "le nombre de chiffre dans ton expression est : " << i << "le dernier chiffre est" << m_exp_str[i-1]<< endl;

    int taille_exp = m_exp_str.size();
	if((taille_exp-i != taille_exp/2) || (taille_exp%2 != 0))
	{
        cout << "Erreur dans l'expression, nombre d'operande ne correspond pas au nombre de constante" << endl;
	}

	int deb_operande = i;

	this->m_exp_saisi = new Constante(stof(m_exp_str[0]));
	//new Constante(4.4);

	for(i = deb_operande; i < taille_exp-1; i ++)
	{
        if (m_exp_str[i] == "+")
        {
            this->m_exp_saisi = new Addition(this->m_exp_saisi, new Constante(stof(m_exp_str[i-(taille_exp/2)])));
        }
        if (m_exp_str[i] == "-")
        {
            this->m_exp_saisi = new Soustraction(this->m_exp_saisi, new Constante(stof(m_exp_str[i-(taille_exp/2)])));
        }
        if (m_exp_str[i] == "*")
        {
            this->m_exp_saisi = new Multiplication(this->m_exp_saisi, new Constante(stof(m_exp_str[i-(taille_exp/2)])));
        }
        if (m_exp_str[i] == "/")
        {
            this->m_exp_saisi = new Division(this->m_exp_saisi, new Constante(stof(m_exp_str[i-(taille_exp/2)])));
        }
	}
}
