* Zawartosc:
============

Katalog zawiera program implementujący figury geometryczne i operacje na nich przy użyciu klas języka C++
--------------------------------------------------------------------------

>> Moduły zawierajacy implementacje figur geometrycznych
    figura.h, figura.cpp
    punkt.h, punkt.cpp
    odcinek.h, odcinek.cpp
    okrag.h, okrag.cpp
    prostokat.h, prostokat.cpp
    trojkat.h, trojkat.cpp

>> Program sklada sie z pojedynczego modulu:    
   main.cpp - program demonstrujacy operacje na figurach
-------------------------------------------------------------------------------

* Jak uruchomic program:
========================

Katalog zawiera plik Makefile do kompilacji, linkowania i przykladowego 
uruchomienia powyzszego programu oraz czyszczenia katalogu i jego archiwizacji.

-> Aby uruchomic program, nalezy wykonac:
     make run

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
     make clean
