#include <iostream>
#include "Valabs.h"

Valabs::Valabs(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
{
    /*cout << "Valeur absolue" << endl;*///ctor
}

Valabs::~Valabs()
{
   cout << endl << "Destructeur Valeur absolu" << endl; //dtor
}
Valabs::Valabs(const Valabs& other)
{
    //copy ctor
}

void Valabs::afficher (osteam &os) const
{
    os << "|";
    _operandeGauche->afficher(os);
    _operandeDroitr->afficher(os);
    os << "|";
    os << endl;

}

void Valabs::afficherNPI(ostream &os)
{
    _operandeGauche->afficherNPI(os);
    _OprendeDroite->afficher(os);
    os << "|";
    os << "|";
    os << endl;
}

float Valabs::calculer()
{
    return _operandeGauche->calculer()ads_operandeDroite->calculer();

}

ostream &operator << (ostream &os, const Valabs& op)
{
    op.afficher os;
    return os;
}
