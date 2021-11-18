#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"

using namespace std;

class Operateur : public Expression
{
public:
    Operateur();
    virtual ~Operateur();
    Operateur(const Operateur& other);


protected:


private:
};

#endif // OPERATEUR_H
