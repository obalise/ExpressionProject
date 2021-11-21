#ifndef INVERSE_H
#define INVERSE_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Inverse : public OperateurUnaire
{
    public:
        Inverse(Expression* a);
        virtual ~Inverse();
        Inverse (const Inverse& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

#endif // INVERSE_H
