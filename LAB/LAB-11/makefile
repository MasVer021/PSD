main1: main.o item.o Btree.o queue.o
	gcc main.o item.o Btree.o  queue.o -o main -lm


main2: main_2.o item.o BST.o
		gcc main_2.o item.o BST.o -o main -lm


main_2.o: main_2.c
		gcc -c main_2.c

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
