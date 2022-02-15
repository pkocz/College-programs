#ifndef ODCINEK_H
#define ODCINEK_H

#include "figura.h"
#include "punkt.h" 

namespace MojeFigury {
    // Klasa Odcinek – dziedziczy po klasie Figura
    class Odcinek: public Figura {
        Punkt poczatek, koniec; // Punkty początkowy i końcowy
    public:
        // Konstruktor, w tym domyślny (przykładowy)
        Odcinek(Punkt a = Punkt(0,1), Punkt b = Punkt(0,0));
        // Funkcja do rysowania odcinka w oknie
        void rysuj(void);
        // Funkcja do przesuwania odcinka
        void przesun(double, double);
        // Funkcja do skalowania odcinka
        void skaluj(double);
    class ZleKonce {
        Punkt p, k; // konce odcinka
    public:
        // Konstruktor
        ZleKonce(Punkt a, Punkt b): p(a), k(b) {}
        // Zwróć końce odcinka
        void dajKonce(Punkt& a, Punkt& b) const
        { a = p; b = k; }
        // Komunikat
        void Komunikat() const
        {
            std::cerr << "\n* Wyjatek: class Odcinek: poczatek"
                      << p << " = koniec" << k << std::endl;
        }
    };
    };

inline Odcinek::Odcinek(Punkt a, Punkt b) {
    if (a != b) {
        poczatek = a; koniec = b ;
    }
    // Rzucanie wyjątku gdy złe końce,
    // tzn. poczatek = koniec
    else
        throw Odcinek::ZleKonce(a, b);
}
}

#endif