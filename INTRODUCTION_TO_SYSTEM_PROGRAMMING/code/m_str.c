#include <stdio.h>

char *my_strcat(char *s1, const char *s2) {
	char *ptr = s1;
	while ( *ptr != '\0' ) {
		ptr++;
	}
	while ( *s2 != '\0' ) {
		*ptr++ = *s2++;
	}
	return s1;
}

int my_strcmp(const char *s1, const char *s2) {
	int c;
	c = 0;
	while ( (*s1 != '\0') || (*s2 != '\0') ) {
		if ( *s1 == *s2 ) {
			s1++; s2++;
		} else {
			if ( *s1 > *s2 ) {
				c = 1;
				break;
			} else {
				c = -1;
				break;
			}
		}
	}
	return c;
}

int main(void) {
	char *str1 = "STARBUCKS";
	char str2[10] = "STAR";
	char *str3 = "BUCKS";
	
	my_strcat(str2, str3);
	printf("my_strcat : %s\n", str2);
	
	if (my_strcmp(str1, str2) == 0) {
		printf("Nailed it\n");
	} else {
		printf("my_strcmp(str1, str2) : %d\n", my_strcmp(str1, str2));
	}
	return 0;
}

