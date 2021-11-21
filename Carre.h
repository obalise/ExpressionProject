#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include "Opunin.h"

#define CARRE_H
#define CARRE_H

class Carre
{
    public:
        Carre(Expression* a);
        virtual ~Carre();
        Carre (const Carre& other);

        float calculer () ;
        void afficher(ostream &os) const ;
        void afficherNPI(ostream &os) const;

    protected:

    private:
        Expression* _operandeGauche;
        Expression* _operandeDroite;

        ostream &operator << (ostream &os, const Carre& op);
};

#endif // CARRE_H
