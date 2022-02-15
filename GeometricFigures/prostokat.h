#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include "figura.h"
#include "punkt.h" 

namespace MojeFigury {
    // Klasa Prostokat – dziedziczy po klasie Figura
    class Prostokat: public Figura {
        Punkt w1; // Lewy górny wierzchołek
        double bokA, bokB; // Boki wychodzące z w1
    public:
        // Konstruktor, w tym domyślny (przykładowy)
        Prostokat(Punkt d = Punkt(0,1), double a = 1, double b = 1);
        // Funkcja do rysowania prostokąta w oknie
        void rysuj(void);
        // Funkcja do przesuwania prostokąta
        void przesun(double, double);
        // Funkcja do skalowania prostokąta
        void skaluj(double);
    class ZleBoki {
        double bokA2, bokB2; // boki
    public:
        // Konstruktor
        ZleBoki(double a, double b): bokA2(a), bokB2(b) {}
        // Zwróć długości boków
        void dajBoki(double& a, double& b) const
        { a = bokA2; b = bokB2; }
        // Komunikat
        void Komunikat() const
        {
            std::cerr << "Bok prostokąta <= 0" << std::endl;
        }
    };
    };

inline Prostokat::Prostokat(Punkt d, double a, double b) {
    if (a > 0 && b > 0) {
        bokA = a; bokB = b; w1 = d;
    }
    // Rzucanie wyjątku gdy ktorys z bokow jest ujemny
    else
        throw Prostokat::ZleBoki(a, b);
}
}

#endif