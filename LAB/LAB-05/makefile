main: main.o item.o list.o utile.o
	gcc main.o item.o list.o utile.o -o main -lm

item.o: item.c
	gcc -c item.c

list.o: list.c
	gcc -c list.c

main.o: main.c item.o list.o utile.o
	gcc -c main.c item.o list.o utile.o

utile.o: utile.c
	gcc -c utile.c

clean:
	rm *o
