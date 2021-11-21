
#include <iostream>
#include "Arcsin.h"

Arcsin::Arcsin(Expression* a) : _operandeUnique(a)
{
    // cout << "Arcsin" << end; // ctor
}

Arcsin::~Arcsin()
{
    cout << endl << "Destructeur Arcsin" << endl;//dtor
}

Arcsin::Arcsin (const Arcsin& other)
{
    //copy ctor
}

void Arcsin::afficher(ostream &os) const
{
    os << "Arcsin(";
    _operandeUnique->afficher(os);
    os << ")";

}

void Arcsin::afficherNPI(ostream &os) const
{
    os << "Arcsin("
    _operandeUnique->afficher(os);
    os << ")";
    os << endl;
}

float Arcsin::calculer()
{
    return asin(_operandeUnique->calculer());
}

Expression* Arcsin::simplifier()
{
    return this;
}


ostream &operator << (ostream &os, const Arcsin& op)
{
    op.afficher(os);
    return os;

}
