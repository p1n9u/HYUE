#include "pgm.h" // 1. main() 함수가 실행되기전 먼저 수행됨


// 2. main() 실행
int main(void) {
	char ans;
	int i, n = N;
	printf("%s",
		   "This Program does not do very much.\n"
		   "Do you want more information?");
	scanf(" %c", &ans);
	if (ans == 'y' || ans == 'Y')
		wrt_info("pgm");
	for ( i=0; i<N; ++i )
		fct1(i); // 3번 실행 fct1() 0, 1, 2
	printf("Bye!\n");
	return 0; 
}