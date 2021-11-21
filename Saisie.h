/************************
 * classe Saisie, par groupe 1 (Mathieu + Thomas)
 * Methode saisie.sauvegarder et saisie.charger, par groupe 2 (Remi + Anakin)
 * *********************/

#ifndef SAISIE_H
#define SAISIE_H
#include <iostream>
#include <vector>
#include "Expression.h"
#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Variable.h"

typedef enum
{
    FILE_OK,
    FILE_NO_OPEN,
    FILE_ERROR,
}Fichier_Report;

class Saisie    //Classe qui garde en memoire l'expression Saisie par l'utilisateur. Permet de la saisir, l'enregistrer dans un fichier ou de la charger
{
    public:
        Saisie();	//Constructeur
        virtual ~Saisie();

        Expression* GetExpSaisie() { return m_exp_saisi; } //Renvoie l'expression en memoire

        void saisir(istream &is, ostream &os); //Demande a l'utilisateur de saisir une expression, la stoque dans m_exp_saisi
        Fichier_Report sauvegarder(istream &is, ostream &os, std::string nom_de_fichier, Expression* exp_to_save); //Sauvegarde une expression sous forme texte (forme polonaise inversee) dans un fichier
        Fichier_Report charger(istream &is, ostream &os, std::string nom_de_fichier); //Charge m_exp_saisi depuis un fichier texte (forme polonaise inversee) 
        void vector_to_exp(std::vector<std::string> vector_str, ostream &os); //Prend en parametre un vector de string, le convertit en expression

    protected:

    private:
		Expression *m_exp_saisi = NULL; //Pointeur sur l'Expression en memoire
};

#endif // SAISIE_H
