main: main.o biblio.o
	gcc -o main main.o biblio.o

main.o: main.c
	gcc -c main.c

biblio.o: biblio.c
	gcc -c biblio.c

t1: main
	echo 1 2 | ./main

t2: main
	echo 1.2 3.4 5.6 7.8 | ./main

t3: main
	echo 1 2 3 4 | ./main

clean: 
	rm *.o main