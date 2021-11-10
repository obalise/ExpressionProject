#include <iostream>
#include "Inv.h"

Inv::Inv(Expression* a, Expression* b) : _opernadeGauche(a), _opernadeGauche(b)

Inv::~Inv()
{
    cout << endl << "Destructeur Inverse" << endl; //dtor
}
 Inv::Inv(const Inv& other)
 {
     //copy ctor
 }

 void Inv::afficher(ostream &os) const

 //dev

 }

 void Inv::afficherNPI(ostream &os) const
 {

 }

 float Inv::calculer()
 {
     return _operandeGauche->calculer() .../!\... _operandeDroite->calculer();
 }

 ostream &operator << (ostream &os, const Inv& op)
 {
     op.afficher(os);
     return os;
 }
