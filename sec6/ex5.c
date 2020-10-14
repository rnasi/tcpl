// Write the function `itob(n,s,b)` that converts the integer `n` into a base `b` character
// representation in the string `s`. In particular, `itob(n,s,16)` formats `s` as a hexadecimal
// integer in `s`.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE	50

void reverse(char s[]) {
	int c, i, j;

}

void itob(int n, char s[], int b);

void printResult(int n, int b) {
	char intStr[MAX_SIZE];
	itob(n, intStr, b);
	printf("%d to string in base %d: %s\n", n, b, intStr);
}

int main() {
	printResult(285430, 10);
	printResult(285430, 16);
	printResult(654, 35);
	printResult(5, 1);
	printResult(23, 2);
	printResult(-67543, 16);

	return 0;
}

int abs(int i) {
	return i < 0 ? -i : i;
}

//itob:		Writes `n` as a string of base `b` (1-35) into `s`
//		If b is not between 1 and 35, does nothing
//assumptions:	`s` is big enough
void itob(int n, char s[], int b) {
	if (b > 35 || b < 1)
		return;

	int i, negative;

	negative = n < 0;

	// Generate digits in reverse order
	i = 0;
	do {
		int digit = abs(n % b) + '0';
		s[i++] = (digit < 10 ? '0' : 'a') + digit;	// Get next digit
	} while ((n /= b) != 0);				// Delete it

	if (negative)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
