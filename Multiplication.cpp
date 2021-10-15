#include <iostream>

#include "Multiplication.h"

Multiplication::Multiplication(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Multiplication" << endl;*/ }

Multiplication::~Multiplication()
{
    cout << endl <<  "Destruction Multiplication" << endl;
}

Multiplication::Multiplication(const Multiplication& other)
{
    //copy ctor
}

void Multiplication::afficher(ostream &os) const
{

     _operandeGauche->afficher(os);
    os << "*";
    _operandeDroite->afficher(os);

}

void Multiplication::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "*";
    //os << endl;
}

float Multiplication::calculer()
{
    return _operandeGauche->calculer()*_operandeDroite->calculer();
}

ostream &operator<<( ostream &os, const Multiplication& op)
{
    op.afficher(os);
    return os;
}
