#include "pgm.h"

// 0, 1, 2
void fct1(int n) {
	int i;
	printf("Hello from fct1() %d\n", n);  // 3번
	for ( i=0; i<n; ++i ) {
		fct2(); // 1, 2 - 3번
	}
}

// 0 fct1() printf
// 1 fct1() printf + fct2() printf
// 2 fct1() printf + fct2() printf * 2

void fct2(void) {
	printf("Hello from fct2()\n");
}