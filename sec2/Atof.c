#include <stdio.h>
#include <ctype.h>

double atof(char[]);
int atoi(char[]);

int main() {
	char dString1[] = "234.345";
	char dString2[] = "-0.345";
	char dString3[] = "+234";
	char iString[] = "123";

	printf("%f\n", atof(dString1));
	printf("%f\n", atof(dString2));
	printf("%f\n", atof(dString3));
	printf("%f\n", atof(iString));
	
	printf("%d\n", atoi(dString1));
	printf("%d\n", atoi(dString2));
	printf("%d\n", atoi(dString3));
	printf("%d\n", atoi(iString));

	return 0;
}


/*
 * atoi:	convert string `s` into an int
 * return:	int value of string
 */
int atoi(char s[]) {
	double atof(char[]);
	return (int) atof(s);
}


/* 
 * atof:	convert string `s` to double
 * return:	double value of string
 */
double atof(char s[]) {
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)  /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}
