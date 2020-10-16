#include <stdio.h>
#include <ctype.h>

int atoi(char[]);

int main() {

	char numStr1[] = "123";
	char numStr2[] = "  123";
	char numStr3[] = "123T-kr543";
	char numStr4[] = " -123";
	char numStr[] = "uiresgyo";

	printf("\"%s\" to int is %d\n", numStr1, atoi(numStr1));
	printf("\"%s\" to int is %d\n", numStr2, atoi(numStr2));
	printf("\"%s\" to int is %d\n", numStr3, atoi(numStr3));
	printf("\"%s\" to int is %d\n", numStr4, atoi(numStr4));
	printf("\"%s\" to int is %d\n", numStr5, atoi(numStr5));

	return 0;
}

//atoi:		convert s to integer, taking sign into account and stopping at first non-number
//return:	converted int
int atoi(char s[]) {
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++);	// Skip white space
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')		// Skip sign
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
