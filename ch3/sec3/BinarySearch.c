#include <stdio.h>

int binsearch(int, int[], int);

int main() {
	int v[] = {1, 3, 4, 4, 7, 10};

	printf("%d\n", binsearch(4, v, 6));
	printf("%d\n", binsearch(5, v, 6));
}

// binsearch:	Searches for `x` in array `v` with length `n`
// assumptions:	`v` is sorted lowest to highest
// return:	The index of an occurence of `x` in `v` if found, or -1 otherwise
int binsearch(int x, int v[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;	// Match found
	}
	return -1;	// No match
}
