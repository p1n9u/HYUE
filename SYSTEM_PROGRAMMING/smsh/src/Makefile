all: smsh

smsh.o:	smsh.c smsh.h
	gcc -c smsh.c

get_tok.o:	get_tok.c smsh.h
	gcc -c get_tok.c

process.o:	process.c smsh.h
	gcc -c process.c

exec.o:	exec.c smsh.h
	gcc -c exec.c

redirect.o:	redirect.c smsh.h
	gcc -c redirect.c

shellbuilt.o : shellbuilt.c smsh.h
	gcc -c shellbuilt.c

util.o: util.c smsh.h
	gcc -c util.c

smsh: smsh.o get_tok.o process.o exec.o redirect.o shellbuilt.o util.o
	gcc -o smsh smsh.o get_tok.o process.o exec.o redirect.o shellbuilt.o util.o

clean:
	rm *.o smsh
