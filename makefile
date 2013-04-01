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

main : main.o libgraphes.a libprim.a io.o | bin
	$(CC) $(CFLAGS) $(LFLAGS) -o $(BPATH)main $(OPATH)main.o -lprim -lgraphes

io.o : io.c io.h
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
