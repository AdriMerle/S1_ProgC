td: td.o
	gcc -o td td.o;

td.o: td_2-3.c;
	gcc -o td.o -c td_2-3.c;

t1: td
	echo 10 7 | ./td

t2: td
	echo 20 6 | ./td