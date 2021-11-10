#include "Variable.h"

#include <iostream>
#include <map>

using namespace std;

float vGlobValVar = 0;
Variable::Variable(char x) 
{ 
    _variable = x; /cout << "Variable" << endl;/ 
}

Variable::Variable(char x)
{
    _variable = x;
    _valeur = NULL;
    cout << "Constructeur Variable" << endl;
}


Variable::~Variable()
{
    //cout << "Destruction Variable" << endl;
}

Variable::Variable(const Variable& other)
{
    //Constructeur de recopie
}

void Variable::attribution(float valeur)
{
   _valeur = valeur;
   // _symbole.emplace(_variable,valeur);
}

void Variable::afficher(ostream &os ) const
{
    os << _variable ;
}

void Variable::afficherNPI(ostream &os) const
{
     os << _variable;
}

Expression* Variable::simplifier()
{

}

float Variable::calculer()
{
    this->attribution(vGlobValVar);
    return _valeur;
}

ostream &operator<<( ostream &os, const Variable& c1) //Surcharge d'op�rateurs pour afficher
{
    c1.afficher(os);
    return os;
}

float Variable::attribution()
{
    if (_symbole.find(_variable)->second == NULL)
    {
        cout << "Entrer la valeur de " << _variable << " :" << endl;
        cin >> _valeur;
        _symbole.emplace(_variable,_valeur);
    }
    else
    {
        _valeur = _symbole.find(_variable)->second;
    }
    return _valeur;
}

void Variable::afficherVariable(char var)
{
    if (_symbole.find(var)->second == NULL)
        cout << "Aucune valeur attribuée pour => " << var;
    else
        cout << var << " = " << _symbole.find(var)->second;
}

float Variable::getValeur(char var)
{
    return _symbole.find(var)->second;
}

void Variable::afficherTableSymboles()
{
    map<char,float>::reverse_iterator i;
    for (i=_symbole.rbegin(); i!=_symbole.rend(); ++i)
    {
        cout << i->first << " => " << i->second << '\n';
    }
}