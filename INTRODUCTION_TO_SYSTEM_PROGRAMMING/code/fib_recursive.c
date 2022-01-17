#include <stdio.h>

int fib(int x) {
	if ( x == 0 ) {
		return 0;
	} else if ( x == 1 ) {
		return 1;
	} else {
		return ( fib(x-2) + fib(x-1) );
	}
}

// 0 1 1 2 3 5 8
int main(void) {
	int n;
	printf("input n : ");
	scanf("%d", &n);
	printf("fib(%d) is %d\n", n, fib(n));
	return 0;
}

