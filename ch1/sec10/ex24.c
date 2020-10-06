#include <stdio.h>

#define OUTSIDE		0
#define INSIDE		1
#define SINGLE_LINE	1
#define MULTI_LINE	2

#define	NO_ERRORS		0
#define UNCLOSED_CHAR_CONST	1
#define UNCLOSED_STR_CONST	2
#define UNCLOSED_BRACE		3
#define UNCLOSED_PARENTHESIS	4
#define UNCLOSED_BRACKET	5
#define UNCLOSED_COMMENT	6

int check();

// Checks a C program for basic errors and prints out the appropriate error message
int main() {
	int statusCode = check();

	switch (statusCode) {
		case UNCLOSED_CHAR_CONST:
			printf("Unclosed char const\n");
			break;
		case UNCLOSED_STR_CONST:
			printf("Unclosed string const\n");
			break;
		case UNCLOSED_BRACE:
			printf("Unclosed curly brace\n");
			break;
		case UNCLOSED_PARENTHESIS:
			printf("Unclosed parenthesis\n");
			break;
		case UNCLOSED_BRACKET:
			printf("Unclosed bracket\n");
			break;
		case UNCLOSED_COMMENT:
			printf("Unclosed multi-line comment\n");
			break;
		default:
			printf("No errors detected\n");
	}

	return 0;
}

// check: reads standard input for errors
// ret: status code as defined above
int check() {
	int c;
	int braces = 0;
	int parentheses = 0;
	int brackets = 0;
	int string = OUTSIDE;
	int charConst = OUTSIDE;
	int comment = OUTSIDE;

	
	while ((c = getchar()) != EOF) {

		// Control character, ignore next character
		if (c == '\\' && comment == OUTSIDE) {
			getchar();

		// Char const, ignore inside and throw error if not closed
		} else if (c == '\'' && comment == OUTSIDE && string == OUTSIDE) {
			if ((c = getchar()) == '\\')
				getchar();
			if ((c = getchar()) != '\'')
				return UNCLOSED_CHAR_CONST;

		// Open or close string
		} else if (c == '"' && comment == OUTSIDE) {
			if (string == INSIDE)
				string = OUTSIDE;
			else
				string = INSIDE;

		// Open comment
		} else if (c == '/' && string == OUTSIDE && comment == OUTSIDE) {
			if ((c = getchar()) == '*')
				comment = MULTI_LINE;
			else if (c == '/')
				comment = SINGLE_LINE;

		} else {

		// Close comment
			if (comment == MULTI_LINE && c == '*' && getchar() == '/') {
				comment = OUTSIDE;
			} else if (comment == SINGLE_LINE && c == '\n') {
				comment = OUTSIDE;

		// Open or close braces & parentheses
			} else if (comment == OUTSIDE && string == OUTSIDE) {
				switch (c) {
					case '{':
						braces++;
						break;
					case '}':
						braces--;
						break;
					case '(':
						parentheses++;
						break;
					case ')':
						parentheses--;
						break;
					case '[':
						brackets++;
						break;
					case ']':
						brackets--;
						break;
				}
			}
		}
	}

	if (braces > 0)
		return UNCLOSED_BRACE;
	if (parentheses > 0)
		return UNCLOSED_PARENTHESIS;
	if (brackets > 0)
		return UNCLOSED_BRACKET;
	if (comment == MULTI_LINE)
		return UNCLOSED_COMMENT;

	return 0;
}
