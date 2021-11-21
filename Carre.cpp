#include <iostream>

#include "Carre.h"

Carre::Carre(Expression* a) : _operandeUnique(a)
{
    /*cout << "Carre" << endl; //ctor*/
}

Carre::~Carre()
{
   cout << endl << "Destructeur Carré" << endl; //dtor
}

Carre::Carre (const Carre& other):OperateurUnaire(other)
{
    //copy ctor
}

void Carre::afficher(ostream &os) const
{
    _operandeUnique->afficher(os);
    os << "²";
}

void Carre::afficherNPI(ostream &os) const
{
    _operandeUnique->afficherNPI(os);
    os << "²";
}

float Carre::calculer()
{
    return _operandeUnique->calculer() * _operandeUnique->calculer();
}

Expression* Carre::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Carre& op)
{
    op.afficher(os);
    return os;
}
