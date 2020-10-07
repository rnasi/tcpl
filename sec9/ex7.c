#include <stdio.h>

int invert(const int, const int, const int);

// Write a function `invert(x,p,n)` that returns `x` with the `n` bits that begin at position `p`
// inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
int main() {
	// 178 = 10 1100 10, flip 4 at position 5 -> 10 0011 10 = 142
	printf("%d\n", invert(178, 5, 4));

	return 0;
}

// invert:	inverts `n` bits of `x` starting at `p`
// assumptions:	`n` and `p` are sensible positive integers
// return:	the result of the inversion
int invert(const int x, const int p, const int n) {
	return (x & (~0 << p))				// left part
		+ ~(x & (~(~0 << n) << p + n))	// inverted part
		+ (x & ~(~0 << p));			// right part
	
}
