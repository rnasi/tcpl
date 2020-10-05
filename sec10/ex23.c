#include <stdio.h>

#define OUTSIDE		0
#define INSIDE		1
#define MULTI_LINE	1
#define SINGLE_LINE	2

// Removes comments from a C program
int main() {
	int string = OUTSIDE;
	int comment = OUTSIDE;
	int controlChar = OUTSIDE;
	int charConst = OUTSIDE;

	int c;

	while ((c = getchar()) != EOF) {
		if (controlChar == INSIDE) {
			printf("\\%c", c);
			controlChar = OUTSIDE;
		} else if (c == '\\' && comment == OUTSIDE) {
			controlChar = INSIDE;
		} else if (c == '\'' && comment == OUTSIDE && string == OUTSIDE) {
			if (charConst == INSIDE)
				charConst = OUTSIDE;
			else
				charConst = INSIDE;
			putchar(c);
		} else if (c == '"' && comment == OUTSIDE && charConst == OUTSIDE) {
			if (string == INSIDE)
				string = OUTSIDE;
			else
				string = INSIDE;
			putchar(c);
		} else if (c == '/' && string == OUTSIDE) {
			if ((c = getchar()) == '*')
				comment = MULTI_LINE;
			else if (c == '/')
				comment = SINGLE_LINE;
			else
				printf("/%c", c);
		} else
			if (comment == MULTI_LINE && c == '*' && getchar() == '/') {
				comment = OUTSIDE;
			} else if (comment == SINGLE_LINE && c == '\n') {
				comment = OUTSIDE;
				putchar('\n');
			} else if (comment == OUTSIDE) {
				putchar(c);
			}
	}

	
	return 0;
}
