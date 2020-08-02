#include "smsh.h"

void redirect(char *src, int srcfd, char *dst, int dstfd, bool is_append, bool is_background) {
	int flag, fd;

	if ( srcfd == 0 && is_background ) {
		strcpy(src, "/dev/null"); // always empty space
		srcfd = CLOSEFD;
	}

	if ( srcfd != 0 ) {
		if ( close(0) == -1 ) {
            perror("close(0) call\n");
        }
		if ( srcfd > 0 ) {
			if ( dup(srcfd) != 0 ) {
                perror("dup(srcfd) call\n");
            }
		} else if ( open(src, O_RDONLY, 0 ) == -1) {
			perror("open(src) call\n");
		}
	}
   
	if ( dstfd != 1 ) {
		if ( close(1) == -1 ) {
            perror("close(1) call\n");
        }
		if ( dstfd > 1 ) {
			if ( dup(dstfd) != 1 ) {
                perror("dup(dstfd) call\n");
            }
		} else {
            if ( is_append ) {
                flag = O_WRONLY | O_CREAT | O_APPEND;
            } else {
                flag = O_WRONLY | O_CREAT | O_TRUNC;
            }
			if ( open(dst, flag, 0644) == -1 ) {
				perror("open(dst) call\n");
			}
		}
	}

   for (fd =3; fd < MAXFD; fd++) close(fd);
   return;
}