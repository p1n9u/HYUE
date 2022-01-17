#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i, n, seed;
	seed = time(NULL);
	srand(seed);
	printf("n : ");
	scanf("%d", &n);
	for ( i=0; i<n; i++ ) {
		if ( i%10 == 0 ) {
			putchar('\n');
		}
		printf("%5d", rand()%100+1);
	}
	printf("\n");
	return 0;
}