pgm : pgm.h main.o fct.o wrt.o
	gcc -o pgm pgm.h main.o fct.o wrt.o

main.o : main.c
	gcc -c -o main.o main.c

fct.o : fct.c
	gcc -c -o fct.o fct.c

wrt.o : wrt.c
	gcc -c -o wrt.o wrt.c

clean :
	rm *.o pgm

			