main : main.o utile.o utile.h punto.o punto.h
	gcc  main.o utile.o utile.h punto.o punto.h -o main -lm

main.o:  main.c
	gcc main.c -c


utile.o: utile.c
	gcc utile.c -c

punto.o: punto.c
	gcc punto.c -c -lm

clear:
	rm *.o
