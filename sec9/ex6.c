#include <stdio.h>

int setbits(const int, const int, const int, const int);

// Write a function `setbits(x,p,n,y)` that returns `x` with the `n` bits that begin at position
// `p` set to the rightmost `n` bits of `y`, leaving the other bits unchanged.
int main() {
	int x = 0xAA;	// 10101010
	int y = 0x55;	//  1010101
	
	printf("%d\n", setbits(x, 5, 4, y)); //1011010 = 90

	return 0;
}

// setbits:	sets the last `n` bits of `y` to the `n` bits from `x` starting at position `p`
// assumptions:	`p` and `n` are sensible positive integers
// return:	the new value of `y`
int setbits(const int x, const int p, const int n, const int y) {
	return ((x >> (p + 1 - n)) & ~(~0 << n))	// Get n bits from x at position p
		+ (y & (~0 << n));			// Put them at the end of y
}
