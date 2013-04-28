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

all: main testio testgeneration

main : main.o libgraphes.a libprim.a libtests.a | bin
	$(CC) $(CFLAGS) -o $(BPATH)main $(OPATH)main.o $(LFLAGS) -lcunit -ltests -lprim -lgraphes

testio : testio.o io.o libgraphes.a
	$(CC) $(CFLAGS) -o $(BPATH)testio $(OPATH)testio.o $(LFLAGS) -lgraphes

testgeneration : testgeneration.o io.o libgraphes.a
	$(CC) $(CFLAGS) -o $(BPATH)testgeneration $(OPATH)testgeneration.o $(LFLAGS) -lgraphes

testgeneration.o : testgeneration.c testgeneration.h io.h graphe.h generation.h base.h
testio.o : testio.c testio.h io.h graphe.h adjacence.h sommet.h base.h
testprim.o : testprim.c testprim.h prim.h arete.h filearetetriee.h coloration.h graphe.h base.h sommet.h
testfilearetetriee.o : testfilearetetriee.c testfilearetetriee.h filearetetriee.h listearete.h sommet.h arete.h base.h
testgrapheconnexe.o : testgrapheconnexe.c testgrapheconnexe.h grapheconnexe.h parcours.h graphe.h base.h
testparcours.o : testparcours.c testparcours.h base.h sommet.h graphe.h coloration.h parcours.h
testcoloration.o : testcoloration.c testcoloration.h base.h sommet.h graphe.h coloration.h
testgraphe.o : testgraphe.c testgraphe.h base.h graphe.h adjacence.h
testadjacence.o : testadjacence.c testadjacence.h base.h adjacence.h
testlistearete.o : testlistearete.c testlistearete.h listearete.h sommet.h arete.h base.h
testarete.o : testarete.c testarete.h base.h sommet.h arete.h
testsommet.o : testsommet.c testsommet.h base.h sommet.h

edition.o : edition.c edition.h base.h graphe.h io.h parcours.h
prompt.o : prompt.c prompt.h base.h graphe.h grapheconnexe.h io.h prim.h parcours.h edition.h
generation.o : generation.c generation.h graphe.h listearete.h arete.h base.h
io.o : io.c io.h
prim.o : prim.c prim.h base.h sommet.h graphe.h coloration.h filearetetriee.h
filearetetriee.o : filearetetriee.c filearetetriee.h base.h sommet.h arete.h
grapheconnexe.o : grapheconnexe.c grapheconnexe.h parcours.h graphe.h adjacence.h sommet.h base.h
parcours.o : parcours.c parcours.h coloration.h graphe.h sommet.h base.h
coloration.o : coloration.c coloration.h graphe.h sommet.h base.h
graphe.o : graphe.c graphe.h adjacence.h sommet.h base.h
adjacence.o : adjacence.c adjacence.h base.h sommet.h
listearete.o : listearete.c listearete.h arete.h sommet.h base.h
arete.o : arete.c arete.h base.h sommet.h
sommet.o : sommet.c sommet.h base.h
main.o : main.c base.h 

%.o : %.c | obj
	$(CC) $(CFLAGS) -o $(OPATH)$@ -c $< $(IFLAGS)

libgraphes.a : sommet.o adjacence.o arete.o listearete.o graphe.o coloration.o parcours.o grapheconnexe.o io.o generation.o | lib
	ar -crv $(LPATH)libgraphes.a $(OPATH)sommet.o $(OPATH)arete.o $(OPATH)listearete.o $(OPATH)adjacence.o $(OPATH)graphe.o $(OPATH)coloration.o $(OPATH)parcours.o $(OPATH)grapheconnexe.o $(OPATH)io.o $(OPATH)generation.o
	ranlib $(LPATH)libgraphes.a

libprim.a : filearetetriee.o prim.o | lib
	ar -crv $(LPATH)libprim.a $(OPATH)filearetetriee.o $(OPATH)prim.o
	ranlib $(LPATH)libprim.a

libtests.a : testsommet.o testarete.o testlistearete.o testadjacence.o testgraphe.o testcoloration.o testparcours.o testgrapheconnexe.o testfilearetetriee.o testprim.o | lib
	ar -crv $(LPATH)libtests.a $(OPATH)testsommet.o $(OPATH)testarete.o $(OPATH)testlistearete.o $(OPATH)testadjacence.o $(OPATH)testgraphe.o $(OPATH)testcoloration.o $(OPATH)testparcours.o $(OPATH)testgrapheconnexe.o $(OPATH)testfilearetetriee.o $(OPATH)testprim.o
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
