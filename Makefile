#Makefile

all: minish

minish: minish.o main.o
	gcc -o minish minish.o main.o

minish.o: minish.c
	gcc -o minish.o -c minish.c -W -Wall -ansi -pedantic

main.o: main.c minish.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
