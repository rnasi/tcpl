#include <stdio.h>

int lower(int c);

// Rewrite the function `lower`, which converts upper case letters to lower case, with a
// conditional expression instead of if-else.
int main() {
	char str[] = "tHIS iS a strING that I waNT to bE ALl loWEr CaSe!";
	char lowerStr[60];

	int i; 
	for (i = 0; str[i] != '\0'; i++)
		lowerStr[i] = lower(str[i]);
	str[i] = '\0';

	printf("%s\n", lowerStr);
}

// lower:	Converts `c` into lower case
// return:	Lower case equivalent of `c` if it is a capital letter, or `c` otherwise
int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
