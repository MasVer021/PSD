
main: main.o item.o BST.o
		gcc main.o item.o BST.o -o main -lm

BST.o: BST.c
		gcc -c BST.c

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
