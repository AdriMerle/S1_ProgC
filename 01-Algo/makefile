all: td
	./td

td: td.o
	gcc -o td td.o

td.o: td_6.c
	gcc -o td.o -c td_6.c

debug: td_6.c
	gcc -o td -g td_6.c