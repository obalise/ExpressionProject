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
<<<<<<< Updated upstream
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
=======
    float sous=0;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                Soustraction res2(_operandeGauche,_operandeDroite);
                sous=res2.calculer();
            }
            else
            {
                Soustraction res2(_operandeGauche,_operandeDroite->simplifier());
                sous=res2.calculer();
>>>>>>> Stashed changes
            }
        }
        else
        {
<<<<<<< Updated upstream
            cout<<"Else Soustraction gauche"<<endl;
            _operandeGauche->simplifier();
        }

    cout<< "Resultat fct Soustraire simplifier="<<res<<endl;
=======
            Soustraction res2(_operandeGauche->simplifier(),_operandeDroite);
            sous=res2.calculer();
        }

    cout<< "Resultat fct sous simplifier final="<<sous<<endl;
    return this;
>>>>>>> Stashed changes
}

ostream &operator<<( ostream &os, const Soustraction& op)
{
    op.afficher(os);
    return os;
}
