#ifndef SINUS_H
#define SINUS_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Sinus : public OperateurUnaire
{
    public:
        Sinus(Expression* a);
        virtual ~Sinus();
        Sinus (const Sinus& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Sinus & op);

#endif // SINUS_H
