#ifndef VALABS_H
#define VALABS_H

#include <iostream>
#include "Opunin.h"


class Valabs
{
    public:
        Valabs(Epression* a, Expression* b);
        virtual ~Valabs();
        Valabs(const Valabs& other);

        float calculer() override;
        void afficher(ostream &os) const override;
        void afficher(ostream &os) const override;

    protected:

    private:
        Expression* _operandeGauche;
        Expression* _OprendeDroite;
};

ostream &operator << (ostream &os, const valabs& op);

#endif // VALABS_H
