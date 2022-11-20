all: td
	./td

td: td.o
	gcc -o td td.o

td.o: ex_sacados_2.c
	gcc -o td.o -c ex_sacados_2.c

debug: ex_sacados_2.c
	gcc -o td -g ex_sacados_2.c