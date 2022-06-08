main: main.o item.o PQueue.o list.o
	gcc main.o item.o PQueue.o list.o -o main -lm

item.o: item.c
	gcc -c item.c

PQueue.o: PQueue.c
	gcc -c PQueue.c

list.o: list.c
		gcc -c list.c


main.o: main.c item.o PQueue.o
	gcc -c main.c item.o PQueue.o

clean:
	rm *o
