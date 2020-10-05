#include <stdio.h>

#define MAXLINE 10

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
		printf("%d: %s", max, longest);
	if (max >= MAXLINE)
		printf("...\n");
	else
		putchar('\n');

	return 0;
}

// getline:	Read a line into s, return length
int getLine(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		i++;
	}

	if (i == lim - 1 && c != '\n') {
		s[i] = '\0';					// Null-terminate the string
		while ((c = getchar()) != EOF && c != '\n')	// Keep counting 
			i++;
	} else
		s[i] = '\0';	// Null-terminate the string

	return i;
}

// copy:	copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
