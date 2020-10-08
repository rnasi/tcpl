#include <stdio.h>

#define X	178	// 10110010

int bitcount(unsigned int);

int main() {
	printf("%d has %d '1' bits in it.\n", X, bitcount(X));
	return 0;
}

int bitcount(unsigned int x) {
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 1)
			b++;
	return b;
}
