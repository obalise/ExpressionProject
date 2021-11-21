
#include <iostream>
#include "Arctan.h"

Arctan::Arctan(Expression* a) : _operandeUnique(a)
{
    // cout << "Arctan" << end; // ctor
}

Arctan::~Arctan()
{
    cout << endl << "Destructeur Arctan" << endl;//dtor
}

Arctan::Arctan (const Arctan& other)
{
    //copy ctor
}

void Arctan::afficher(ostream &os) const
{
    os << "Arctan(";
    _operandeUnique->afficher(os);
    os << ")";

}

void Arctan::afficherNPI(ostream &os) const
{
    os << "Arctan("
    _operandeUnique->afficher(os);
    os << ")";
    os << endl;
}

float Arctan::calculer()
{
    return atan(_operandeUnique->calculer());
}

Expression* Arctan::simplifier()
{
    return this;
}

