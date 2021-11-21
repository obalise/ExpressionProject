#ifndef ARCSIN_H
#define ARCSIN_H
#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Arcsin : public OperateurUnaire
{
    public:
        Arcsin(Expression* a);
        virtual ~Arcsin();
        Arcsin(const Arcsin& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Arcsin& op);

#endif // ARCSIN_H
