#include "log10.h"


Log10::Log10(Expression* a) : _operandeUnique(a)
{
    /*cout << "Log10" << endl; //ctor*/
}

Log10::~Log10()
{
   cout << endl << "Destructeur Log10" << endl; //dtor
}

Log10::Log10 (const Log10& other):OperateurUnaire(other)
{
    //copy ctor
}

void Log10::afficher(ostream &os) const
{
    os << "Log10(";
    _operandeUnique->afficher(os);
    os << ")";
}

void Log10::afficherNPI(ostream &os) const
{
    os << "Log10(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float Log10::calculer()
{
    return log10(_operandeUnique->calculer());
}

Expression* Log10::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Log10& op)
{
    op.afficher(os);
    return os;
}
