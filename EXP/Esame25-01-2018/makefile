main: item.o list.o main.o
	gcc item.o list.o main.o -o main -lm

item.o: item.c item.h
	gcc -c item.c

list.o: list.c list.h
	gcc -c list.c


main.o: main.c
	gcc -c main.c

clean:
	rm *.o
