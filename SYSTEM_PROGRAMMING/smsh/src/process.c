#include "smsh.h"

T_TYPE process(pid_t *pid, bool is_pipe, int *pipfdptr) {
    pid_t p;
    bool INC;
	T_TYPE tok, chk;
    int i, cmdc, is_clg, argc, srcfd, dstfd;
	int pipfd[2], vs[MAXCLG];
	char dst[MAXFILE], src[MAXFILE];
    char *argv[MAXARG+1];
	char vector[MAXVEC];
	bool is_append;
    bool is_background;

    is_clg = 0; argc = 0; cmdc = 1; srcfd = 0; dstfd = 1; INC = true;

	while (true) {

		switch ( tok = get_tok(vector, &is_clg) ) {

			case T_ARG :

				if (argc == MAXARG) {
					fprintf(stderr, "MAXARG CALL\n");
					break;
				}

				argv[argc] = (char *)malloc(strlen(vector)+1);
				
				if (argv[argc] == NULL) {
					fprintf(stderr, "ARGV MALLOC CALL\n");
					break;
				}

				strcpy(argv[argc], vector);
				argc++;
				continue;

			case T_INR :

				if ( is_pipe ) {
					perror("inred <> pip call\n");
				}

				if ( get_tok(src, &is_clg) != T_ARG ) {
					perror("src not vector call\n");
				}

				srcfd = CLOSEFD;
				continue;

			case T_OTA :
			case T_OTR : 
            case T_INC :

				if ( dstfd != 1 ) {
					break;
				}

				if ( get_tok(dst, &is_clg ) != T_ARG ) {
					perror("dst not vector call\n");
				}

				dstfd = CLOSEFD;
                if ( tok == T_OTA) {
                    is_append = true;
                }
				continue;

            case T_SEM :

                if ( is_clg > 0 ) {
                    vs[cmdc-1] = argc;
                    cmdc++;
                    continue;
                }

			case T_PIP  :
			case T_AMP  :
			case T_EOL   :
            
                if ( cmdc > 1 ) {
                    vs[cmdc-1] = argc;
                }

				argv[argc] = NULL;
				if ( tok == T_PIP ) {
					if (dstfd != 1) {
						break;
					}
					chk = process(pid, true, &dstfd);
				} else {
					chk = tok;
                }

				if ( is_pipe ) {
					if ( pipe(pipfd) == -1 ) {
                        perror("pipe call\n");
                    }
					*pipfdptr = pipfd[1];
					srcfd = pipfd[0];
				}

                if ( chk == T_AMP ) {
                    is_background = true;
                } else {
                    is_background = false;
                }

				p = exec_argv(argc, argv, src, srcfd, dst, dstfd, is_append, is_background, cmdc, vs, &INC);
                if ( tok != T_PIP ) {
                    *pid = p;
                }
				if (argc == 0 && (tok != T_EOL || srcfd > 1))
					fprintf(stderr, "cmd err\n");

				while (--argc >= 0)	free(argv[argc]);

				return chk;

			case T_EOF : 
				exit(0);
		} 
	}    
}