main: main.o item.o queue.o Btree.o stack.o list.o
	gcc main.o item.o queue.o Btree.o stack.o list.o -o main -lm

list.o: list.c
		gcc -c list.c

stack.o: stack.c
		gcc -c stack.c

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
