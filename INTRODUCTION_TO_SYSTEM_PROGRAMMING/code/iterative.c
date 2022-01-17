#include <stdio.h>

int main(void) {
	int i;
	int f_result = 0, w_result = 0;

	for ( i=0; i<10; i++ ) {
		f_result += i;
	}

	i=0;
	while ( i<10 ) {
		w_result += i;
		i++;
	}

	printf("f_result : %d\nw_result: %d\n", f_result, w_result);
	return 0;
}

