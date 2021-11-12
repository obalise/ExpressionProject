#include "Saisie.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stack>

using namespace std;

bool is_digits(const std::string &str)
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
    stack<Expression *> pile;


    for(i = 0; i < vector_str.size()-1; i++)
    {
        if(is_digits(vector_str[i]))
        {
            pile.push(new Constante(stof(vector_str[i])));
        }
        else if(vector_str[i] == "+")
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
                pile.push(new Addition(moins_deux, moins_un));
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
        else
        {
            pile.push(new Variable(vector_str[i][0]));
        }
    }
    this->m_exp_saisi = pile.top();
}
