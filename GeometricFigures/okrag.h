#ifndef OKRAG_H
#define OKRAG_H

#include "figura.h"
#include "punkt.h" 

namespace MojeFigury {
    // Klasa Okrag – dziedziczy po klasie Figura
    class Okrag: public Figura {
        Punkt srodek; // Środek okręgu
        double r; // Promień okręgu
    public:
        // Konstruktor, w tym domyślny (przykładowy)
        Okrag(Punkt a = Punkt(0,0), double b = 1);
        // Funkcja do rysowania okręgu w oknie
        void rysuj(void);
        // Funkcja do przesuwania okręgu
        void przesun(double, double);
        // Funkcja do skalowania okręgu
        void skaluj(double);
    class ZlyPromien {
        double b2; // Promień
    public:
        // Konstruktor
        ZlyPromien(double b): b2(b) {}
        // Zwróć promien
        void dajPromien(double& b) const
        { b = b2; }
        // Komunikat
        void Komunikat() const
        {
            std::cerr << "\n* Wyjatek: class Okrag: promien"
                      << b2 << std::endl;
        }
    };
    };

inline Okrag::Okrag(Punkt a, double b) {
    if (b > 0) {
        srodek = a; r = b ;
    }
    // Rzucanie wyjątku gdy złe końce,
    // tzn. poczatek = koniec
    else
        throw Okrag::ZlyPromien(b);
}
}

#endif