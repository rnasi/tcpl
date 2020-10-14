#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void expand(const char[], char[]);

void printExpanded(const char str[]) {
	char out[MAX_LENGTH];
	expand(str, out);

	printf("\"%s\" expanded is: \"%s\"\n", str, out);
}

// Write a function `expand(s1,s2)` that expands shorthand notations like a-z in the string `s1` 
// into the equivalent complete list abc...xyz in `s2`. Allow for letters of either case and digits,
// and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or 
// trailing - is taken literally. 
int main() {
	// Test cases
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

	char str14[] = "This one has a lot of different things like a-z, A-Z, 0-9, maybe some e-y and 3-3-6-7-7.";
	
	printExpanded(str1);
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

//expandRange:	Expands a single character range shorthand.
//		Specifically, if a shorthand with start and end characters between `start` and `end`
//		is found at `input[iIn]`, it is expanded into `output` starting at `iOut`. Does
//		nothing if no matching shorthand found.
//assumptions:	`output` is big enough
//		iIn < strlen(input) - 2
//return:	if a char shorthand is found at `input[iIn]`:
//			index of the last character in `output` after expansion
//		otherwise:
//			0
int expandRange(char start, char end, const char input[], char output[], int iIn, int iOut) {
	int j;
	if (input[iIn] >= start  && input[iIn] <= end
			&& input[iIn + 1] == '-'
			&& input[iIn + 2] >= input[iIn] && input[iIn + 2] <= end) {

		// Start at first letter, go to last letter (not inclusive)
		for (j = input[iIn] - start; j < input[iIn + 2] - start; iOut++, j++)
			output[iOut] = start + j;

		// Above loop increments iOut one time without adding a character
		return iOut - 1;
	}

	return 0;
}

//expand:	Copies `input` into `output`, expanding any character range shorthand notations of
//		letters or digits (e.g. a-z, B-E, 3-7 -> abc ... z, BCDE, 34567)
//assumptions:	`output` is big enough
void expand(const char input[], char output[]) {
	// Indices for `input` and `output`
	int iIn, iOut;
	int inLen = strlen(input);

	for (iIn = 0, iOut = 0; iIn < inLen - 2; iIn++, iOut++) {
		int shorthandFound;
		// Lower case letter range shorthand
		if ((shorthandFound = expandRange('a', 'z', input, output, iIn, iOut))) {
			// Shorthand found--advance iOut
			iOut = shorthandFound;
			// skip '-' in input
			iIn++;
		// Upper case letter range
		} else if ((shorthandFound = expandRange('A', 'Z', input, output, iIn, iOut))) {
			iOut = shorthandFound;
			iIn++;
		// Digit range
		} else if ((shorthandFound = expandRange('0', '9', input, output, iIn, iOut))) {
			iOut = shorthandFound;
			iIn++;
		// No shorthand, just copy character
		} else
			output[iOut] = input[iIn];
	}

	// Copy the last characters (including null terminator) as necessary
	for (; iIn <= inLen; iIn++, iOut++)
		output[iOut] = input[iIn];
}
