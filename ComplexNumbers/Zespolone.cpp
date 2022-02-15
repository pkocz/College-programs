#include <iostream>
#include <fstream>
#include <cstdlib>
#include <complex>
#include "KlasaZespolone.h"
using namespace std;
using namespace zesp;


int main(int argc, char* argv[])
{
    Zespolone x, y;
    
    ifstream czytaj(argv[1]);
    if (!czytaj)
        { cerr << "Error loading file: " << argv[1] << endl; exit(1);}
    
    ofstream pisz(argv[2]);
    if (!pisz)
        { cerr << "Error loading files: " << argv[2] << endl; exit(2);}

    czytaj >> x >> y;

    pisz << "x = " << x << " y = " << y << endl; 
    pisz << "Dodawanie = " << x + y << endl;
    pisz << "Odejmowanie = " << x - y << endl;
    pisz << "Mnożenie = " << x * y << endl;
    pisz << "Dzielenie = " << x / y << endl;
    pisz << "Minus = " << -x << endl;
    pisz << "x += 2  = " << (x += 2.0) << endl;
    pisz << "x -= 2  = " << (x -= 2.0) << endl;
    pisz << "x *= 2  = " << (x *= 2) << endl;
    pisz << "x /= 2  = " << (x /= 2.0) << endl;
    pisz << "!x = " << !x << endl;
    pisz << "moduł x = " << x.mod() << endl;
    pisz << "faza x = " << x.arg() << endl;
    pisz << "sprzężenie x = " << x.conj() << endl;
    pisz << "Relacja  x == y: " << (x == y) << endl;
    pisz << "Relacja  x != y: " << (x != y) << endl;


    //Sprawdzenie wyników z biblioteką complex
    complex<double> z1(x.re(),x.im()), z2(y.re(),y.im());
    pisz << "Wyniki dla biblioteki complex:" << endl;
    pisz << "x = " << z1 << " y = " << z2 << endl;
    pisz << "Dodawanie = " << z1 + z2 << endl;
    pisz << "Odejmowanie = " << z1 - z2 << endl;
    pisz << "Mnożenie = " << z1 * z2 << endl;
    pisz << "Dzielenie = " << z1 / z2 << endl;
    pisz << "z1 += 2  = " << (z1 += 2.0) << endl;
    pisz << "z1 -= 2  = " << (z1 -= 2.0) << endl;
    pisz << "z1 *= 2  = " << (z1 *= 2.0) << endl;
    pisz << "z1 /= 2  = " << (z1 /= 2.0) << endl;
    pisz << "moduł z1 = " << abs(z1) << endl;
    pisz << "faza z1 = " << arg(z1) << endl;
    pisz << "sprzężenie z1 = " << conj(z1) << endl;
    pisz << "Relacja  z1 == z2: " << (z1 == z2) << endl;

    
    pisz << "Sprawdzenie operatorów ++ i --" << endl;
    pisz << "x = " << x << endl;
    y = x++;
    pisz << "y = x++ = " << y << endl;
    pisz << "x = " << x << endl;
    y = x--;
    pisz << "y = x-- = " << y << endl;
    pisz << "x = " << x << endl;



    return 0;
}