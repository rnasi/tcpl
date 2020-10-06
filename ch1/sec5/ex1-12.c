#include <stdio.h>

#define IN	1  // inside a word
#define OUT	0  // outside a word

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			while (c == ' ' || c == '\n' || c == '\t') 
				c = getchar();
			putchar('\n');
			putchar(c);
		} else {
			putchar(c);
		}
	}

	return 0;
}
