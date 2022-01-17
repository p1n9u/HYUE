#include <stdio.h>

int main(void) {
	printf("The size of some fundamental types.\n");
	printf("char:%10lu byte\n", sizeof(char));
	printf("short:%10lu bytes\n", sizeof(short));
	printf("int:%10lu bytes\n", sizeof(int));
	printf("long:%10lu bytes\n", sizeof(long));
	printf("unsigned:%10lu bytes\n", sizeof(unsigned));
	printf("float:%10lu bytes\n", sizeof(float));
	printf("double:%10lu bytes\n", sizeof(double));
	printf("long double:%10lu bytes\n", sizeof(long double));
	return 0;
}