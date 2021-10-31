#include <iostream>

#include "Addition.h"

using namespace std;

Addition::Addition(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
{
    //cout <<  "Addition " << endl;
}

Addition::~Addition()
{
    //cout <<  "Destruction Addition" << endl;
}

Addition::Addition(const Addition& other)
{
    //copy ctor
}

void Addition::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "+";
    _operandeDroite->afficher(os);
    os << ")";

}

void Addition::afficherNPI(ostream &os) const
{
    _operandeGauche->afficher(os);
    _operandeDroite->afficher(os);
    os << "+";
    //os << endl;

}

float Addition::calculer()
{

   return _operandeGauche->calculer()+ _operandeDroite->calculer();

}

ostream &operator<<(ostream &os, const Addition& op)
{
    op.afficher(os);
    return os;
}
