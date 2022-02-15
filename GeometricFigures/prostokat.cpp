#include "prostokat.h"
#include <cmath>

namespace MojeFigury {
    // Funkcja do rysowania prostokata
    void Prostokat::rysuj(){
        std::cout << "Rysuje prostokat o wierzchołkach: w1: " << w1
                  << ", w2: " << Punkt(w1.dajX() + bokA, w1.dajY()) << ", w3: " 
                  << Punkt(w1.dajX(), w1.dajY() - bokB) << ", w4: " 
                  << Punkt(w1.dajX() + bokA, w1.dajY() - bokB) <<std::endl;
    }
    // Funkcja do przesuwania prostokąta o wektor (dx,dy)
    void Prostokat::przesun(double dx, double dy) {
        w1.przesun(dx,dy);
    }
    // Funkcja do skalowania prostokąta
    void Prostokat::skaluj(double s) {
        if (s <= 0) throw Figura::ZlaSkala(s, "Prostokat");
        bokA *= sqrt(s);
        bokB *= sqrt(s);
    }
} // namespace MojeFigury