// Write a version of `itoa` that accepts three arguments instead of two. The third argument is a
// minimum field width; the converted number must be padded with blanks on the left if necessary to
// make it wide enough.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE	50

void itoa(int, char[], int);

int main() {
	char intStr[MAX_SIZE];

	itoa(3465, intStr, 10);
	printf("%s\n", intStr);

	itoa(0, intStr, 0);
	printf("%s\n", intStr);

	itoa(-65, intStr, 3);
	printf("%s\n", intStr);

	itoa(65, intStr, 3);
	printf("%s\n", intStr);

	return 0;
}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

int abs(int i) {
	return i < 0 ? -i : i;
}

//itoa:		Writes `n` as a string into `s`, padded out to minimum field width `w` as necessary
//assumptions:	`s` is big enough
void itoa(int n, char s[], int w) {
	int i, negative;

	negative = n < 0;

	// Generate digits in reverse order
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';	// Get next digit
	} while ((n /= 10) != 0);	// Delete it

	if (negative)
		s[i++] = '-';
	while (i < w) {
		s[i++] = ' ';
	}

	s[i] = '\0';
	reverse(s);
}
