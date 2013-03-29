CC = gcc
CFLAGS = -Wall -g -pedantic -std=c99
IFLAGS = -Iinclude -I../include
LFLAGS = -L/usr/lib -Llib

OPATH = obj/
BPATH = bin/
LPATH = lib/

vpath %.c src/ ../src/
vpath %.h include/ ../include/
vpath %.o obj/
vpath main bin/

main : main.o libgraphes.a testsommet.o testliste.o testgraphe.o testcoloration.o testparcours.o | bin
	$(CC) $(CFLAGS) -o $(BPATH)main $(OPATH)main.o $(OPATH)testsommet.o $(OPATH)testliste.o $(OPATH)testgraphe.o $(OPATH)testcoloration.o $(OPATH)testparcours.o $(LFLAGS) -lcunit -lgraphes

testparcours.o : testparcours.c testparcours.h base.h sommet.h graphe.h coloration.h parcours.h
testcoloration.o : testcoloration.c testcoloration.h base.h sommet.h graphe.h coloration.h
testgraphe.o : testgraphe.c testgraphe.h base.h graphe.h liste.h
testliste.o : testliste.c testliste.h base.h liste.h
testsommet.o : testsommet.c testsommet.h base.h sommet.h

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
	rm obj/* lib/* bin/*

cleanall : clean
	rm -r doc/*
