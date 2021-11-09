#include "Variable.h"

#include <iostream>
#include <map>

using namespace std;

Variable::Variable(char x) 
{ 
    _variable = x; /cout << "Variable" << endl;/ 
}


Variable::~Variable()
{
    cout << "Destruction Variable" << endl;
}

Variable::Variable(const Variable& other)
{
    //copy ctor
}

void Variable::afficher(ostream &os ) const
{
    os << _variable;
}

void Variable::afficherNPI(ostream &os) const
{
     os << _variable;
}

float Variable::calculer()
{
    return _valeur;
}

ostream &operator<<( ostream &os, const Variable& c1)
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