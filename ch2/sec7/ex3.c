#include <stdio.h>
#include <ctype.h>

int htoi(const char[]);

int main() {
	char hex1[] = "3f";
	char hex2[] = "0x5A1e";
	char hex3[] = "0XaF10";

	printf("%s to decimal is %d\n", hex1, htoi(hex1));
	printf("%s to decimal is %d\n", hex2, htoi(hex2));
	printf("%s to decimal is %d\n", hex3, htoi(hex3));
	
	return 0;
}

// hdigit:	calculates the int value of a single hexadecimal digit
// return:	int value, or -1 if the character is not a valid hex digit
int htoiDigit(int c) {
	if (isdigit(c))
		return c - '0';
	else if (c >= 'a' && c <= 'f')
		return 10 + c - 'a';
	else if (c >= 'A' && c <= 'F')
		return 10 + c - 'A';
	else
		return -1;
}

// htoi:	converts hex string into deciman
// return:	int value of given hex string, or 0 if not valid
int htoi(const char hexStr[]) {
	int intVal, hexDigit, i;
	intVal = i = 0;

	// Ignore prefix
	if (hexStr[0] == '0' && (hexStr[1] == 'x' || hexStr[1] == 'X'))
		i = 2;
		
	while ((hexDigit = htoiDigit(hexStr[i])) >= 0) {
		intVal = 16 * intVal + hexDigit;
		i++;
	}

	return intVal;
}


