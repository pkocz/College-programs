===============================================================================
Autor: Paweł Koczanowski,                                      Krakow, 05.07.2021
===============================================================================

* Zawartosc:
============

Katalog zawiera implementacje liczb zespolonych w jezyku C++ (w postaci
odpowiedniej klasy i zwiazanych z nia metod, w szczegolosci przeladowanych
operatorow) oraz program demonstrujacy dzialania na nich.
--------------------------------------------------------------------------

>> Modul zawierajacy implementacje liczb zespolonych:
   KlasaZespolone.h - wszystko zawarte jest w pliku naglowkowym 
                      (funkcje typu inline).

>> Program sklada sie z pojedynczego modulu:    
   Zespolone.cpp - program demonstrujacy dzialania na liczbach zespolonych.
-------------------------------------------------------------------------------

* Jak uruchomic program:
========================

Katalog zawiera plik Makefile do kompilacji, linkowania i przykladowego 
uruchomienia powyzszego programu oraz czyszczenia katalogu i jego archiwizacji.

-> Aby uruchomic program, nalezy wykonac:
     make run

-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
     make clean
===============================================================================