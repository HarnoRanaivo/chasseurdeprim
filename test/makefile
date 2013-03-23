CC = gcc
CFLAGS = -Wall -g
IFLAGS = -Iinclude -I../include
LFLAGS = -L/usr/lib

OPATH = obj/
BPATH = bin/

vpath %.c src/ ../src/
vpath %.h include/ ../include/
vpath %.o obj/
vpath main bin/

main : main.o testsommet.o sommet.o testliste.o liste.o | bin
	$(CC) $(CFLAGS) -o $(BPATH)main $(OPATH)main.o $(OPATH)testsommet.o $(OPATH)sommet.o $(OPATH)testliste.o $(OPATH)liste.o $(LFLAGS) -lcunit

testgraphe.o : testgraphe.c testgraphe.h base.h graphe.h
testliste.o : testliste.c testliste.h base.h liste.h
testsommet.o : testsommet.c testsommet.h base.h sommet.h
graphe.o : graphe.c graphe.h liste.h sommet.h base.h
liste.o : liste.c liste.h sommet.h base.h
sommet.o : sommet.c sommet.h base.h
main.o : main.c base.h testsommet.h testliste.h

%.o : %.c | obj
	$(CC) $(CFLAGS) -o $(OPATH)$@ -c $< $(IFLAGS)

obj :
	mkdir obj

bin :
	mkdir bin

clean :
	rm obj/* bin/*

cleanall : clean
	rm -r doc/*
