KATBIEZ = `basename $(PWD)`
# Plik głowny
GLOWNY = Zespolone
# Plik zrodlowy
GLOZRO = $(GLOWNY).cpp
# Plik skompilowany
GLOKOM = $(GLOWNY).o
# Plik naglowkowy
FUNNAG = KlasaZespolone.h
# Plik wykonawczy
GLOWYK = $(GLOWNY).x
# Plik danych
DANEA = A.txt
# Plik wynikow
WYNIKI = wyniki.txt
# Kompilator
KOMP = g++
# Opcje kompilatora
KOMOP = -Wall
# Linker
LINKER = $(KOMP)
# Opcje linkera
LINOP = -Wall
all: $(GLOWYK)
# Regula dla kompilacji:
$(GLOKOM): $(GLOZRO) $(FUNNAG)
	$(KOMP) $(KOMOP) $(GLOZRO) -c
# Regula dla linkowania:
$(GLOWYK): $(GLOKOM)
	$(LINKER) $(LINOP) -o $(GLOWYK) $(GLOKOM)
# Uruchamianie programu
run: $(GLOWYK)
	./$(GLOWYK) $(DANEA) $(WYNIKI)
# Regula do czyszczenia katalogu
clean:
	rm -f a.out *~ *.o *. *.x