#include <stdio.h>

void celsiusToFahrenheit();

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("====== F to C ======\n");
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	celsiusToFahrenheit();
	return 0;
}

void celsiusToFahrenheit() {
	float fahr, celsius;
	float lower, upper, step;

	lower = -20;
	upper = 100;
	step = 10;

	celsius = lower;

	printf("====== C to F ======\n");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * (celsius + 32);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
