#include <iostream>
#include "Logarithme.h"

Logarithme::Logarithme(Expression* a) : _operandeUnique(a)
{
    // cout << "Logarithme" << end; // ctor
}

Logarithme::~Logarithme()
{
    cout << endl << "Destructeur logaritheme" << endl;//dtor
}

Logarithme::Logarithme(const Logarithme& other)
{
    //copy ctor
}

void Logarithme::afficher(ostream &os) const
{
    os << "Log(";
    _operandeUnique->afficher(os);
    os << ")";

}

void Logarithme::afficherNPI(ostream &os) const
{
    os << "Log("
    _operandeUnique->afficher(os);
    os << ")";
    os << endl;
}

float Logarithme::calculer()
{
    return log(_operandeUnique->calculer());
}

Expression* Logarithme::simplifier()
{

}


ostream &operator << (ostream &os, const Logarithme& op)
{
    op.afficher(os);
    return os;

}
