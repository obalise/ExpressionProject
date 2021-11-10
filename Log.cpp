#include <iostream>
#include "Log.h"

Log::Log(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)

Log::~Log()
{
    cout << endl << "Destructeur logaritheme" << endl;//dtor
}

Log::Log(const Log& other)
{
    //copy ctor
}

void Log::afficher(ostream &os) const
{
    os << "...";
    _operandeGauche->afficher(os);
    os << "...";
    _operandeDroite->afficher(os);
    os << "...";//
}

void Log::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "...";
    os << endl;
}

float Log::calculer()
{
    return _operandeGauche->calculer()log _operandeDroite->calculer();
}

ostream &operator << (ostream &os, const Log& op)
{
    op.afficher(os);
    return os;

}
