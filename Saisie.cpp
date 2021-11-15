#include "../include/Saisie.h"
#include <iostream>
#include <fstream>
#include <string>

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

void Saisie::saisir(istream &is, ostream &os)
{
    string truc_saisie = "2";
    std::vector<std::string> exp_str;

    os << endl << "**Veuillez entrer votre expression, nombre par nombre, operande par operande, en notation polonaise inversee**" << endl;
    os << "Appuyer sur entree entre chaque saisi, entrez 'p' pour terminer" << endl;
    os << endl <<" : " << endl;


    while (truc_saisie != "p")
    {
        is >> truc_saisie;
        exp_str.push_back(truc_saisie);
    }

    this->vector_to_exp(exp_str, os);
}


void Saisie::vector_to_exp(vector<string> vector_str, ostream &os)
{
    int i = 0;

    /*for(i = 0; i < vector_str.size(); i ++)
    {
        cout << "   l'element : "<< i <<" est : "<<vector_str[i]<<endl;
    }*/
    for(i = 0; i < vector_str.size(); i ++)
    {
        if ((vector_str[i] == "+") || (vector_str[i] == "-"))
        {
            break;
        }
        if ((vector_str[i] == "*") || (vector_str[i] == "/"))
        {
            break;
        }
    }
    os << endl << "le nombre de chiffre dans ton expression est : " << i << " le dernier chiffre est : " << vector_str[i-1]<< endl;

    int taille_exp = vector_str.size();
    if((taille_exp-i != taille_exp/2) || (taille_exp%2 != 0))
    {
        cout << "Erreur dans l'expression, nombre d'operande ne correspond pas au nombre de constante" << endl;
    }

    int deb_operande = i;

    this->m_exp_saisi = new Constante(stof(vector_str[0]));
    //new Constante(4.4);

    for(i = deb_operande; i < taille_exp-1; i ++)
    {
        if (vector_str[i] == "+")
        {
            this->m_exp_saisi = new Addition(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
        }
        if (vector_str[i] == "-")
        {
            this->m_exp_saisi = new Soustraction(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
        }
        if (vector_str[i] == "*")
        {
            this->m_exp_saisi = new Multiplication(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
        }
        if (vector_str[i] == "/")
        {
            this->m_exp_saisi = new Division(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
        }
    }
}

Fichier_Report Saisie::sauvegarder(istream &is, ostream &os, std::string nom_de_fichier, Expression* exp_to_save)
{
	ofstream flux_fichier(nom_de_fichier.c_str());

	if(flux_fichier)
	{
		exp_to_save->afficherNPI(flux_fichier);
		exp_to_save->afficherNPI(os);

		flux_fichier.close();

		return FILE_OK;
	}

	else
	{
		return FILE_ERROR;
	}
}

Fichier_Report Saisie::sauvegarder(istream &is, ostream &os, std::string nom_de_fichier, Expression* exp_to_save)
{
	ofstream flux_fichier(nom_de_fichier.c_str());

	if(flux_fichier)
	{
		exp_to_save->afficherNPI(flux_fichier);
		exp_to_save->afficherNPI(os);

		flux_fichier.close();

		return FILE_OK;
	}

	else
	{
		return FILE_ERROR;
	}
}


Fichier_Report Saisie::charger(istream &is, ostream &os, std::string nom_de_fichier)
{
	ifstream flux_fichier(nom_de_fichier.c_str());

	string buffer;

	vector <string> gollum;

	gollum.push_back("");

	int i, j = 0;

	char character;

	if(flux_fichier)
	{
		getline(flux_fichier, buffer);

		for(i = 0; i < buffer.length(); i++)
		{
			//character = buffer.at(i);

			character = buffer[i];

			if(character == ' ')
			{
				gollum.push_back("");
				j++;
			}

			else
			{
				gollum[j].push_back(character);
			}
		}

		flux_fichier.close();

		this->vector_to_exp(gollum, os);

		return FILE_OK;
	}

	else
	{
		return FILE_ERROR;
	}
}
