merge : merge.o funct.o funct.h
	gcc  merge.o funct.o funct.h -o merge

merge.o : merge.c
	gcc  -c merge.c

funct.o : funct.c
	gcc  -c funct.c

ordina : ordina.o funct.o funct.h
	gcc  ordina.o funct.o funct.h -o ordina

ordina.o : ordina.c
	gcc  -c ordina.c

vocCons : vocCons.o funct.o funct.h
	gcc  vocCons.o funct.o funct.h -o vocCons

vocCons.o : vocCons.c
	gcc  -c vocCons.c



clear:
	rm *.o
