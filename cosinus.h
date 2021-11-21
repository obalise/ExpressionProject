#ifndef COSINUS_H
#define COSINUS_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Cosinus : public OperateurUnaire
{
    public:
        Cosinus(Expression* a);
        virtual ~Cosinus();
        Cosinus (const Cosinus& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Cosinus & op);

#endif // COSINUS_H
