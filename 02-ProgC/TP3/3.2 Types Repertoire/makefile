main: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c main.c

t1: main
	echo Chloe 0658396786 Baptiste 0689632145 Antonin 0636541278 | ./main

t2: main
	cat input.txt | ./main

clean: 
	rm *.o main