#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void moving_sign(char, char, char, char);
void print_sign(int);

int main(void) {
	moving_sign('H', 'E', 'Y', ' ');
	return 0;
}

void print_sign(int a) {
	printf(" %c %c %c %c \n",
			a/(256*256*256), a/(256*256), a/256, a);
}

void moving_sign(char _a, char _b, char _c, char _d) {
	char a = _a, b = _b, c = _c, d = _d, tmp;
	int p = a; // _ _ _ H
	p = (p << CHAR_BIT) | b; // _ _ H E
	p = (p << CHAR_BIT) | c; // _ H E Y
	p = (p << CHAR_BIT) | d; // H E Y _
	while (1) {
		system("clear");
		print_sign(p);
		sleep(1);

		int n = 3*CHAR_BIT; // 24-bits

		// 00000000 00000000 00000000 11111111
		unsigned mask = 255;
		
		// 11111111 00000000 00000000 00000000
		mask <<= n;

		// p&mask : '최상위문자 ascii' 00000000 00000000 00000000
		// >> n : 00000000 00000000 00000000 '최상위문자 ascii'
		tmp = (p&mask) >> n;
        
		// H E Y _ -> E Y _ _ -> E Y _ H
		// 한 칸씩 밀고 마지막에 tmp 추가
		p = (p << CHAR_BIT) | tmp;
	}
}