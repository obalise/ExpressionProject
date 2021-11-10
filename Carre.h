#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include "Opunin.h"


class Carre
{
    public:
        Carre(Expression* a);
        virtual ~Carre();
        Carre (const Carre& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;

    protected:

    private:
        Expression* _operandeGauche a;
        Expression* _operandeDroite a;

        ostream &operator<<(ostream &os, const carre& op);
};

#endif // CARRE_H
