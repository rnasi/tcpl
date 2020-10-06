#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		// Current line length
	char line[MAXLINE];	// Current input line

	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 80)
			printf("%s", line);
	}

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

	s[i] = '\0';	// Null-terminate the string
	return i;
}

// copy:	copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
