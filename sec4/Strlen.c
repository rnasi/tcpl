#include <stdio.h>

int strLen(const char str[]);
int badStrLen(const char str[]);

int main() {
	char hello[] = "Hello world!";

	printf("The length of \"%s\" is: %d", hello, strLen(hello));
//	printf("The length of \"%s\" is: %d", hello, badStrLen(hello));
}

// Determines the length of a string
// assumptions:	`str` is null-terminated
// returns:	the length of the string
int strLen(const char str[]) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

// Same as above, but tries to change a `const` parameter. 
// For `gcc` on Mac we get this compile-time error:
// Strlen.c:27:11: error: read-only variable is not assignable
//                 str[len]++;
/*
int badStrLen(const char str[]) {
	int len = 0;
	while (str[len] != '\0') {
		str[len]++;
		len++;
	}
	return len;
}
*/
