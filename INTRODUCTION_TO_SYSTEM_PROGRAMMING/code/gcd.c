#include <stdio.h>

int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b, a%b);
}

int gcdi(int a, int b) {
	while(1) {
		int r = a%b;
		if (r==0) return b;
		a = b;
		b = r;
	}
}

int main(void) {
	printf("gcd(10, 15) = %d\n", gcdi(10, 15));
	printf("gcd(125, 13) = %d\n", gcdi(125, 13));
	printf("gcd(625, 225) = %d\n", gcdi(625, 225));
	printf("gcd(6840, 324) = %d\n", gcdi(6840, 324));
}