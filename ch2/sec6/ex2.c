#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		// Current line length
	int max;		// Max length seen so far
	char line[MAXLINE];	// Current input line
	char longest[MAXLINE];	// longest line saved here

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
			if (len > max) {
				max = len;
				copy(longest, line);
			}
	if (max > 0)	// There was a line
		printf("%s", longest);

	return 0;
}

// getline:	Read a line into s, return length
int getLine(char s[], int lim) {
	int c, i;

	// All three conditions need to be true in order to keep reading a line, so their sum should be 3
	c = getchar();
	for (i = 0; (i < lim - 1) + (c != EOF) + (c != '\n') == 3; i++) {
		s[i] = c;
		c = getchar();
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';	// Null-terminate the string
	return i;
}

// copy:	copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
