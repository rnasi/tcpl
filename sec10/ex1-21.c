#include <stdio.h>

#define TAB_LENGTH	8

// entab: replaces spaces with tabs when possible
int main() {
	int c;
	int buffer[TAB_LENGTH + 1];
	int linePosition = 0;
	int spaceCount = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n') {
			putchar('\n');
			linePosition = 0;
			spaceCount = 0;
		} else if (c == ' ') {
			spaceCount++;
			linePosition++;

			//We have more than one space and have reached a tab position; put in a tab
			if (spaceCount > 2 && TAB_LENGTH * (linePosition / TAB_LENGTH) == linePosition) {
				putchar('\t');
				spaceCount = 0;
			}

		} else {
			// We have untabbable spaces--flush them to output
			while (spaceCount > 0) {
				putchar(' ');
				spaceCount--;
			}

			putchar(c);	
			linePosition++;
		}

	return 0;
}
