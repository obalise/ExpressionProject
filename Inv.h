#ifndef INV_H
#define INV_H

#include <iostream>
#include "opunin.h"


class Inv
{
    public:
        Inv(Expression * a, Expression* b);
        virtual ~Inv();
        Inv (ocnst Inv& other);

        float calculer() override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;

    protected:

    private:
        Expression* _opernadeGauche;
        Expression* _operandeDroite;
};
ostream &operator << (ostream &os, const Inv& op);
#endif // INV_H
