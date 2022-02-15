KATBIEZ = `basename $(PWD)`
# Plik głowny
GLOWNY = main
# Plik zrodlowy
GLOZRO = $(GLOWNY).cpp
# Plik skompilowany
GLOKOM = $(GLOWNY).o
# Plik wykonawczy
GLOWYK = $(GLOWNY).x
# Biblioteka
BIBSTAT = libFigury.a
BIBKOM = odcinek.o trojkat.o prostokat.o okrag.o
AR = ar # archiwizer
AROP = rsv # Opcje archiwizera
# Kompilator
KOMP = g++
# Opcje kompilatora
KOMOP = -Wall
# Linker
LINKER = $(KOMP)
# Opcje linkera
LINOP = -Wall
# Tworzenie biblioteki statycznej:
$(BIBSTAT): $(BIBKOM)
	$(AR) $(AROP) $@ $?
all: $(GLOWYK)
# Regula dla kompilacji:
$(GLOKOM): $(GLOZRO) $(FUNNAG)
	$(KOMP) $(KOMOP) $(GLOZRO) -c
# Regula dla linkowania:
$(GLOWYK): $(GLOKOM) $(BIBSTAT)
	$(LINKER) -o $@ $(LINOP) $^
# Uruchamianie programu
run: $(GLOWYK)
	./$(GLOWYK)
# Regula do czyszczenia katalogu
clean:
	rm -f a.out *~ *.o *. *.x *.a