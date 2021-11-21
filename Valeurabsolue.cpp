#include<iostream>
#include "Valeurabsolue.h"

using namespace std;

Valeurabsolue::Valeurabsolue()
{
    //cout << "Valeur absolue" << endl; //ctor
}

Valeurabsolue::~Valeurabsolue()
{
    // cout "Destructeur Valeurabsolue" << endl; //dtor
}
void Valeurabsolue::afficher(ostream &os) const
{
    os << "Valeurabsulue |";
    _operateurUnique->afficher(os);
    os << "|"
}

void Valeurabsolue::afficheNPI(ostream &os) const
{
    os << "Valeurabsolue |";
    _operateurUnique->afficherNPI(os);
    os << "|";
    cout << endl;
}
float Valeurabsolue::calculer()
{
    return abs(_operandeUnique->calculer());
}

Expression* Valeurabsolue::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const Valeurabsolue& op)
{
    op.afficher(os);
    return os;
}
