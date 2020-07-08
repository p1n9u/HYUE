#include "smsh.h"

void display_welcome() {
    printf(COLOR_WLC "WELCOME! - This message is printed only once.\n");
    printf("SHELL BUILTIN COMMANDS : 'cd' 'exit'\n" COLOR_RST);
}

void display_time() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf(COLOR_TIM " %d월 %d일 %d:%d:%d " COLOR_RST, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void display_cwd() {
    char cwd[MAXFILE];
    if ( getcwd(cwd, sizeof(cwd)) == NULL ) {
            perror("getcwd call\n");
        }
    printf(COLOR_CWD " %s " COLOR_RST "\n", cwd);
}

void display_line() {
    printf(COLOR_USR " input command > " COLOR_RST " ");
}

void display_prompt() {
    display_time(); display_cwd(); display_line(); fflush(stdout);
}