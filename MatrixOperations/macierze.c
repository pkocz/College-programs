#include "OperacjeMacierzowe.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_CHAR 100

int main(int argc, char *argv[])
{
    const int n = 3;
    FILE *daneA, *daneB, *daneV, *daneC, *wyniki;

    double A[n][n];
    double B[n][n];
    double C[n][n];
    double T[n][n];
    double V[n];
    double VM[n];
    double *c;
    double liczba;
    c = &liczba;

    char tekst[20];
    char *nazwa;
    nazwa = tekst;

    char *nazwy[] = {"Transpozycja", "Dodawanie", "Odejmowanie", "Mnożenie", "WektorMacierz", "MacierzLiczba"};
    

    if (argc != 6)
    {
        printf("Zła liczba plików.");
        exit(1);
    }
    assert((daneA = fopen(argv[1] ,"r")) != NULL);
    assert((daneB = fopen(argv[2] ,"r")) != NULL);
    assert((daneV = fopen(argv[3] ,"r")) != NULL);
    assert((daneC = fopen(argv[4] ,"r")) != NULL);
    assert((wyniki = fopen(argv[5] ,"w")) != NULL);


    assert(czytajMacierz(daneA, nazwa, n, A));
    assert(wypiszMacierz(wyniki, nazwa, n, A));

    assert(czytajMacierz(daneB, nazwa, n, B));
    assert(wypiszMacierz(wyniki, nazwa, n, B));

    assert(czytajWektor(daneV, nazwa, n, V));
    assert(wypiszWektor(wyniki, nazwa, n, V));

    assert(czytajLiczbe(daneC, nazwa, c));
    assert(wypiszLiczbe(wyniki, nazwa, liczba));

    transponujMacierz(n, A, T);
    assert(wypiszMacierz(wyniki, nazwy[0], n, T));

    dodajMacierze(n, A, B, C);
    assert(wypiszMacierz(wyniki, nazwy[1], n, C));

    odejmijMacierze(n, A, B, C);
    assert(wypiszMacierz(wyniki, nazwy[2], n, C));

    mnozMacierze(n, A, B, C);
    assert(wypiszMacierz(wyniki, nazwy[3], n, C));

    mnozMacierzWektor(n, A, V, VM);
    assert(wypiszWektor(wyniki, nazwy[4], n, VM));

    mnozLiczbaMacierz(n, liczba, A, C);
    assert(wypiszMacierz(wyniki, nazwy[5], n, C));

    assert(fclose(daneA) != EOF);
    assert(fclose(daneB) != EOF);
    assert(fclose(daneC) != EOF);
    assert(fclose(daneV) != EOF);
    assert(fclose(wyniki) != EOF);

}