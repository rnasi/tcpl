#include <stdio.h>

#define X	178	// 10110010
#define N	3	// will yield 010 ... 10110 when right rotated
			// 32-bit: 01000000000000000000000000010110 = 1073741846

int rightrot(int, int);
int intsize();

// Write a function `rightrot(x,n)` that returns the value of the integer `x` rotated to the right
// by `n` positions.
int main() {
	printf("Int size in bits on current machine: %d\n"
			"%d rotated right %d positions: %d\n"
			, intsize(), X, N, rightrot(X, N));
}

// intsize:	determines the size of an `int`
// return:	size of `int` in bits
int intsize() {
	int i, x;
	x = 1;
	// Shift `x` left until overflow; `i` will be int size - 1 (not counting rightmost bit).
	for (i = 1; (x = x << 1) > 0; i++);
	return i + 1;
}

// rightrot:	rotates `x` to the right by `n` positions
// assumptions:	`n` is a sensible positive integet
// return:	rotated value
int rightrot(int x, int n) {
	return (x >> n)				// left part
		+ (x << (intsize() - n));	// right part
}

