#ifndef TROJKAT_H
#define TROJKAT_H

#include "figura.h"
#include "punkt.h" 

namespace MojeFigury {
    // Klasa Odcinek – dziedziczy po klasie Figura
    class Trojkat: public Figura {
        Punkt w1, w2, w3; // Wierzchołki trójkata
    public:
        // Konstruktor, w tym domyślny (przykładowy)
        Trojkat(Punkt a = Punkt(0,1), Punkt b = Punkt(0,0), Punkt c = Punkt(1,0));
        // Funkcja do rysowania trójkąta w oknie
        void rysuj(void);
        // Funkcja do przesuwania trójkąta
        void przesun(double, double);
        // Funkcja do skalowania trójkąta
        void skaluj(double);
    class ZlePunkty {
        Punkt a2, b2, c2; // wierzchołki trójkąta
    public:
        // Konstruktor
        ZlePunkty(Punkt a, Punkt b, Punkt c): a2(a), b2(b), c2(c) {}
        // Zwróć wierzchołki
        void dajKonce(Punkt& a, Punkt& b, Punkt& c) const
        { a = a2; b = b2; c = c2; }
        // Komunikat
        void Komunikat() const
        {
            std::cerr << "\n* Wyjatek: class Trojkat: w1 "
                      << a2 << ", w2" << b2 << ", w3" << c2 << std::endl;
        }
    };
    };

inline Trojkat::Trojkat(Punkt a, Punkt b, Punkt c) {
    if (a != b && a != c && b != c) {
        w1 = a; w2 = b; w3 = c;
    }
    // Rzucanie wyjątku gdy wierzchołki się pokrywają,
    else
        throw Trojkat::ZlePunkty(a, b, c);
}
}

#endif