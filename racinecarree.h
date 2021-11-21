#ifndef RACINECARREE_H
#define RACINECARREE_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"

class RacineCarree : public OperateurUnaire
{
    public:
        RacineCarree(Expression* a);
        virtual ~RacineCarree();
        RacineCarree (const RacineCarree& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const RacineCarree & op);
#endif // RACINECARREE_H
