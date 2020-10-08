#include <stdio.h>

// replaces characters with escaped sequences
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '\t':
				printf("\\t");
				break;
			case '\n':
				printf("\\n");
				break;
			case '\\':
				printf("\\\\");
				break;
			default:
				putchar(c);
				break;
		}
	}
}
