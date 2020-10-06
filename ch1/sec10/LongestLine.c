#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine();
void copy();

int main() {
	int len;		// Current line length
	extern int max;		// Max length seen so far
	extern char longest[MAXLINE];	// longest line saved here

	max = 0;
	while ((len = getLine()) > 0)
		if (len > max) {
			max = len;
			copy();
		}

	if (max > 0)	// There was a line
		printf("%s", longest);

	return 0;
}

// getline:	Read a line into s, return length
int getLine() {
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';	// Null-terminate the string
	return i;
}

// copy:	copy 'line' into 'longest'
void copy() {
	int i = 0;
	extern char line[], longest[];
	while ((longest[i] = line[i]) != '\0')
		i++;
}
