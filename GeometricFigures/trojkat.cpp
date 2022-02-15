#include "trojkat.h"

namespace MojeFigury {
    // Funkcja do rysowania trójkąta
    void Trojkat::rysuj(){
        std::cout << "Rysuje trojkat o wierzchołkach w1: " << w1
                  << ", w2: " << w2 << ", w3: " << w3 << std::endl;
    }
    // Funkcja do przesuwania trójkąta o wektor (dx,dy)
    void Trojkat::przesun(double dx, double dy) {
        w1.przesun(dx,dy);
        w2.przesun(dx,dy);
        w3.przesun(dx, dy);
    }
    // Funkcja do skalowania trójkąta
    void Trojkat::skaluj(double s) {
        if (s <= 0) throw Figura::ZlaSkala(s, "Trojkat");
        double x0 = w1.dajX();
        double delx1 = w2.dajX() - x0;
        double y0 = w1.dajY();
        double dely1 = w2.dajY() - y0;

        double delx2 = w3.dajX() - x0;
        double dely2 = w3.dajY() - y0;
        // Nowe współrzędne końca - po przeskalowaniu
        double x1 = x0 + s*delx1;
        double y1 = y0 + s*dely1;
        double x2 = x0 + s*delx2;
        double y2 = y0 + s*dely2;
        w2 = Punkt(x1 ,y1);
        w3 = Punkt(x2, y2);
    }
} // namespace MojeFigury