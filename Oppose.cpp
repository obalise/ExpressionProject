#include <iostream>
#include "Oppose.h"

Oppose::Oppose(Expression* a) : _operateurUnique(a)
{
   // cout << "Opposé" << endl; //ctor
}

Oppose::~Oppose()
{
   //cout << "Destructeur Opposé" << endl;  //dtor
}

Oppose::Oppose(const Oppose& other)
{
    //copy ctor
}

void Oppose::afficher(ostream &os) const
{
    os << "Opposé(";
    _operateurUnique->afficher(os);
    os << ")"
}

void Oppose::afficherNPI(ostream &os) const
{
    os << "Opposé(";
    _operateurUnique->afficherNPI(os);
    os << ")"
}

float Oppose::calculer()
{
    return -(_operateurUnique->calculer());
}

Expression* Oppose::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Oppose& op)
{
    op.afficher(os);
    return os;
}
