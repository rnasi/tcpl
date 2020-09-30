#include <stdio.h>

#define LOWER	0	// lower limit of the table
#define UPPER	300	// upper limit
#define STEP	20	// step

int main() {
	printf("====== F to C ======\n");
	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		printf("%3d %6.1f\n", fahr, ( 5.0 / 9.0 ) * ( fahr - 32 ));
	}

	return 0;
}