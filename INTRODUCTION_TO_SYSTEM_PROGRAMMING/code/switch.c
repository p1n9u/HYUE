#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch;
	printf("Type character...\n");
	while(1) {
		ch = tolower(getchar());
		if (ch=='q') break;
		switch (ch) {
			case 'a':
				printf("You Typed a.\n");
				break;
			case 'b':
				printf("You Typed b.\n");
				break;
			case 0x63:
				printf("You Typed c.\n");
				break;
			case 0x1b:
				printf("You Typed ESC.\n");
				break;
		}
	}
}