#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#define MAXARGS 31
#define MAXFILENAME 1024
#define MAXPATHSTR 2048

extern char **environ;
int myexeclp(const char *file, const char *args, ...) {
	int argc, i;
	va_list ap;
	
	/* counting argc */
    va_start(ap, args);
    for ( argc = 1; va_arg(ap, const char *); argc++ ) {
        if ( argc == INT_MAX ) {
            va_end(ap);
            errno = E2BIG;
            fprintf(stderr, "argc MAX : %s\n", strerror(errno));
            return -1;
        }
    }
    va_end(ap);
    
    /* get argv from args */
    char *argv[MAXARGS];
    va_start(ap, args);
    argv[0] = (char *)args;
    for ( i = 1; i <= argc; i++ ) {
        argv[i] = va_arg(ap, char *);
    }
    va_end(ap);
    
    /* return call execve() */
	return execve(file, argv, environ);
}

int main(void) {
  char path[MAXPATHSTR];
  sprintf(path, "PATH=%s:%s", getcwd(NULL, 0), getenv("PATH"));
  putenv(path);
  // prepare the executable file named "hello"
  system("cp hello.tmp hello.c");
  system("clang-7 -pthread -lm -o hello hello.c");
  system("rm hello.c");
  myexeclp("hello", "hello", "-a", "-b", "-c", (char *) 0);
  return 0;
}