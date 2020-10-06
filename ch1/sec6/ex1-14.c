#include<stdio.h>

#define HIST_WIDTH 75

int main() {
	int charFreq[128];
	int i;
	for (i = 0; i < 128; i++)
		charFreq[i] = 0;

	int c;
	while ((c = getchar()) != EOF)
		// sanity check
		if (c < 128)
			charFreq[c]++;

        int maxLength = 0;
        for (i = 0; i < 128; ++i)
                if (charFreq[i] > maxLength)
                        maxLength = charFreq[i];

        if (maxLength == 0)
        	return 1;

        for (i = 0; i < 128; ++i) {
                printf("\n%c:\t", i);
                int normalizedLength = (float) HIST_WIDTH * ((float) charFreq[i] / maxLength);
                for (int i = 0; i < normalizedLength; i++)
                        putchar('-');
        }
        putchar('\n');	
	
	return 0;
}
