#include <stdio.h>
#define MAXLINE	1000

int getLine(char line[], int max);
int strindex(char source[], char searchFor[]);

char pattern[] = "ould";	// What to search for

// Find all lines matching pattern
int main() {
	char line[MAXLINE];
	int found = 0;

	while (getLine(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

//getline:	Read line into `s`
//assumptions:	Size of `s` is at least `lim` + 1
//return:	Length of line
int getLine(char s[], int lim) {
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';;
	return i;
}

//strindex:	Find first occurence of `t` in `s`
//return:	Index of first occurence if found; -1 otherwise
int strindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
