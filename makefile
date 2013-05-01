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

main : main.o libgraphes.a libprim.a prompt.o edition.o script.o | bin
	$(CC) $(CFLAGS) $(LFLAGS) -o $(BPATH)chasseurdeprim $(OPATH)main.o $(OPATH)prompt.o $(OPATH)edition.o $(OPATH)script.o -lprim -lgraphes

script.o : script.c script.h edition.h prompt.h
edition.o : edition.c edition.h base.h graphe.h io.h parcours.h
prompt.o : prompt.c prompt.h base.h graphe.h grapheconnexe.h io.h prim.h parcours.h edition.h
generation.o : generation.c generation.h graphe.h listearete.h arete.h base.h
io.o : io.c io.h
prim.o : prim.c prim.h base.h sommet.h graphe.h coloration.h filearetetriee.h
filearetetriee.o : filearetetriee.c filearetetriee.h base.h sommet.h arete.h listearete.h
grapheconnexe.o : grapheconnexe.c grapheconnexe.h parcours.h graphe.h adjacence.h sommet.h base.h
parcours.o : parcours.c parcours.h coloration.h graphe.h sommet.h base.h
coloration.o : coloration.c coloration.h graphe.h sommet.h base.h
graphe.o : graphe.c graphe.h adjacence.h sommet.h base.h
adjacence.o : adjacence.c adjacence.h base.h sommet.h
listearete.o : listearete.c listearete.h arete.h sommet.h base.h
arete.o : arete.c arete.h base.h sommet.h
sommet.o : sommet.c sommet.h base.h
main.o : main.c base.h generation.h prompt.h io.h script.h

%.o : %.c | obj
	$(CC) $(CFLAGS) -o $(OPATH)$@ -c $< $(IFLAGS)

libgraphes.a : sommet.o adjacence.o arete.o listearete.o graphe.o coloration.o parcours.o grapheconnexe.o io.o generation.o | lib
	ar -crv $(LPATH)libgraphes.a $(OPATH)sommet.o $(OPATH)arete.o $(OPATH)listearete.o $(OPATH)adjacence.o $(OPATH)graphe.o $(OPATH)coloration.o $(OPATH)parcours.o $(OPATH)grapheconnexe.o $(OPATH)io.o $(OPATH)generation.o
	ranlib $(LPATH)libgraphes.a

libprim.a : filearetetriee.o prim.o | lib
	ar -crv $(LPATH)libprim.a $(OPATH)filearetetriee.o $(OPATH)prim.o
	ranlib $(LPATH)libprim.a

obj :
	mkdir obj

lib :
	mkdir lib

bin :
	mkdir bin

clean :
	rm -f obj/* bin/* lib/*

cleanall : clean
	rm -rf doc/*

archive :
	tar -f meyer_razanajato-ProjetSDA2P.tar.gz -cvz src/*.c include/*.h makefile Doxyfile exemple*
