#include <iostream>
#include "Arccos.h"


Arccos::Arccos(Expression* a) : _operandeUnique(a)
{
    // cout << "Arccos" << end; // ctor
}

Arccos::~Arccos()
{
    cout << endl << "Destructeur Arccos" << endl;//dtor
}

Arccos::Arccos(const Arccos& other)
{
    //copy ctor
}

void Arccos::afficher(ostream &os) const
{
    os << "Arccos(";
    _operandeUnique->afficher(os);
    os << ")";

}

void Arccos::afficherNPI(ostream &os) const
{
    os << "Arccos("
    _operandeUnique->afficher(os);
    os << ")";
    os << endl;
}

float Arccos::calculer()
{
    return acos(_operandeUnique->calculer());
}

Expression* Arccos::simplifier()
{
    return this;
}


ostream &operator << (ostream &os, const Arccos& op)
{
    op.afficher(os);
    return os;

}
