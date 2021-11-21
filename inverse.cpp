#include "inverse.h"

#include "Inverse.h"

Inverse::Inverse(Expression* a) : _operandeUnique(a)
{
    /*cout << "Inverse" << endl; //ctor*/
}

Inverse::~Inverse()
{
   cout << endl << "Destructeur Inverse" << endl; //dtor
}

Inverse::Inverse (const Inverse& other):OperateurUnaire(other)
{
    //copy ctor
}

void Inverse::afficher(ostream &os) const
{
    os << "1/(";
    _operandeUnique->afficher(os);
    os << ")";
}

void Inverse::afficherNPI(ostream &os) const
{
    os << "1 ";
    _operandeUnique->afficherNPI(os);
    os << "/";
}

float Inverse::calculer()
{
    return (1/_operandeUnique->calculer());
}

Expression* Inverse::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Inverse& op)
{
    op.afficher(os);
    return os;
}
