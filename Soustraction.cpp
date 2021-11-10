#include "Soustraction.h"

Soustraction::Soustraction(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Soustraction" << endl;*/ }

Soustraction::~Soustraction()
{
    //cout << endl <<  "Destruction Soustraction" << endl;
}

Soustraction::Soustraction(const Soustraction& other)
{
    //copy ctor
}

void Soustraction::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "-";
    _operandeDroite->afficher(os);
    os << ")";

}

void Soustraction::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "-";
    //os << endl;
}

float Soustraction::calculer()
{
    return _operandeGauche->calculer()-_operandeDroite->calculer();
}

ostream &operator<<( ostream &os, const Soustraction& op)
{
    op.afficher(os);
    return os;
}
