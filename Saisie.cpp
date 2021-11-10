#include "Saisie.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

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

    int taille_exp = vector_str.size();
	if((taille_exp-i != taille_exp/2) || (taille_exp%2 != 0))
	{
        os << "Erreur dans l'expression, nombre d'operande ne correspond pas au nombre de constante" << endl;
	}

	int deb_operande = i;

	this->m_exp_saisi = new Constante(stof(vector_str[0]));

	for(i = deb_operande; i < taille_exp-1; i ++)
	{
        if (vector_str[i] == "+")
        {
            if((vector_str[i-(taille_exp/2)+1].length() == 1) && !(isdigit(vector_str[i-(taille_exp/2)+1][0])))
            {
                this->m_exp_saisi = new Addition(this->m_exp_saisi, new Variable(vector_str[i-(taille_exp/2)+1][0]));
            }
            else
            {
                this->m_exp_saisi = new Addition(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
            }
        }
        if (vector_str[i] == "-")
        {
            if((vector_str[i-(taille_exp/2)+1].length() == 1) && !(isdigit(vector_str[i-(taille_exp/2)+1][0])))
            {
                this->m_exp_saisi = new Soustraction(this->m_exp_saisi, new Variable(vector_str[i-(taille_exp/2)+1][0]));
            }
            else
            {
                this->m_exp_saisi = new Soustraction(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
            }
        }
        if (vector_str[i] == "*")
        {
            if((vector_str[i-(taille_exp/2)+1].length() == 1) && !(isdigit(vector_str[i-(taille_exp/2)+1][0])))
            {
                this->m_exp_saisi = new Multiplication(this->m_exp_saisi, new Variable(vector_str[i-(taille_exp/2)+1][0]));
            }
            else
            {
                this->m_exp_saisi = new Multiplication(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
            }
        }
        if (vector_str[i] == "/")
        {
            if((vector_str[i-(taille_exp/2)+1].length() == 1) && !(isdigit(vector_str[i-(taille_exp/2)+1][0])))
            {
                this->m_exp_saisi = new Division(this->m_exp_saisi, new Variable(vector_str[i-(taille_exp/2)+1][0]));
            }
            else
            {
                this->m_exp_saisi = new Division(this->m_exp_saisi, new Constante(stof(vector_str[i-(taille_exp/2)+1])));
            }
        }
	}
}
