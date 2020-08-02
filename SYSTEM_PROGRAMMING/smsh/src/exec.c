#include "smsh.h"

pid_t exec_argv(int argc, char *argv[], char *src, int srcfd, char *dst, int dstfd, bool is_append, bool is_background, int cmdc, int vs[], bool *INC) {
	pid_t pid;
    int i, j, k, status;
    bool chk;

	if ( argc == 0 || shellbuilt(argc, argv, srcfd, dstfd, INC) ) {
        return 0;
    }
    /*
    if ( *INC == false ) {
        printf("cannot overwrite : %s, %s\n", src, dst);
    }
    */
    
    if ( cmdc > 1 ) {

        char *vm[cmdc][MAXARG+1];
        k=0;
        for ( i=0; i<cmdc ; i++ ) {
            chk = true; j = 0;
            while ( chk ) {
                if ( i == 0 ) {
                    if ( j == vs[i] ) {
                        vm[i][j] = NULL;
                        chk = false;
                        continue;
                    }
                } else {
                    if ( j == (vs[i] - vs[i-1]) ) {
                        vm[i][j] = NULL;
                        chk = false;
                        continue;
                    }
                }
                vm[i][j] = argv[k];
                j++;
                k++;
            }
        }

        for ( i=0; i<cmdc; i++ ) {
            pid = fork();
            if ( pid < 0 ) {
                perror("fork call\n");
            } else if (pid ==0) {
                if ( i != 0 ) {
                    is_append = true;
                }
                redirect(src, srcfd, dst, dstfd, is_append, is_background);
			    execvp(vm[i][0], vm[i]);
                perror("execvp call\n");
            } else {
                if (srcfd > 0 && close(srcfd) == -1)
			        perror("close sourcefd");

		        if (dstfd > 1 && close(dstfd) == -1)
			        perror("close destfd");

		        if ( is_background ) {
                    printf("%d\n", pid);
                } else {
                    wait(NULL);
                }
            }
        }
		return pid;

    } else {

	    pid = fork();
        if ( pid < 0 ) {
            perror("fork call\n");
        } else if ( pid == 0 ) {
            redirect(src, srcfd, dst, dstfd, is_append, is_background);
			execvp(argv[0], argv);
			perror("execvp call\n");
        } else {
            if (srcfd > 0 && close(srcfd) == -1) {
				perror("close sourcefd");
            }
			if (dstfd > 1 && close(dstfd) == -1) {
				perror("close destfd");
            }
			if ( is_background ) {
                printf("%d\n", pid);
            }
			return pid;
        }	
	}
}