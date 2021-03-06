#include <stdio.h>

int invert(int, int, int);

// Write a function `invert(x,p,n)` that returns `x` with the `n` bits that begin at position `p`
// inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
int main() {
	// 178 = 10 1100 10, flip 4 at position 5 -> 10 0011 1	0 = 142
	printf("%d\n", invert(178, 5, 4));

	return 0;
}

// invert:	inverts `n` bits of `x` starting at `p`
// assumptions:	`n` and `p` are sensible positive integers
// return:	the result of the inversion
int invert(int x, int p, int n) {
	return (x & (~0 << (p + 1)))			// left part
		+ (~x & (~(~0 << n) << (p - n + 1)))	// inverted part
		+ (x & ~(~0 << (p - n + 1)));		// right part
}
