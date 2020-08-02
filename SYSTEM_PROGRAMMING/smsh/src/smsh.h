#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

/* define MAXVAL */
#define MAXFILE 255
#define MAXARG 32
#define MAXVEC 32
#define MAXFD 32
#define MAXCLG 16
#define CLOSEFD (-1)

/* typedef */
typedef int T_TYPE;
typedef int T_STAT;

/* TYPE : type of token */
#define T_AMP 1 // '&'
#define T_SEM 2 // ';'
#define T_OTR 3// '>'
#define T_INC 4 // '>|'
#define T_OTA 5 // '>>'
#define T_INR 6 // '<'
#define T_PIP 7 // '|'
#define T_DQT 8 // '"'
#define T_ARG 9 // argument
#define T_EOL 10 // '\n'
#define T_EOF 11 // end of file
#define T_STR 12 // start
#define T_CLG 13 // '('

/* STAT */
#define S_NRM 0
#define S_OTR 1
#define S_DQT 2
#define S_ARG 3
#define S_CLG 4

/* prompt color set motivated by oh-my-zsh agnosterzak 현재 사용중인 쉘 */
#define COLOR_CWD "\e[100;97m" // fg: bright white bg: bright gray
#define COLOR_USR "\e[103;95m" // fg: bright magenta bg: bright yellow
#define COLOR_TIM "\e[104;97m" // fg: bright white bg: bright blue
#define COLOR_WLC "\e[0;91m" // bright red
#define COLOR_HLP "\e[0;92m" // bright green
#define COLOR_RST "\e[0m" // reset

/* fucn proto type */

/* make sh */
T_TYPE process(pid_t *pid, bool is_pipe, int *pipfdptr);
T_TYPE get_tok(char *vector, int *is_clg);
pid_t exec_argv(int argc, char *argv[], char *src, int srcfd, char *dst, int dstfd, bool is_append, bool is_background, int cmdc, int vs[], bool *INC);
void redirect(char *src, int srcfd, char *dst, int dstfd, bool is_append, bool is_background);
bool shellbuilt(int argc,char *argv[], int srcfd, int dstfd, bool *INC);

/* util.c */
void display_welcome();
void display_time();
void display_cwd();
void display_line();
void display_prompt();

