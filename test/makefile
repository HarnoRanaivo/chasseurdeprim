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

main : main.o testsommet.o sommet.o | bin
	$(CC) $(CFLAGS) -o $(BPATH)main $(OPATH)main.o $(OPATH)testsommet.o $(OPATH)sommet.o $(LFLAGS) -lcunit

testsommet.o : testsommet.c testsommet.h base.h sommet.h
sommet.o : sommet.c sommet.h base.h
main.o : main.c base.h 

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
