#include <iostream>

#include "Carre.h"

Carre::Carre(Expression* a) : _operandeUnique(a)
{
    /*cout << "Carre" << endl; //ctor*/
}

Carre::~Carre()
{
   cout << endl << "Destructeur Mutiplication" << endl; //dtor
}

Carre::Carre (const Carre& other)
{
    //copy ctor
}

void Carre::afficher(ostream &os) const
{
    _operandeUnique->afficher (os);
    os << "²";


}

void Carre::afficherNPI(ostream &os) const
{
    _operandeUnique->afficherNPI(os);
    os << "²";
}

float Carre::calculer()
{
    return _operandeUnique->calculer();
}

ostream &operator << (ostream &os, const Carre& op)
{
    op.afficher(os);
    return os;
}
