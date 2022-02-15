KATBIEZ = `basename $(PWD)`
# Nazwy rdzeniowe plikow
GLOWNY = macierze
FUNKCJE = OperacjeMacierzowe
# Nazwy plikow zrodlowych
GLOZRO = $(GLOWNY).c
FUNZRO = $(FUNKCJE).c
# Pliki skompilowane
GLOKOM = $(GLOWNY).o
FUNKOM = $(FUNKCJE).o
# Pliki naglowkowe
FUNNAG = $(FUNKCJE).h
# Plik wykonawczy
GLOWYK = $(GLOWNY).x
# Plik danych
A = A.txt
B = B.txt
V = V.txt
C = c.txt
# Plik wynikow
WYNIKI = wynik.txt
# Kompilator
KOMP = gcc
# Opcje kompilatora
KOMOP = -Wall
# Linker
LINKER = $(KOMP)
# Opcje linkera
LINOP = -Wall
# Regula all - bedzie uruchamiana po wykonaniu make bez argumentow.
# Tu oznacza utworzenie pliku wykonawczego.
all: $(GLOWYK)
# Reguly dla kompilacji:
# 1. Plik z funkcjami
$(FUNKOM): $(FUNZRO)
	$(KOMP) $(KOMOP) $(FUNZRO) -c
# 2. Plik z programem glownym: zalezy tez od pliku naglowkowego
$(GLOKOM): $(GLOZRO) $(FUNNAG)
	$(KOMP) $(KOMOP) $(GLOZRO) -c
# Regula dla linkowania:
$(GLOWYK): $(GLOKOM) $(FUNKOM)
	$(LINKER) $(LINOP) -o $(GLOWYK) $(GLOKOM) $(FUNKOM)
run: $(GLOWYK)
	./$(GLOWYK) $(A) $(B) $(V) $(C) $(WYNIKI)
# Regula do czyszczenia katalogu
clean:
	rm -f a.out *~ *.o *.x