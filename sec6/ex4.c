// In a two’s complement number representation, our version of `itoa` does not handle the largest
// negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it 
// to print that value correctly, regardless of themachine on which it runs. 
//
//
//   The two's complement system solves the problems of a one's complement system by subtracting 1 
// after inverting all the digits to make a number negative. This has the result of disambiguating
// 11...1 and 00...0 from both representing 0, by shifting all the negative numbers down and making
// 11...1 equal to -1. This means that the range of numbers that can be represented by any word 
// length always has one more negative number than positive. Therefore, reversing the largest
// possible negative number in the line:
// 	n = -n;
// will cause overflow.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE	50

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

int abs(int i) {
	return i < 0 ? -i : i;
}

void itoa(int n, char s[]) {
	int i, negative;

	negative = n < 0;

	// Generate digits in reverse order
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';	// Get next digit
	} while ((n /= 10) != 0);	// Delete it

	if (negative)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
