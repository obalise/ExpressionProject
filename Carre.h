#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include "OperateurUnaire.h"


class Carre : public OperateurUnaire
{
    public:
        Carre(Expression* a);
        virtual ~Carre();
        Carre (const Carre& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Carre & op);

#endif // CARRE_H
