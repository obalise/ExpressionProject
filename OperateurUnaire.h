#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Expression.h"

using namespace std;


class OperateurUnaire : public Expression
{
    public:
        OperateurUnaire();
        virtual ~OperateurUnaire();
        OperateurUnaire(const OperateurUnaire& other);

    protected:

    private:
};

#endif // OPERATEURUNAIRE_H
