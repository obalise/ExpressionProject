#include <iostream>

#include "tan.h"

Tan::Tan(Expression* a) : _operandeUnique(a)
{
    /*cout << "Tan" << endl; //ctor*/
}

Tan::~Tan()
{
   cout << endl << "Destructeur Tan" << endl; //dtor
}

Tan::Tan (const Tan& other):OperateurUnaire(other)
{
    //copy ctor
}

void Tan::afficher(ostream &os) const
{
    os << "Tan(";
    _operandeUnique->afficher(os);
    os << ")";
}

void Tan::afficherNPI(ostream &os) const
{
    os << "Tan(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float Tan::calculer()
{
    return tan(_operandeUnique->calculer());
}

Expression* Tan::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Tan& op)
{
    op.afficher(os);
    return os;
}
