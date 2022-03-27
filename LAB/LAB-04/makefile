main: libro.h libro.o utile.o utile.h main.o
	gcc main.o utile.o libro.o -o main -lm

libro.o: libro.c libro.h
	gcc -c libro.c

utile.o: utile.c
	gcc utile.c -c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o
