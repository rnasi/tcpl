#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void expand(const char[], char[]);

void printExpanded(const char str[]) {
	char out[MAX_LENGTH];
	expand(str, out);

	printf("\"%s\" expanded is: \"%s\"\n", str, out);
}

int main() {
	char str1[] = "This has nothing";
	char str2[] = "This has a-z";
	char str3[] = "This has a-l which is less";
	char str4[] = "This has c-h which starts later";
	char str5[] = "This has a-a which is just an \'a\'";
	char str6[] = "This has z-z which is just a \'z\'";
	char str7[] = "This has a-c-f which is weird";

	char str8[] = "This has 0-9";
	char str9[] = "This has 0-5 which is less";
	char str10[] = "This has 3-7 which starts later";
	char str11[] = "This has 0-0 which is just a \'0\'";
	char str12[] = "This has 9-9 which is just a \'9\'";
	char str13[] = "This has 2-5-6 which is weird";

	char str14[] = "This one has a lot of different things like a-z, 0-9, maybe some e-y and 3-3-6-7-7.";

	
	printExpanded(str1);
	printExpanded(str2);
	printExpanded(str2);
	printExpanded(str3);
	printExpanded(str4);
	printExpanded(str5);
	printExpanded(str6);
	printExpanded(str7);
	printExpanded(str8);
	printExpanded(str9);
	printExpanded(str10);
	printExpanded(str11);
	printExpanded(str12);
	printExpanded(str13);
	printExpanded(str14);
	


	return 0;
}

void copyRange(char start, char end, const char input[], char output[], int iIn, int iOut) {



}

//expand:	expands shorthand notations (e.g. a-z) in `str1` into `str2`
//assumptions:	`str2` is big enough
void expand(const char input[], char output[]) {
	int iIn, iOut, j;
	int inLen = strlen(input);

	for (iIn = 0, iOut = 0; iIn < inLen - 2; iIn++, iOut++) {



		// Letter range found
		if (input[iIn] >= 'a'  && input[iIn] <= 'z'
				&& input[iIn + 1] == '-'
				&& input[iIn + 2] >= input[iIn] && input[iIn + 2] <= 'z') {

			// Start at first letter, go to last letter (not inclusive)
			for (j = input[iIn] - 'a'; j < input[iIn + 2] - 'a'; iOut++, j++)
				output[iOut] = 'a' + j;
			// Skip '-' in input
			iIn ++;
			// Output index was incremented one too many times as a result of the previous loop
			iOut--;

		// Number range found
		} else if (input[iIn] >= '0'  && input[iIn] <= '9'
				&& input[iIn + 1] == '-'
				&& input[iIn + 2] >= input[iIn] && input[iIn + 2] <= '9') {
			
			// Start at first letter, go to last letter (not inclusive)
			for (j = input[iIn] - '0'; j < input[iIn + 2] - '0'; iOut++, j++)
				output[iOut] = '0' + j;
			// Skip '-' in input
			iIn ++;
			// Output index was incremented one too many times as a result of the previous loop
			iOut--;

		// No shorthand, just copy character
		} else
			output[iOut] = input[iIn];
	}

	// Copy the last characters (including null terminator) as necessary
	for (; iIn <= inLen; iIn++, iOut++)
		output[iOut] = input[iIn];
//	output[iOut + 1] = input[iIn + 1];
//	output[iOut + 2] = '\0';
}
