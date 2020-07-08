#include "smsh.h"

int main(void) {
	int fd, status;
    pid_t pid;
	T_TYPE chk;
    display_welcome();
    display_prompt();
	while (true) {
		chk = process(&pid, false, NULL);
        if ( pid != 0 && chk != T_AMP ) {
            waitpid(pid, &status, 0);
        }
		if (chk == T_EOL) {
            display_prompt();
        }
		for (fd=3; fd<MAXFD; fd++)	close(fd);
	}
}