#include <iostream>

#include "OperateurUnaire.h"

using namespace std;

OperateurUnaire::OperateurUnaire()
{
    //cout << "Opunin" << endl;   ctor
}

OperateurUnaire::~OperateurUnaire()
{
    cout << "Destructeur Opunin" << endl; //dtor
}

OperateurUnaire::OperateurUnaire(const OperateurUnaire & other)
{
    //copy ctor
}
