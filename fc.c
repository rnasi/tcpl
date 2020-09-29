#include <stdio.h>

void celsiusToFahrenheit();

int main() {
	printf("====== F to C ======\n");
	int fahr;
	for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
		printf("%3d %6.1f\n", fahr, ( 5.0 / 9.0 ) * ( fahr - 32 ));
	}

	printf("====== C to F ======\n");
	int celsius;
	for (celsius = -20; celsius <= 100; celsius = celsius + 10) {
		printf("%3d %6.1f\n", celsius, ( 9.0 / 5.0 ) * celsius + 32);
	}

	return 0;
}
