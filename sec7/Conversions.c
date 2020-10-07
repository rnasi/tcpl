#include <stdio.h>

int atoi(const char numStr[]);
int lower(const int c);

// Playing with various type conversion functions
int main() {
	char numStr[] = "123";
	char upperCase = 'R';
	
	printf("%s is the same as %d\n", numStr, atoi(numStr));
	printf("%c to lower case is %c\n", upperCase, lower(upperCase));

	return 0;
}

// atoi:	converts a string to an integer
// return:	the `int` value of the string when read as a decimal number
int atoi(const char numStr[]) {
	int i, n;

	n = 0;
	for (i = 0; numStr[i] >= '0' && numStr[i] <= '9'; i++)
		n = 10 * n + (numStr[i] - '0');

	return n;
}

// lower:	convert char to lower case
// assumptions:	using ASCII character set
// return:	upper-case character
int lower(const int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
