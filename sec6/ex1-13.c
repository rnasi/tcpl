#include <stdio.h>

#define	IN	1
#define	OUT	2
#define HIST_WIDTH	20


void printHorizontal(int nlength[20]);

int main() {
	// words of 20 or more counted together
	int nlength[20];
	int wordLength;
	int state = OUT;
	char c;

	int i;
	for (i = 0; i < 20; i++)
		nlength[i] = 0;

	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			// found end of word
			if (state == IN) {
				// increment counter
				if (wordLength >= 20)
					++nlength[19];
				else
					++nlength[wordLength];
				// reset
				wordLength = 0;
				state = OUT;
			}
		} else if (state == OUT) {
			state = IN;
		} else {
			++wordLength;
		}
	}

	printf("\nWord lengths: ");

	for (i = 0; i < 20; i++)
		printf(" %d", nlength[i]);

	printHorizontal(nlength);
		
	return 0;
}


void printHorizontal(int nlength[20]) {
	int maxLength = 0;

	int i;
	for (i = 0; i < 20; ++i)
		if (nlength[i] > maxLength)
			maxLength = nlength[i];

	if (maxLength == 0)
		return;

	
	for (i = 0; i < 20; ++i) {
		printf("\n%d: ", i + 1);
		int normalizedLength = (float) HIST_WIDTH * ((float) nlength[i] / maxLength);
		printf("\n%d\n", normalizedLength);
//		for (int i = 0; i < normalizedLength; i++)
//			putchar('-');
	}

}
	
