#ifndef ARCTAN_H
#define ARCTAN_H

#include <cmath>
#include "OperateurUnaire.h"

class Arctan : public OperateurUnaire
{
    public:
        Arctan(Expression* a);
        virtual ~Arctan();
        Arctan(const Arctan& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Arctan& op);

#endif // ARCTAN_H
