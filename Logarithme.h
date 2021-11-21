#ifndef LOGARITHME_H
#define LOGARITHME_H


#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Logarithme : public OperateurUnaire
{
    public:
        Logarithme(Expression* a);
        virtual ~Logarithme();
        Logarithme (const Logarithme& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Logarithme & op);
#endif // LOGARITHME
