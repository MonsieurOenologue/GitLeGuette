#Makefile

all: minish

minish: minish.o main.o
	gcc -pthread -o minish minish.o main.o

minish.o: minish.c
	gcc -o minish.o -c minish.c -W -Wall -pedantic

main.o: main.c minish.h
	gcc -o main.o -c main.c -W -Wall -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf minish
