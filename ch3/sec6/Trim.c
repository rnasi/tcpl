#include <stdio.h>
#include <string.h>

int trim(char[]);

void printTrimmed(char str[]) {
	printf("\"%s\"\n", str);
	int length = trim(str);
	printf("\"%s\" is now trimmed and %d chars long\n", str, length);
}

int main() {
	char str1[] = "This needs to be trimmed!   \t\n\n\t";
	char str2[] = "    \t\t\n\n \n\t";
	char str3[] = "";

	printTrimmed(str1);
	printTrimmed(str2);
	printTrimmed(str3);
	
	return 0;
}

//trim:		Trims the whitespace off the end of `s`
//assumptions:	`s` is a null-terminated string
//return:	The new length of the string
int trim(char s[]) {
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[++n] = '\0';
	return n;
}
