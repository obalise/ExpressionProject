#include <iostream>

#include "sinus.h"

Sinus::Sinus(Expression* a) : _operandeUnique(a)
{
    /*cout << "Sinus" << endl; //ctor*/
}

Sinus::~Sinus()
{
   cout << endl << "Destructeur Sinus" << endl; //dtor
}

Sinus::Sinus (const Sinus& other)
{
    //copy ctor
}

void Sinus::afficher(ostream &os) const
{
    os << "Sin(";
    _operandeUnique->afficher(os);
    os << ")";
}

void Sinus::afficherNPI(ostream &os) const
{
    os << "Sin(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float Sinus::calculer()
{
    return sin(_operandeUnique->calculer());
}

Expression* Sinus::simplifier()
{

}

ostream &operator << (ostream &os, const Sinus& op)
{
    op.afficher(os);
    return os;
}
