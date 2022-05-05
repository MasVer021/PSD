main: main.o item.o queue.o
	gcc main.o item.o queue.o -o main -lm

item.o: item.c
	gcc -c item.c

queue.o: queue.c
	gcc -c queue.c

main.o: main.c item.o queue.o
	gcc -c main.c item.o queue.o

clean:
	rm *o
