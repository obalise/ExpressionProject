#ifndef INVERSE_H
#define INVERSE_H

#include <iostream>

#include "OperUnaire.h"


class Inverse : public OperateurUnaire
{
    public:
        Inverse(Expression * a);
        Inverse(const Inverse& other);
        virtual ~Inverse();


        float calculer();
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier() override;

    protected:

    private:
        Expression* _opernadeUnique;

};
ostream &operator << (ostream &os, const Inverse& op);
#endif // INVERSE_H
