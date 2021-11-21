#ifndef VALEURABSOLUE_H
#define VALEURABSOLUE_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <OperateurUnaire.h>


class ValeurAbsolue : public OperateurUnaire
{
    public:
        ValeurAbsolue(Expression* a);
        virtual ~ValeurAbsolue();
        ValeurAbsolue (const ValeurAbsolue& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const ValeurAbsolue & op);

 #endif  //VALEURABSOLUE_H
