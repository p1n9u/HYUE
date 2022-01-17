#include <stdio.h>

int fac(int x) {
	if ( x == 0 ) {
		return 1;
	} else {
		return (x*fac(x-1));
	}
}


int main(void) {
	int n;
	printf("input n : ");
	scanf("%d", &n);
	printf("%d! is %d\n", n, fac(n));
	return 0;
}

