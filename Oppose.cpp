#include <iostream>
#include "Oppose.h"

Oppose::Oppose(Expression* a) : _operateurUnique(a)
{
   // cout << "Oppos�" << endl; //ctor
}

Oppose::~Oppose()
{
   //cout << "Destructeur Oppos�" << endl;  //dtor
}

Oppose::Oppose(const Oppose& other)
{
    //copy ctor
}

void Oppose::afficher(ostream &os) const
{
    os << "Oppos�(";
    _operateurUnique->afficher(os);
    os << ")"
}

void Oppose::afficherNPI(ostream &os) const
{
    os << "Oppos�(";
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
