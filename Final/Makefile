update: main.o replace.o 
	gcc -o update main.o replace.o
main.o: main.c replace.h 
	gcc -c main.c
replace.o: replace.c
	gcc -c replace.c