#include "Constante.h"

#include <iostream>

using namespace std;

Constante::Constante(float x) { _valeur = x; }


Constante::~Constante()
{

}

Constante::Constante(const Constante& other):Expression(other)
{
    //copy ctor
}

void Constante::afficher(ostream &os ) const
{
    os << _valeur;
}

void Constante::afficherNPI(ostream &os) const
{
     os << _valeur;
}

float Constante::calculer()
{
    return _valeur;
}

Expression* Constante::simplifier()
{
    return this;
}

ostream &operator<<( ostream &os, const Constante& c1)
{
    c1.afficher(os);
    return os;
}
