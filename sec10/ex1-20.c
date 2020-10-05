#include <stdio.h>

#define TAB_LENGTH	8

// detab: replaces tabs with spaces given defined tab length
int main() {
	int c;
	int linePosition = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n') {
			putchar('\n');
			linePosition = 0;
		} else if (c == '\t') {
			do {
				putchar(' ');
				linePosition++;
			} while (TAB_LENGTH * (linePosition / TAB_LENGTH) != linePosition);
		} else {
			putchar(c);	
			linePosition++;
		}

	return 0;
}
