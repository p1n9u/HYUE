#include <stdio.h>

double my_sqrt(double num) {
	double sqrt = num-0.1; // 1
	int i;
	for ( i=0; i<100; i++ ) { // i<40
		sqrt=(sqrt+(num/sqrt))/2;
	}
	return sqrt;
}

int main(void) {
	double x;
	printf("input non-negative num : ");
	scanf("%lf", &x);
	printf("\nsqrt(x) = %10lf, sqrt(x)^2 = %.30e\n",
		  my_sqrt(x), my_sqrt(x)*my_sqrt(x));
	return 0;
}