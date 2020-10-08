#include <stdio.h>

int any(const char[], const char[]);

// Write the function `any(s1,s2)`, which returns the first location in a string `s1` where any
// character from the string `s2` occurs, or -1 if s1 contains no characters from s2. (The
// standard library function `strpbrk` does the same job but returns a pointer to the location.)
int main() {
	char str1[] = "Hello world!";
	char str2[] = "";
	char check1[] = "aeiou";
	char check2[] = "XYZ<>:{}";
	char check3[] = "";

	printf("\"%s\" -- \"%s\"  :  %d\n", str1, check1, any(str1, check1));
	printf("\"%s\" -- \"%s\"  :  %d\n", str1, check2, any(str1, check2));
	printf("\"%s\" -- \"%s\"  :  %d\n", str1, check3, any(str1, check3));
	printf("\"%s\" -- \"%s\"  :  %d\n", str2, check1, any(str2, check1));
	printf("\"%s\" -- \"%s\"  :  %d\n", str2, check3, any(str2, check3));
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

// any:		Checks if any of the chars in str2 are contained in str1
// return:	index of first matching char if any are found, -1 if none found
int any(const char str[], const char delete[]) {
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (contains(delete, str[i]))
			return i;
			
	return -1;
}
