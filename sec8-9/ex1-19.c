#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main() {
	int len;		// Current line length
	int max;		// Max length seen so far
	char line[MAXLINE];	// Current input line
	char toPrint[MAXLINE];	// line to print

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0) {
		reverse(toPrint, line, len);				// Reverse moves newline to beginning.
		printf("%s\n", (char*) (toPrint + sizeof(char))); 	// Ignore it and put line break at the end
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

// reverse:	reverse 'from' into 'to' given 'len'; assume 'to' is big enough
void reverse(char to[], char from[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		to[len - i - 1] = from[i];
	}
	to[len] = '\0';
}
