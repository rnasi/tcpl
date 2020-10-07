#include <stdio.h>

void squeeze(char[], const char[]);

void printResult(char str[], const char del[]) {
	printf("\"%s\" minus \"%s\"", str, del);
	squeeze(str, del);
	printf(" equals \"%s\"\n", str);
}

// Write an alternative version of `squeeze(s1,s2)` that deletes each character in `s1` that
// matches any character in the string `s2`.
int main() {
	char str1[] = "Hello world!";
	char str2[] = "HellO world!";
	char str3[] = "Hello world!";
	char str4[] = "";
	char del1[] = "!";
	char del2[] = "aeiouAEOIU";
	char del3[] = "";
	
	printResult(str1, del1);	// Hello world
	printResult(str2, del2);	// Hll wrld!
	printResult(str3, del3);	// Hello world!
	printResult(str4, del2);	// edge case testing
	printResult(str4, del3);	// edge case testing
}

// contains:	Determines if `str` contains `c`
// return:	1 if contained, 0 if not
int contains(const char str[], const char c) {
	int i;
	for(i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return 1;
	return 0;
}

// squeeze:	Removes all occurences in `str` of any character in `delete`
void squeeze(char str[], const char delete[]) {
	int i, j;

	for (i = j = 0; str[i] != '\0'; i++)
		if (!contains(delete, str[i]))
			str[j++] = str[i];
	str[j] = '\0';
}
