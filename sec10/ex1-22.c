#include <stdio.h>

#define SCREEN_WIDTH	10
#define MAX_WIDTH	1000

int getLine(char line[], int limit);
void wrapLine(char line[], int length, int screenWidth);

int main() {
	char line[MAX_WIDTH];
	int length;

	while ((length = getLine(line, MAX_WIDTH)) > 0) {
		wrapLine(line, length, SCREEN_WIDTH);
		printf("%s", line);
	}
	
	return 0;
}

// getLine: Copies input into 'line' until 'limit' or a newline is reached and returns length
int getLine(char line[], int limit) {
	int c;
	int length = 0;

	while(length < limit - 1 && (c = getchar()) != '\n' && c != EOF) {
		line[length] = c;
		length++;
	}

	if (c == '\n') {
		line[length] = '\n';
		length++;
	}
	
	line[length] = '\0';
	return length;
}

// wrapLine: inserts newlines at first blank before 'screenWidth'. wraps unbroken lines at 'screenWidth'
void wrapLine(char line[], int length, int screenWidth) {
	int i = screenWidth;

	while (i < length) {
		int j;
		for (j = 1; line[i - j] != ' ' && j < screenWidth; j++);
		if (j == screenWidth)
			;// something
		else
			line[i - j] = '\n';

//		printf("%d  %d\n", i, j);
		i = i - j + screenWidth;
	}
}
