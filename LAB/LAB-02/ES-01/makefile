testunit : run_test_ordina_array.o utile.o utile.h vettore.o vettore.h
	gcc run_test_ordina_array.o utile.o utile.h vettore.o vettore.h -o testunit

run_test_ordina_array.o:  run_test_ordina_array.c
	gcc run_test_ordina_array.c -c

utile.o: utile.c
	gcc utile.c -c

vettore.o: vettore.c
	gcc vettore.c -c

clear:
	rm *.o
