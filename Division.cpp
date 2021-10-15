#include "Division.h"

Division::Division(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Division" << endl;*/ }

Division::~Division()
{
    cout << endl <<  "Destruction Division" << endl;
}

Division::Division(const Division& other)
{
    //copy ctor
}

void Division::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "/";
    _operandeDroite->afficher(os);
    os << ")";

}

void Division::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "/";
    os << endl;
}

float Division::calculer()
{
    return _operandeGauche->calculer()/_operandeDroite->calculer();
}

ostream &operator<<( ostream &os, const Division& op)
{
    op.afficher(os);
    return os;
}
