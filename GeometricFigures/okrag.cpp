#include "okrag.h"
#include <cmath>

namespace MojeFigury {
    // Funkcja do rysowania odcinka
    void Okrag::rysuj(){
        std::cout << "Rysuje okrag o srodku" << srodek
                  << " i promieniu " << r << std::endl;
    }
    // Funkcja do przesuwania okręgu o wektor (dx,dy)
    void Okrag::przesun(double dx, double dy) {
        srodek.przesun(dx,dy);
    }
    // Funkcja do skalowania okręgu
    void Okrag::skaluj(double s) {
        if (s <= 0) throw Figura::ZlaSkala(s, "Okrag");
        // Nowy promien okręgu po przeskalowaniu
        r *= sqrt(s);
    }
} // namespace MojeFigury