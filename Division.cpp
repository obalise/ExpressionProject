#include <iostream>

#include "Division.h"
#include "Constante.h"

Division::Division(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Division" << endl;*/ }

Division::~Division()
{
   // cout << endl <<  "Destruction Division" << endl;
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
    float res = 0.0;
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
    float div=0;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                Division res2(_operandeGauche,_operandeDroite);
                div=res2.calculer();
            }
            else
            {
                Division res2(_operandeGauche,_operandeDroite->simplifier());
                div=res2.calculer();
            }
        }
        else
        {
            cout<<"Else Division gauche"<<endl;
            _operandeGauche->simplifier();
        }
    cout<< "Resultat fct Division simplifier="<<res<<endl;
            Division res2(_operandeGauche->simplifier(),_operandeDroite);
            div=res2.calculer();
        }

    //cout<< "Resultat fct div simplifier final="<<div<<endl;
    return this;
    }
}

ostream &operator<<( ostream &os, const Division& op)
{
    op.afficher(os);
    return os;
}
