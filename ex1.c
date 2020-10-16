// Write the function `strindex(s,t)` which returns the position of the rightmost occurrence of `t`
// in `s`, or -1 if there is none. 

#include <stdio.h>
#define MAXLINE	1000

int getLine(char line[], int max);
int strLastIndex(char source[], char searchFor[]);

char pattern[] = "th";	// What to search for

// Find all lines matching pattern & prints matched pattern beneath last occurence in line.
int main() {
	char line[MAXLINE];
	int found = 0;
	int index;

	while (getLine(line, MAXLINE) > 0)
		if ((index = strLastIndex(line, pattern)) >= 0) {
			printf("%s", line);
			for (; index > 0; index--)
				putchar(' ');

			printf("%s\n", pattern);
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

//strLastIndex:	Find last occurence of `t` in `s`
//return:	Index of last occurence if found; -1 otherwise
int strLastIndex(char s[], char t[]) {
	int i, j, k;
	int index = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			index = i;
	}
	return index;
}
