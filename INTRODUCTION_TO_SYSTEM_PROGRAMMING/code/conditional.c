#include <stdio.h>

int main(void) {
	int N;
	printf("input integer & press enter\n");
	printf("input N : ");
	scanf("%d", &N);

	if ( N == 0 ) {
		printf("false\n");
	} else {
		printf("true\n");
	}

	return 0;
}

