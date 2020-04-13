#include<stdio.h>
#include<stdlib.h>

/*
 Program to implement a single calculator
 ******************************************************
 * Author	Dept.	    Date	Note
 ******************************************************
 * Michael Li   Soft. Eng.  Feb 10 2020 Initial version.
 * Michael Li 	Soft. Eng.  Feb 20 2020 Added error handling.
 */

int main(int argc, char *argv[]) {
	// If the user does not pass proper argument, display an error message and terminate with error code 1
	if (argc != 4) {
	puts("Error: usage is simplecalc <x> <op> <y>");
	return 1; 
	}

	char operator = argv[2][0];
	int operand1 = atoi(argv[1]);
	int operand2 = atoi(argv[3]);
	int result = 0;

	switch (operator) {
		case '+': 
			result = operand1+operand2;
			break; 
		case '-':
			result = operand1-operand2;
			break;
		case '/':
			result = operand1/operand2;
			break;
		case '*': 
			result = operand1*operand2;
			break;
		default: 
			printf("%c is not a valid operator\n", operator);
			return 2;
	}
	printf("%d\n", result);
	return 0;
}

