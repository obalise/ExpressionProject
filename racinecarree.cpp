#include "racinecarree.h"

RacineCarree::RacineCarree(Expression* a) : _operandeUnique(a)
{
    /*cout << "RacineCarree" << endl; //ctor*/
}

RacineCarree::~RacineCarree()
{
   cout << endl << "Destructeur RacineCarree" << endl; //dtor
}

RacineCarree::RacineCarree (const RacineCarree& other):OperateurUnaire(other)
{
    //copy ctor
}

void RacineCarree::afficher(ostream &os) const
{
    os << "√(";
    _operandeUnique->afficher(os);
    os << ")";
}

void RacineCarree::afficherNPI(ostream &os) const
{
    os << "√(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float RacineCarree::calculer()
{
    return sqrt(_operandeUnique->calculer());
}

Expression* RacineCarree::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const RacineCarree& op)
{
    op.afficher(os);
    return os;
}
