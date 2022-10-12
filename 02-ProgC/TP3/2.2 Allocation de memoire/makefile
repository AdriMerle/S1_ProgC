main: main.o biblio.o
	gcc -o main main.o biblio.o

main.o: main.c
	gcc -c main.c

biblio.o: biblio.c
	gcc -c biblio.c

t1: main
	echo 10 1 2 3 4 5 6 7 8 9 10 | ./main

t2: main
	echo 6 -1 65 56 29 74 -362 | ./main

t3: main
	echo 3 -10 10 0 | ./main

all: main

clean: 
	rm *.o main