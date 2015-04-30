#ifndef VECT_H
#define VECT_H

#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

class Vect
{
    int dim;       // wymiar przestrzeni
    double* v;     // tablica współrzędnych

public:
    // Konstruktor domyślnie przyjmuje wymiar = 3
    Vect(int _dim = 3)
    {
        dim = _dim;
        v = new double[_dim];
    }

    // Konstruktor inicjalizujący współrzędne wektora
    Vect (int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        int i = 0;
        for (const double & d: _v) {
            assert(i < dim);
            v[i++] = d;
        }
    }

    // Destruktor
    ~Vect()
    {
        delete[] v;
    }

    // konstruktor kopiujący
    Vect(const Vect &w);

    // Operator podstawienia
    Vect& operator=(const Vect &w);

    // Metoda ustawiająca wartość współrzędnej
    void setCoordinate(int,double);

    // Metoda pobierająca wartość współrzędnej
    double getCoordinate(int) const;

    // Metoda zwracająca wymiar przestrzeni
    int getDimension() const;

    friend istream& operator>>(istream&, Vect&);

    // Operatory dodawania i odejmowania od danego wektora
    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);

    // Metoda obliczająca normę tego wektora
    double norm() const;

    // Metoda normalizująca wektor
    void normalize();
};

// Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2);

// Mnożenie wektora przez skalar
Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
