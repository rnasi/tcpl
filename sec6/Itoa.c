#include <stdio.h>
#include <string.h>

#define MAX_SIZE	20

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int, char[]);

int main() {
	char intStr[MAX_SIZE];

	itoa(3465, intStr);

	printf("%s\n", intStr);

	itoa(0, intStr);

	printf("%s\n", intStr);

	itoa(-65, intStr);

	printf("%s\n", intStr);

        itoa( (( (unsigned) ~0 ) >> 1) + 1, intStr);
 
        printf("%s\n", intStr);

	return 0;
}

void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)	// Record sign
		n = -n;		// Make `n` positive

	// Generate digits in reverse order
	i = 0;
	do {
		s[i++] = n % 10 + '0';	// Get next digit
	} while ((n /= 10) > 0);	// Delete it

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

