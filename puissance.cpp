#include "puissance.h"

#include <iostream>
#include <cmath>
#include "Variable.h"
#include "puissance.h"
#include "Constante.h"
#include "Expression.h"

using namespace std;

Puissance::Puissance(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
{
    //cout <<  "Puissance " << endl;
}

Puissance::~Puissance()
{
    //cout <<  "Destruction Puissance" << endl;
}

Puissance::Puissance(const Puissance& other):Operateur(other)
{
    //copy ctor
    //this->_operandeDroite = other._operandeDroite;
    //this->_operandeGauche = other._operandeGauche;
}

void Puissance::afficher(ostream &os) const
{
    _operandeGauche->afficher(os);
    os << "^";
    _operandeDroite->afficher(os);
}

void Puissance::afficherNPI(ostream &os) const
{
    _operandeGauche->afficher(os);
    _operandeDroite->afficher(os);
    os << "^";

}

float Puissance::calculer()
{
   return pow(_operandeGauche->calculer(),_operandeDroite->calculer());

}


Expression* Puissance::simplifier()
{
   return this;
}

ostream &operator<<(ostream &os, const Puissance& op)
{
    op.afficher(os);
    return os;
}
