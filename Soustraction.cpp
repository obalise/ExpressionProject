#include <iostream>

#include "Soustraction.h"
#include "Constante.h"

Soustraction::Soustraction(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Soustraction" << endl;*/ }

Soustraction::~Soustraction()
{
    //cout << endl <<  "Destruction Soustraction" << endl;
}

Soustraction::Soustraction(const Soustraction& other)
{
    //copy ctor
}

void Soustraction::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "-";
    _operandeDroite->afficher(os);
    os << ")";

}

void Soustraction::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "-";
    //os << endl;
}

float Soustraction::calculer()
{
    return _operandeGauche->calculer()-_operandeDroite->calculer();
}

Expression* Soustraction::simplifier()
{
    float res;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            cout<<"If Soustraction"<<endl;
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                res=_operandeGauche->calculer()-_operandeDroite->calculer();
                cout<<"If Soustraction"<<endl;
            }
            else
            {
                cout<<"Else Soustraction droite"<<endl;
                _operandeDroite->simplifier();
            }
        }
        else
        {
            cout<<"Else Soustraction gauche"<<endl;
            _operandeGauche->simplifier();
        }

    cout<< "Resultat fct Soustraire simplifier="<<res<<endl;
}

ostream &operator<<( ostream &os, const Soustraction& op)
{
    op.afficher(os);
    return os;
}
