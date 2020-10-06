#include <stdio.h>
#include <limits.h>
#include <float.h>

// Displayes the ranges of various data types, using symbolic constants in `limits.h` and direct 
// computaion.
int main() {
	printf("============ limits.h ============\n");
	printf("signed char range:     %d  --  %d\n", CHAR_MIN, SCHAR_MAX);
	printf("unsigned char range:   0  --  %d\n", UCHAR_MAX);
	printf("signed short range:    %d  --  %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short range:  0  --  %d\n", USHRT_MAX);
	printf("signed int range:      %d  --  %d\n", INT_MIN, INT_MAX);
	printf("unsigned int range:    0  --  %u\n", UINT_MAX);
	printf("signed long range:     %ld  --  %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long range:   0  --  %lu\n", ULONG_MAX);

	printf("\n\n============ Computed ============\n");

	// Let's count until we hit overflow. I don't want to use bitwise operators (although that 
	// would be far more efficient) since they have not yet been covered in the book, and I 
	// want to use only the tools given as much as possible.

	char charMin, charMax;
	unsigned char ucharMax;
	charMin = 0;
	while (charMin >= 0)
		charMin++;
	charMax = charMin - 1;
	ucharMax = 2 * charMax + 1;

	printf("signed char range:     %d  --  %d\n", charMin, charMax);
	printf("unsigned char range:   0  --  %d\n", ucharMax);

	short shortMin, shortMax;
	unsigned short ushortMax;
	shortMin = charMax;
	while (shortMin >= 0)
		shortMin++;
	shortMax = shortMin - 1;
	ushortMax = 2 * shortMax + 1;

	printf("signed short range:    %d  --  %d\n", shortMin, shortMax);
	printf("unsigned short range:  0  --  %d\n", ushortMax);

	int intMin, intMax;
	unsigned int uintMax;
	intMin = shortMax;
	while (intMin >= 0)
		intMin++;
	intMax = intMin - 1;
	uintMax = 2 * intMax + 1;
	
	printf("signed int range:      %d  --  %d\n", intMin, intMax);
	printf("unsigned int range:    0  --  %u\n", uintMax);

	// Longs are big. Instead of simply incrementing, double until overflow, then take last
	// positive value and increment from there.
	long longMin, lastPositiveLong, longMax;
	unsigned long ulongMax;
	longMin = intMax;
	while (longMin >= 0) {
		lastPositiveLong = longMin;
		longMin = longMin * 2;
	}
	longMin = lastPositiveLong;
	while (longMin > 0)
		longMin++;
	longMax = longMin - 1;
	ulongMax = 2 * longMax + 1;

	printf("signed long range:     %ld  --  %ld\n", longMin, longMax);
	printf("unsigned long range:   0  --  %lu\n", ulongMax);

	return 0;
}
