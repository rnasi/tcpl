#include <stdio.h>

int main() {
	int wsc = 0; //white space count
	int c;

	while((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n')
			++wsc;

	printf("\nWSC: %d\n", wsc);
	
	return 0;
}
