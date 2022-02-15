#include <iostream>
#include <string>

#ifndef FIGURA_H
#define FIGURA_H

namespace MojeFigury {
    class Figura { // Klasa abstrakcyjna Figura
    public:
    // Czysto wirtualny destruktor
    virtual ~Figura() = 0;
    // Funkcja czysto wirtualna do rysowania figur
    virtual void rysuj(void) = 0;
    // Funkcja czysto wirtualna do przesuwania figur
    virtual void przesun(double, double) = 0;
    // Funkcja czysto wirtualna do skalowania figur
    virtual void skaluj(double) = 0;
    // Zagnieżdżona klasa do obsługi wyjątków dla funkcji skaluj
    class ZlaSkala {
        double s; // skala
        std::string gdzie; // miejsce zgłoszenia wyjątku: klasa
    public:
        // Konstruktor
        ZlaSkala(double x=0,std::string opis=""): s(x),gdzie(opis){}
        // Zwróć skalę
        float dajSkale() const { return s; }
        // Komunikat
        void Komunikat() const {
            std::cerr << "\nWyjatek w funkcji skaluj dla klasy: "
                    << gdzie << ": zla skala s = " << s << std::endl;
        }
    }; // class ZlaSkala
    }; // class Figura

    inline Figura::~Figura() {}
}

#endif
