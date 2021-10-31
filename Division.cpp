#include <iostream>

#include "Division.h"
#include "Constante.h"

Division::Division(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Division" << endl;*/ }

Division::~Division()
{
    //cout << endl <<  "Destruction Division" << endl;
}

Division::Division(const Division& other)
{
    //copy ctor
}

void Division::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "/";
    _operandeDroite->afficher(os);
    os << ")";

}

void Division::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "/";
    os << endl;
}

float Division::calculer()
{
    return _operandeGauche->calculer()/_operandeDroite->calculer();
}


Expression* Division::simplifier()
{
    float res;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            cout<<"If Division"<<endl;
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                res=_operandeGauche->calculer()/_operandeDroite->calculer();
                cout<<"If Division"<<endl;
            }
            else
            {
                cout<<"Else Division droite"<<endl;
                _operandeDroite->simplifier();
            }
        }
        else
        {
            cout<<"Else Division gauche"<<endl;
            _operandeGauche->simplifier();
        }
    cout<< "Resultat fct Division simplifier="<<res<<endl;
}

ostream &operator<<( ostream &os, const Division& op)
{
    op.afficher(os);
    return os;
}
