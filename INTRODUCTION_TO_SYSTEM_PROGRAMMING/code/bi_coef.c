#include <stdio.h>

int bi_coef(int, int);

int main(void) {
	int a, b;
	printf("n, k : ");
	scanf("%d %d", &a, &b);
	printf("%d C %d == %d\n", a, b, bi_coef(a, b));
	return 0;
}

int bi_coef(int n, int k) {

}