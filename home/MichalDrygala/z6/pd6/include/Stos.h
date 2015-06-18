#ifndef STOS_H
#define STOS_H

#include <iostream>
using namespace std;

#include "ElementStosu.h"

/*
 * Obiekty klasy Stos mog� przechowywa� dowolne obiekty implementuj�ce interfejs
 * ElementStosu.
 */

class Stos
{
    struct Link
    {
        ElementStosu    *dane;
        Link            *poprzedni;
    };

    Link* wierzcholek;

public:

//konstruktor
    Stos() ;

//destruktor
    ~Stos();

//funkcje
    void push(ElementStosu* el);
    ElementStosu* pop();

//operatory
    friend ostream& operator<<(ostream&, Stos &);
};

#endif // STOS_H
