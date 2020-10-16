#include <stdio.h>

int binsearch(int, const int[], int);
int binsearch2(int, const int[], int);

#define MAX_SIZE	1000000 // 1,000,000

// Our binary search makes two tests inside the loop, when one would suffice (at the price of more
// tests outside.) Write a version with only one test inside the loop and measure the difference
// in run-time.
int main() {
	int v[MAX_SIZE];
	int i;
	for (i = 0; i < MAX_SIZE; i++)
		v[i] = 2 * i;
	
	int testData[12] = {-1, 0, 1, MAX_SIZE / 4 + 1, MAX_SIZE / 4, MAX_SIZE / 2, MAX_SIZE / 2 + 1,
		MAX_SIZE - (MAX_SIZE / 4), MAX_SIZE - (MAX_SIZE / 4) + 1, MAX_SIZE - 3, MAX_SIZE - 2,
		MAX_SIZE};

	for (i = 0; i < 12; i++)
		printf("%d\n", binsearch(testData[i], v, MAX_SIZE));
}

// binsearch:	Searches for `x` in array `v` with length `n`
// assumptions:	`v` is sorted lowest to highest
// return:	The index of an occurence of `x` in `v` if found, or -1 otherwise
int binsearch(int x, const int v[], int n) {
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

// binsearch2:	Searches for `x` in array `v` with length `n` using only 1 comparison in the loop
// assumptions:	`v` is sorted lowest to highest
// return:	The index of an occurence of `x` in `v` if found, or -1 otherwise
int binsearch2(int x, const int v[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid;
		else
			low = mid;
	}
	if (x == v[low])
		return low;
	else if (x == v[high])
		return high;
	else
		return -1;
}
