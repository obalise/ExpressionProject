#ifndef TAN_H
#define TAN_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Tan : public OperateurUnaire
{
    public:
        Tan(Expression* a);
        virtual ~Tan();
        Tan (const Tan& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Tan & op);

#endif // TAN_H
