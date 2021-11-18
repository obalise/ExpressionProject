#include "logneperien.h"

LogNeperien::LogNeperien(Expression* a) : _operandeUnique(a)
{
    /*cout << "LogNeperien" << endl; //ctor*/
}

LogNeperien::~LogNeperien()
{
   cout << endl << "Destructeur LogNeperien" << endl; //dtor
}

LogNeperien::LogNeperien (const LogNeperien& other):OperateurUnaire(other)
{
    //copy ctor
}

void LogNeperien::afficher(ostream &os) const
{
    os << "Ln(";
    _operandeUnique->afficher(os);
    os << ")";
}

void LogNeperien::afficherNPI(ostream &os) const
{
    os << "Ln(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float LogNeperien::calculer()
{
    return log(_operandeUnique->calculer());
}

Expression* LogNeperien::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const LogNeperien& op)
{
    op.afficher(os);
    return os;
}

