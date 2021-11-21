#include "exponentielle.h"
#include <iostream>


Exponentielle::Exponentielle(Expression* a) : _operandeUnique(a)
{
    /*cout << "Exponentielle" << endl; //ctor*/
}

Exponentielle::~Exponentielle()
{
   cout << endl << "Destructeur Exponentielle" << endl; //dtor
}

Exponentielle::Exponentielle (const Exponentielle& other):OperateurUnaire(other)
{
    //copy ctor
}

void Exponentielle::afficher(ostream &os) const
{
    os << "exp(";
    _operandeUnique->afficher(os);
    os << ")";
}

void Exponentielle::afficherNPI(ostream &os) const
{
    os << "exp(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float Exponentielle::calculer()
{
    return exp(_operandeUnique->calculer());
}

Expression* Exponentielle::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Exponentielle& op)
{
    op.afficher(os);
    return os;
}
