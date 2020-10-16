#include <stdio.h>

// replaces escape sequences with the actual character
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\\') {
			switch (c = getchar()) {
				case '\\':
					putchar('\\');	
					break;
				case 'n':
					putchar('\n');
					break;
				case 't':
					printf("\t");
					break;
				default:
					putchar('\\');
					putchar(c);
					break;
			}	
		} else {
			putchar(c);
		}
	}
	
	return 0;
}
