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

all: main testio

main : main.o libgraphes.a libprim.a libtests.a | bin
	$(CC) $(CFLAGS) -o $(BPATH)main $(OPATH)main.o $(LFLAGS) -lcunit -ltests -lprim -lgraphes

testio : testio.o io.o libgraphes.a
	$(CC) $(CFLAGS) -o $(BPATH)main $(OPATH)testio.o $(OPATH)io.o $(LFLAGS) -lgraphes

testio.o : testio.c testio.h io.h graphe.h liste.h sommet.h base.h
testprim.o : testprim.c testprim.h prim.h arete.h filetriee.h coloration.h graphe.h base.h sommet.h
testfiletriee.o : testfiletriee.c testfiletriee.h filetriee.h sommet.h arete.h base.h
testgrapheconnexe.o : testgrapheconnexe.c testgrapheconnexe.h grapheconnexe.h parcours.h graphe.h base.h
testparcours.o : testparcours.c testparcours.h base.h sommet.h graphe.h coloration.h parcours.h
testcoloration.o : testcoloration.c testcoloration.h base.h sommet.h graphe.h coloration.h
testgraphe.o : testgraphe.c testgraphe.h base.h graphe.h liste.h
testliste.o : testliste.c testliste.h base.h liste.h
testarete.o : testarete.c testarete.h base.h sommet.h arete.h
testsommet.o : testsommet.c testsommet.h base.h sommet.h

io.o : io.c io.h sommet.h graphe.h liste.h base.h
prim.o : prim.c prim.h base.h sommet.h graphe.h coloration.h filetriee.h
filetriee.o : filetriee.c filetriee.h base.h sommet.h arete.h
grapheconnexe.o : grapheconnexe.c grapheconnexe.h parcours.h graphe.h liste.h sommet.h base.h
parcours.o : parcours.c parcours.h coloration.h graphe.h sommet.h base.h
coloration.o : coloration.c coloration.h graphe.h sommet.h base.h
graphe.o : graphe.c graphe.h liste.h sommet.h base.h
liste.o : liste.c liste.h base.h sommet.h
arete.o : arete.c arete.h base.h sommet.h
sommet.o : sommet.c sommet.h base.h
main.o : main.c base.h 


%.o : %.c | obj
	$(CC) $(CFLAGS) -o $(OPATH)$@ -c $< $(IFLAGS)

libgraphes.a : sommet.o liste.o graphe.o coloration.o parcours.o grapheconnexe.o | lib
	ar -crv $(LPATH)libgraphes.a $(OPATH)sommet.o $(OPATH)liste.o $(OPATH)graphe.o $(OPATH)coloration.o $(OPATH)parcours.o $(OPATH)grapheconnexe.o
	ranlib $(LPATH)libgraphes.a

libprim.a : arete.o filetriee.o prim.o | lib
	ar -crv $(LPATH)libprim.a $(OPATH)arete.o $(OPATH)filetriee.o $(OPATH)prim.o
	ranlib $(LPATH)libprim.a

libtests.a : testsommet.o testarete.o testliste.o testgraphe.o testcoloration.o testparcours.o testgrapheconnexe.o testfiletriee.o testprim.o | lib
	ar -crv $(LPATH)libtests.a $(OPATH)testsommet.o $(OPATH)testarete.o $(OPATH)testliste.o $(OPATH)testgraphe.o $(OPATH)testcoloration.o $(OPATH)testparcours.o $(OPATH)testgrapheconnexe.o $(OPATH)testfiletriee.o $(OPATH)testprim.o
	ranlib $(LPATH)libtests.a

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
