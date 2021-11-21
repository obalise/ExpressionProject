#ifndef EXPONENTIELLE_H
#define EXPONENTIELLE_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"

class Exponentielle : public OperateurUnaire
{
    public:
        Exponentielle(Expression* a);
        virtual ~Exponentielle();
        Exponentielle (const Exponentielle& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Exponentielle & op);

#endif // EXPONENTIELLE_H
