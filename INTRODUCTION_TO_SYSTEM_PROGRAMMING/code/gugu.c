#include <stdio.h>

int main(void) {
	int N;
	printf("input N (1~9) : ");
	scanf("%d", &N);

	int i;
	for( i=1; i<=9; i++ ) {
		printf("%d * %d = %d\n", N, i, N*i);		
	}
}