main: main.o biblio.o
	gcc -o main main.o biblio.o -g

main.o: main.c
	gcc -c main.c -g

biblio.o: biblio.c
	gcc -c biblio.c -g

test: main
	echo 1 2 3 4 5 6 7 8 9 10 | ./main

test2: main
	echo -10 10 0 | ./main

all: main

clean: 
	rm *.o main