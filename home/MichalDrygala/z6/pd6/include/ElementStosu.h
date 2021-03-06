#ifndef ELEMENTSTOSU_H
#define ELEMENTSTOSU_H

#include<iostream>
using namespace std;

/* Obiekty klas implementujących interfejs ElementStosu można przechowywać w niżej określonej strukturze Stos. */

class ElementStosu
{
    virtual void output(ostream&) = 0;

public:

//destruktor
    virtual ~ElementStosu() = 0 ;

//operator
    friend ostream& operator << (ostream& os, ElementStosu& el);
};

#endif // ELEMENTSTOSU_H
