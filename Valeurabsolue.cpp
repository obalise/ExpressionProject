#include<iostream>
#include "Valeurabsolue.h"

ValeurAbsolue::ValeurAbsolue(Expression* a) : _operandeUnique(a)
{
    /*cout << "ValeurAbsolue" << endl; //ctor*/
}

ValeurAbsolue::~ValeurAbsolue()
{
   cout << endl << "Destructeur ValeurAbsolue" << endl; //dtor
}

ValeurAbsolue::ValeurAbsolue (const ValeurAbsolue& other):OperateurUnaire(other)
{
    //copy ctor
}

void ValeurAbsolue::afficher(ostream &os) const
{
    os << "|";
    _operandeUnique->afficher(os);
    os << "|";
}

void ValeurAbsolue::afficherNPI(ostream &os) const
{
    os << "|";
    _operandeUnique->afficherNPI(os);
    os << "|";
}

float ValeurAbsolue::calculer()
{
    return abs(_operandeUnique->calculer());
}

Expression* ValeurAbsolue::simplifier()
{
    return this;
}

ostream &operator << (ostream &os, const ValeurAbsolue& op)
{
    op.afficher(os);
    return os;
}

