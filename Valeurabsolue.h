#ifndef VALEURABSOLUE_H
#define VALEURABSOLUE_H

#include <iostream>
#include <cmath>
#include <OperateurUnaire.h>


class Valeurabsolue : public OperateurUnaire
{
    public:
        Valeurabsolue();
        virtual ~Valeurabsolue();
        float calculer();
        void afficher(ostream &os) const override;
        void afficheNPI(ostream &os) const override
        Expression* simplifier() override


    protected:

    private:
        Expression* _operateurUnique;
};
 ostream &operator << (ostram &os, const Valeurabsolue& op);
 #endif  //VALEURABSOLUE_H
