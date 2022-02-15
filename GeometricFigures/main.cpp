#include <iostream>

#include "odcinek.h"
#include "trojkat.h"
#include "prostokat.h"
#include "okrag.h"

using namespace MojeFigury;
using namespace std;

int main() {
    
    Punkt a, b, c;
    a = Punkt(1, 1);
    b = Punkt(2,1);
    c = Punkt(3, 3);
    double przesuniecieX, przesuniecieY, skala, bokA, bokB, promien;
    bokA = 2;
    bokB = 3;
    promien = 2;
    przesuniecieX = 2;
    przesuniecieY = 3;
    skala = 0.5;

    try {
        Odcinek od = Odcinek(a, b);
        Trojkat tr = Trojkat(a, b, c);
        Prostokat pr = Prostokat(a, bokA, bokB);
        Okrag ok = Okrag(a, promien);

        od.rysuj();
        tr.rysuj();
        pr.rysuj();
        ok.rysuj();

        cout << endl << "Przesunięcie figur o wektor dx = " << przesuniecieX << " i dy = " << przesuniecieY << endl;
        od.przesun(przesuniecieX, przesuniecieY);
        tr.przesun(przesuniecieX, przesuniecieY);
        pr.przesun(przesuniecieX, przesuniecieY);
        ok.przesun(przesuniecieX, przesuniecieY);
        od.rysuj();
        tr.rysuj();
        pr.rysuj();
        ok.rysuj();

        cout << endl << "Skalowanie figur o s = " << skala << endl;
        od.skaluj(skala);
        tr.skaluj(skala);
        pr.skaluj(skala);
        ok.skaluj(skala);
        od.rysuj();
        tr.rysuj();
        pr.rysuj();
        ok.rysuj();

        // Dynamiczny przydział pamięci

        cout << endl <<  "Te same operacje ale przy użyciu tablicy wskaźników." << endl;
        Odcinek* od2 = new Odcinek(a, b);
        Trojkat* tr2 = new Trojkat(a, b, c);
        Prostokat* pr2 = new Prostokat(a, bokA, bokB);
        Okrag* ok2 = new Okrag(a, promien);

        Figura* fig[4];
        fig[0] = od2; fig[1] = tr2; fig[2] = pr2; fig[3] = ok2;

        for(int i = 0; i < 4; ++i)
        {
            fig[i]->rysuj();
            fig[i]->przesun(przesuniecieX,przesuniecieY);
            fig[i]->skaluj(skala);
            fig[i]->rysuj();
        }
        
        delete od2; od2 = 0;
        delete tr2; tr2 = 0;
        delete pr2; pr2 = 0;
        delete ok2; ok2 = 0;


    } catch (Odcinek::ZleKonce& zk) {
        zk.Komunikat();
    } catch (Trojkat::ZlePunkty& zw) {
        zw.Komunikat();
    } catch (Prostokat::ZleBoki& zb) {
        zb.Komunikat();
    } catch (Okrag::ZlyPromien& zp) {
        zp.Komunikat();
    } catch (Figura::ZlaSkala& zs) {
        zs.Komunikat();
    } catch (...) {
        cerr << "Nieznany wyjątek" << endl;
        exit(1);
    }

return 0;
}