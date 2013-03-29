CC = gcc
CFLAGS = -Wall -g -pedantic -std=c99
IFLAGS = -Iinclude
LFLAGS = -L/usr/lib -Llib

OPATH = obj/
BPATH = bin/
LPATH = lib/

vpath %.c src/
vpath %.h include/
vpath %.o obj/
vpath main bin/
vpath %.a lib/

main : main.o libgraphes.a | bin
	$(CC) $(CFLAGS) $(LFLAGS) -o $(BPATH)main $(OPATH)main.o -lgraphes

grapheconnexe.o : grapheconnexe.c grapheconnexe.h parcours.h graphe.h liste.h sommet.h base.h
parcours.o : parcours.c parcours.h coloration.h graphe.h sommet.h base.h
coloration.o : coloration.c coloration.h graphe.h sommet.h base.h
graphe.o : graphe.c graphe.h liste.h sommet.h base.h
liste.o : liste.c liste.h base.h sommet.h
sommet.o : sommet.c sommet.h base.h
main.o : main.c base.h 

%.o : %.c | obj
	$(CC) $(CFLAGS) -o $(OPATH)$@ -c $< $(IFLAGS)

libgraphes.a : sommet.o liste.o graphe.o coloration.o parcours.o grapheconnexe.o | lib
	ar -crv $(LPATH)libgraphes.a $(OPATH)sommet.o $(OPATH)liste.o $(OPATH)graphe.o $(OPATH)coloration.o $(OPATH)parcours.o $(OPATH)grapheconnexe.o
	ranlib $(LPATH)libgraphes.a

obj :
	mkdir obj

lib :
	mkdir lib

bin :
	mkdir bin

clean :
	rm obj/* bin/*

cleanall : clean
	rm -r doc/*

archive :
	tar -f meyer_razanajato-ProjetSDA2P.tar.gz -cvz src/*.c include/*.h makefile Doxyfile
