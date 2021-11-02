#ifndef SAISIE_H
#define SAISIE_H
#include <iostream>
#include <vector>
#include "Expression.h"
#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"

class Saisie
{
    public:
        Saisie();
        virtual ~Saisie();

        int GetCounter() { return m_Counter; }
        void SetCounter(int val) { m_Counter = val; }
        Expression* GetExpSaisie() { return m_exp_saisi; }

        void saisir();

    protected:

    private:
        int m_Counter;
        std::vector<std::string> m_exp_str;
		Expression *m_exp_saisi = NULL;
};

#endif // SAISIE_H
