// Write the function `itob(n,s,b)` that converts the integer `n` into a base `b` character
// representation in the string `s`. In particular, `itob(n,s,16)` formats `s` as a hexadecimal
// integer in `s`.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE	50

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
	printResult(23, 2);
	printResult(-67543, 16);
	printResult(123, 1);
	printResult(123, 36);

	return 0;
}

//reverse:	reverses string `s`
//assumptions:	`s` is a null-terminated string
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

//abs:		Calculates the absolute value of `i`
//assumptions:	`i` is not INT_MIN
//return:	|i|
int abs(int i) {
	return i < 0 ? -i : i;
}

//itob:		Writes `n` as a string of base `b` (2-35) into `s`
//		If b is not between 2 and 35, sets `s` to empty string
//assumptions:	`s` is big enough
void itob(int n, char s[], int b) {
	if (b > 35 || b < 2) {
		s[0] = '\0';
		return;
	}

	int i, negative;

	negative = n < 0;

	// Generate digits in reverse order
	i = 0;
	do {
		int digit = abs(n % b);
		s[i++] = (digit < 10 ? '0' + digit : 'a' + digit - 10);	// Get next digit
	} while ((n /= b) != 0);				// Delete it

	if (negative)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
