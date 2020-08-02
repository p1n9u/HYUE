#include "smsh.h"

bool shellbuilt(int argc,char *argv[], int srcfd, int dstfd, bool *INC) {
	if ( strcmp(argv[0], "set") == 0 )	{
        if ( argc != 3 ) {
            return false;
        } else {
        
            if ( strcmp(argv[2], "noclobber") == 0 ) {
                if ( strcmp(argv[1], "-o") == 0 ) {
                    *INC = false;
                    printf("set -o >| !\n");
                } else if ( strcmp(argv[1], "+o") == 0 ) {
                    *INC = true;
                    printf("set +o > or >| !\n");
                } else {
                    return false;
                }
            }
        }
    } else if ( strcmp(argv[0], "history") == 0 ) {

    } else if ( strcmp(argv[0], "!") == 0 ) {

    } else if ( strcmp(argv[0], "cd") == 0 ) {
        chdir(argv[1]);
    } else if ( strcmp(argv[0], "exit") == 0 ) {
		exit(0);
	} else {
        return false;
    }
	return true;
}