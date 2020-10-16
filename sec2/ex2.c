/*
 * Extend `atof` to handle scientific notation of the form
 * 	123.45e-6
 * where a floating-point number may be followed by 'e' or 'E' and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

double atof(char[]);

int main() {
	char dString1[] = "234.345e+0";
	char dString2[] = "-0.345e-3";
	char dString3[] = "+234E6";
	char iString[] = "123e";

	printf("%f\n", atof(dString1));
	printf("%f\n", atof(dString2));
	printf("%f\n", atof(dString3));
	printf("%f\n", atof(iString));
	
	return 0;
}


/* 
 * atof:	convert string `s` to double
 * return:	double value of string
 */
double atof(char s[]) {
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)  /* skip white space */
		; // VOID
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

	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		int exp;
		int expIsNeg = (s[i] == '-');

		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + s[i] - '0';
		printf("%d\n", (expIsNeg ? -1 : 1) * exp);
		while (exp > 0) {
			if (expIsNeg)
				power *= 10.0;
			else
				power /= 10.0;
			exp--;
		}
	}

	return sign * val / power;
}
