#include "cosinus.h"

Cosinus::Cosinus(Expression* a) : _operandeUnique(a)
{
    /*cout << "Cosinus" << endl; //ctor*/
}

Cosinus::~Cosinus()
{
   cout << endl << "Destructeur Cosinus" << endl; //dtor
}

Cosinus::Cosinus (const Cosinus& other)
{
    //copy ctor
}

void Cosinus::afficher(ostream &os) const
{
    os << "Cos(";
    _operandeUnique->afficher(os);
    os << ")";
}

void Cosinus::afficherNPI(ostream &os) const
{
    os << "Cos(";
    _operandeUnique->afficherNPI(os);
    os << ")";
}

float Cosinus::calculer()
{
    return cos(_operandeUnique->calculer());
}

Expression* Cosinus::simplifier()
{

}

ostream &operator << (ostream &os, const Cosinus& op)
{
    op.afficher(os);
    return os;
}
