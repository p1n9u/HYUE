#include "smsh.h"

T_TYPE get_tok(char *vector, int *is_clg) {
	T_STAT state;
	int c;
	char *v;
	
	state = S_NRM; v = vector;

	while ((c = getchar()) != EOF) {
		switch (state) {

			case S_NRM :

				switch (c) {
                    case '(' : 
                        (*is_clg)++; continue;
                    case ')' : 
                        (*is_clg)--; continue;
                    case '&' : 
                        return T_AMP;
					case ';' : 
                        return T_SEM;
					case '>' : 
						state = S_OTR;
						continue;
                    case '<' : 
                        return T_INR;
					case '|' : 
                        return T_PIP;
                    case '"' : 
						state = S_DQT;
						continue;
					case '\n': 
                        return T_EOL;
					case ' ' :
					case '\t': 
                        continue;
					default  : 
						state = S_ARG;
						*v++ = c;
						continue;
				}

			case S_OTR:
                
				if ( c == '>' ) { 
                    /* append */
                    return T_OTA;
                } else if ( c == '|' ) {
                    return T_INC;
                } else {
				    ungetc(c, stdin);
				    return T_OTR;
                }

			case S_DQT:

				switch (c) {
                    case '"'  : 
						*v = '\0';
						return T_ARG;
					case '\\' : 
						*v++ = getchar();
						continue;
					default   : 
						*v++ = c;
						continue;
				}

			case S_ARG:

				switch ( c ) {
                    case '&' :
					case ';' :
					case '>' :
                    case '<' :
					case '|' :
					case '\n':
					case ' ' :
					case '\t': 
						ungetc(c, stdin);
						*v = '\0';
						return T_ARG;
					default  : 
						*v++ = c;
						continue;
				}
		}
	}
   return T_EOF;
}