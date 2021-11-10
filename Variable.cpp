#include "Variable.h"

#include <iostream>
#include <map>

using namespace std;

Variable::Variable(char x) { _variable = x; /*cout << "Variable" << endl;*/ }


Variable::~Variable()
{
    //cout << "Destruction Variable" << endl;
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

Expression* Variable::simplifier()
{

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
