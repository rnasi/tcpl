#include <stdio.h>

#define X 	178	// 10110010

int bitcount(unsigned);

// ==== Excercise 2-9 ====
//
// In a two’s complement number system, `x &= (x-1)` deletes the rightmost 1-bit in `x`. Explain
// why. Use this observation to write a faster version of `bitcount`.
//
//
// ==== Explanation ====
//
// `x &= (x - 1)` is equivalent to `x = x & (x - 1)`. There are 3 cases to consider in the result
// of the expression `x & (x - 1): the last 1-bit itself, all the bits to the right of it, and all
// the bits to the left of it.
//
// Case 1--Last 1-bit:
//   Subtracting 1 will always set the last 1 bit to 0 as a result of borrowing, thus `x & (x - 1)`
// will be 0 at this bit.
//
// Case 2--All bits to the right:
//   All the bits to the right of the last 1-bit are by definition 0 in `x`, so they will all be 0
// in `x & (x - 1)`.
//
// Case 3--All bits to the left:
//   Since we are only subtracting 1, borrowing will stop at the last 1-bit, thus `x` and `x - 1`
// are equivalent to the left of the last 1-bit, so `&`-ing them will not change any of these bits.
//
// Therefore, we see that the only bit in the result of this expression that differs from `x` is
// the last 1-bit, which gets set to 0.
//
// For example:
// x = 9
// 	  1001
//	- 0001
//	= 1000	 (9 - 1)
//	& 1001	 & 9
//	= 1000
//
// x = 10
//	  1010
//	- 0001
//	= 0001	 (10 - 1)
//	& 1010	 & 10
//	= 1000
//
// x = 12
// 	  1100
//	- 0001
//	= 1011  (12 - 1)
//	& 1100  & 10
//	= 1000
//	
// Thus we can build a bit counter that keeps performing this assignment until `x` is 0 (meaning it
// has no more 1-bits) and counting how many operations are needed, which will clearly be equal to
// the number of 1-bits in `x`. This is faster because it does not require shifting bits.
int main() {
	printf("%d has %d '1' bits in it.\n", X, bitcount(X));
	return 0;
}

// bitcount:	counts the number of `1` bits in x
// return:	the aforementioned count
int bitcount(unsigned x) {
	int b;
	for (b = 0; x != 0; b++)
		x &= x - 1;
	return b;
}
