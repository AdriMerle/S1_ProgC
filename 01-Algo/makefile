all: td
	./td

td: td.o
	gcc -o td td.o

td.o: td_5_liste.c
	gcc -o td.o -c td_5_liste.c

debug: td_5_liste.c
	gcc -o td -g td_5_liste.c