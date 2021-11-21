#include <iostream>
#include "Inverse.h"

Inverse::Inverse(Expression* a) : _opernadeUnique()

Inverse::~Inverse()
{
    cout << endl << "Destructeur Inverse" << endl; //dtor
}
Inverse::Inverse(const Inverse& other)
 {
     //copy ctor
 }

 void Inverse::afficher(ostream &os) const

 {
     os << "Inverse(";
     _operateurUnique->afficher(os);
     os << ")";
     cout << endl;
 }

 void Inverse::afficherNPI(ostream &os) const
 {
     os << "Inverse("
     _operateurUnique->afficherNPI(os);
     os << ")";
     cout << endl;

 }

 float Inverse::calculer()
 {
     return (1/_operateurUnique->calculer());
 }

 Expression* Inverse::simplifier()

 {

 }

 ostream &operator << (ostream &os, const Inverse& op)
 {
     op.afficher(os);
     return os;
 }
