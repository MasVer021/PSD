main: item.o list.o stack.o main.o
	gcc item.o list.o stack.o main.o -o main -lm

item.o: item.c item.h
	gcc -c item.c

list.o: list.c list.h
	gcc -c list.c

stack.o: stack.c stack.h
	gcc -c stack.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o
