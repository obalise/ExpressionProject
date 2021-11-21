#include <iostream>
#include "OperateurUnaire.h"

using namespace std;

OperateurUnaire::OperateurUnaire()
{
    //cout << "Opearateur Uniare" << end; ctor
}

OperateurUnaire::~OperateurUnaire()
{
   cout << "Destructeur Operateur Unaire" //dtor
}

OperateurUnaire::OperateurUnaire(const OperateurUnaire& other)
{
    //copy ctor
}
