main: main.o item.o queue.o Btree.o
	gcc main.o item.o queue.o Btree.o -o main -lm


Btree.o: Btree.c
		gcc -c Btree.c

item.o: item.c
	gcc -c item.c

queue.o: queue.c
	gcc -c queue.c

main.o: main.c
	gcc -c main.c

clear:
	rm *o
