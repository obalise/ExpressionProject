#include <iostream>

#include "Carre.h"

Carre::Carre(Expression* a) : _operandeUnique(a)
{
    /*cout << "Carre" << endl; //ctor*/
}


Carre::Carre (const Carre& other)
{
    cout << "Constructeur carré" << endl;//copy ctor
}

Carre::~Carre()
{
   cout << endl << "Destructeur Carré" << endl; //dtor
}


void Carre::affucher(ostream &os) const
{
    _operateurUnique->afficher(os);
    _operandeUnique->afficher(os);
    os << "²";
    cout << endl;

}

void Carre::afficherNPI(ostream &os) const
{
    _operteurUniqe->afficherNPI(os);
    _operandeUnique->afficherNPI(os);
      os << "²";
    cout  << endl;
}

float Carre::calculer()
{
    return _operandeUnique->calculer();
    return _operandeUnique->calculer()*_operateurUnique->calculer();
}

ostream &operator << (ostream &os, const Carre& op)
{
    op.afficher(os);
    return os;
}
