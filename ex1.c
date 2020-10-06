#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("unsigned char range: 0 - %d\n", UCHAR_MAX);
	printf("signed char range: %d - %d\n", CHAR_MIN, SCHAR_MAX);
	printf("unsigned short range: 0 - %d\n", USHRT_MAX);
	printf("signed short range: %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned int range: 0 - %u\n", UINT_MAX);
	printf("signed int range: %d - %d\n", INT_MIN, INT_MAX);
	printf("unsigned long range: 0 - %lu\n", ULONG_MAX);
	printf("signed long range: %ld - %ld\n", LONG_MIN, LONG_MAX);

	return 0;
}
