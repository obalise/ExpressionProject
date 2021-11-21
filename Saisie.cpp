/************************
 * classe Saisie, par groupe 1 (Mathieu + Thomas)
 * Methode saisie.sauvegarder et saisie.charger, par groupe 2 (Remi + Anakin)
 * *********************/

#include "../include/Saisie.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_digits(const std::string &str) //outils, interne a saisie.cpp, permet de verifier si un string est un nombre
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}


Saisie::Saisie()
{
    //ctor
}

Saisie::~Saisie()
{
    //dtor
}

void Saisie::saisir(istream &is, ostream &os) //Demande a l'utilisateur d'entree son expression, Constante par Constante, Operande par Operande en NPI, Les stoque dans un vector de string puis appelle vector_to_exp
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


void Saisie::vector_to_exp(vector<string> vector_str, ostream &os)  //Convertir un vector de string en expression
{
    int i = 0;
    stack<Expression *> pile; //On cree une pile d'expression


    for(i = 0; i < vector_str.size()-1; i++)
    {
        if(is_digits(vector_str[i])) //si le string est un nombre
        {
            pile.push(new Constante(stof(vector_str[i]))); //ajoute dans la pile une constante
        }
        else if(vector_str[i] == "+") //si le string est un "+"
        {
            if(pile.size()<2) //On verifie qu'il y ai au moins deux constante/variable/expression deja dans la pile
            {
                os << "Vous avez mal saisi votre expression" << endl;
            }
            else
            {
                Expression* moins_un = pile.top();
                pile.pop();
                Expression* moins_deux = pile.top();
                pile.pop(); //on supprime les deux expression precedante de la pile
                pile.push(new Addition(moins_deux, moins_un)); //on les remplace par une operation entre ces deux expression
            }
        }
        else if(vector_str[i] == "-")
        {
            if(pile.size()<2)
            {
                os << "Vous avez mal saisi votre expression" << endl;
            }
            else
            {
                Expression* moins_un = pile.top();
                pile.pop();
                Expression* moins_deux = pile.top();
                pile.pop();
                pile.push(new Soustraction(moins_deux, moins_un));
            }
        }
        else if(vector_str[i] == "*")
        {
            if(pile.size()<2)
            {
                os << "Vous avez mal saisi votre expression" << endl;
            }
            else
            {
                Expression* moins_un = pile.top();
                pile.pop();
                Expression* moins_deux = pile.top();
                pile.pop();
                pile.push(new Multiplication(moins_deux, moins_un));
            }
        }
        else if(vector_str[i] == "/")
        {
            if(pile.size()<2)
            {
                os << "Vous avez mal saisi votre expression" << endl;
            }
            else
            {
                Expression* moins_un = pile.top();
                pile.pop();
                Expression* moins_deux = pile.top();
                pile.pop();
                pile.push(new Division(moins_deux, moins_un));
            }
        }
        else //Si le caractere saisie n'est ni un nombre ni un operateur, c'est une variable
        {
            pile.push(new Variable(vector_str[i][0]));
        }
    }
    this->m_exp_saisi = pile.top(); //Lorsque il ne reste plus qu'une expression sur la pile, on place celle ci dans m_exp_saisi
}

Fichier_Report Saisie::sauvegarder(istream &is, ostream &os, std::string nom_de_fichier, Expression* exp_to_save) //Sauvegarde une expression sous forme texte (forme polonaise inversee) dans un fichier
{
	ofstream flux_fichier(nom_de_fichier.c_str()); //ouvre un fichier

	if(flux_fichier)
	{
		exp_to_save->afficherNPI(flux_fichier); //imprime dans celui ci m_exp_saisi en notation polonaise inversee
		exp_to_save->afficherNPI(os);

		flux_fichier.close();

		return FILE_OK;
	}

	else
	{
		return FILE_ERROR;
	}
}


Fichier_Report Saisie::charger(istream &is, ostream &os, std::string nom_de_fichier) //Charge m_exp_saisi depuis un fichier texte (forme polonaise inversee)
{
	ifstream flux_fichier(nom_de_fichier.c_str()); //ouvre un fichier

	string buffer;

	vector <string> gollum; //on cree un vector de string pour y enregistrer ce qu'on lit depuis le fichier

	gollum.push_back("");

	int i, j = 0;

	char character;

	if(flux_fichier)
	{
		getline(flux_fichier, buffer); //on imprime flux fichier dans buffer

		for(i = 0; i < buffer.length(); i++) //on parcour buffer
		{

			character = buffer[i];

			if(character == ' ') //pour chaque espace dans le fichier, on passe a un autre string dans le vector de string
			{
				gollum.push_back("");
				j++;
			}

			else //on enregistre caractere par caractere le contenu du fichier dans le vector de string
			{
				gollum[j].push_back(character);
			}
		}

		flux_fichier.close();

		this->vector_to_exp(gollum, os); //on appelle vector_to_exp en lui passant en parametre gollum

		return FILE_OK;
	}

	else
	{
		return FILE_ERROR;
	}
}
