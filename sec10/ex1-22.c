#include <stdio.h>

#define SCREEN_WIDTH	80
#define MAX_WIDTH	1000

int getLine(char line[], int limit);
int wrapLine(char line[], int length, int screenWidth, int maxLength);

int main() {
	char line[MAX_WIDTH];
	int length;

	while ((length = getLine(line, MAX_WIDTH)) > 0) {
		int statusCode;
		if ((statusCode = wrapLine(line, length, SCREEN_WIDTH, MAX_WIDTH)) != 0)
			return statusCode;
		printf("%s", line);
	}
	
	return 0;
}

// getLine: Copies input into 'line' until 'limit' or a newline is reached
// ret: length of line
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

// wrapLine: inserts newlines at first blank before 'screenWidth'. Wraps unbroken lines at 
// 	'screenWidth'
// ret: status code	0 - OK
// 			1 - Max length exceeded. Since a character is added to the string when a
// 				line has no whitespace, we need to make sure the wrapped string 
// 				does not exceed the max width.
int wrapLine(char line[], int length, int screenWidth, int maxLength) {
	int i = screenWidth;

	while (i < length) {
		int j;
		// Find last space in the line before the screen width
		for (j = 0; line[i - j] != ' ' && j < screenWidth; j++);

		// There were no spaces before screen width; need to insert one
		if (j == screenWidth) {
			if (length < maxLength - 1) {
				// Increment length, shift array over, insert newline
				length++;
				int k;
				for (k = length; k > i; k--)
					line[k] = line[k - 1];

				line[i] = '\n';
				line[length + 1] = '\0';
				i += screenWidth + 1;
			} else
				return 1; // Max length exceeded

		// There was a space; make it a newline
		} else {
			line[i - j] = '\n';
			i = i - j + screenWidth;
		}
	}

	return 0;
}
