#ifndef OPUNIN_H
#define OPUNIN_H

#include "Expression.h"

using namespace std;

class OperateurUnaire : public Expression
{
public:
    OperateurUnaire();
    virtual ~OperateurUnaire();
    OperateurUnaire(const OperateurUnaire& other);
    //Expression* _operandeUnique;

protected:

private:

};



#endif // OPUNIN_H
