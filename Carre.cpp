#include <iostream>

#include "Carre.h"

Carre::Carre(Expression* a) : _operandeGauche(a),_operandeDroite(a)
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

void Carre::affucher(ostream &os) const
{
    _operandeGouche->afficher (os);
    os << "*";
    _operandeDroite->afficher(os);

}

void Carre::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroit->afficher(os);
    os << "*";
    //os << endl;
}

float Carre::calculer()
{
    return _operandeGauche ->calculer()*_operandeDroite->calculer();
}

ostream &operator << (ostream &os, const Carre& op)
{
    op.afficher(os);
    return os;
}
