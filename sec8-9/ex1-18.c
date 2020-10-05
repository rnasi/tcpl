#include <stdio.h>

#define MAXLINE 1000

int trimLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		// Current line length
	char line[MAXLINE];	// Current input line

	while ((len = trimLine(line, MAXLINE)) > 0)
		printf("%s", line);

	return 0;
}

// trimline:	Read a line into s, trim whitespace at the end, and return trimmed length. Breaks lines at MAXLENGTH - 2
int trimLine(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
	}
	for (i--; s[i] == ' ' || s[i] == '\t'; i--);	// Go back to first non-whitespace character
	s[++i] = '\n';
	s[i + 1] = '\0';
	return i;
}

// copy:	copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
