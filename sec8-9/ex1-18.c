#include <stdio.h>

#define MAXLINE 100

int trimLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		// Current line length
	char line[MAXLINE];	// Current input line

	while ((len = trimLine(line, MAXLINE)) > 0)
		printf("%s", line);

	return 0;
}

// trimline:	Read a line into s, trim whitespace at the end, and return trimmed length. Truncates if over MAXLINE
int trimLine(char s[], int lim) {
	int c, len;

	for (len = 0; len < lim - 2 && (c = getchar()) != EOF && c != '\n'; len++)
		s[len] = c;
	if (c == '\n') {
		s[len] = c;
		len++;
	} else 
		while ((c = getchar()) != EOF && c != '\n');	// Truncate the rest of the line

	if (len > 1) {
		for (len = len - 2; s[len] == ' ' || s[len] == '\t'; len--);	// Go back to first non-whitespace character
		s[++len] = '\n';
	}
	s[len + 1] = '\0';
	return len;
}

// copy:	copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
