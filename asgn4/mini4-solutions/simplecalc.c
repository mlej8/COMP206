/*
 Program to implement a simple calculator
 ***************************************************************
 * Author         Dept.             Date          Notes
 ***************************************************************
 * Joseph D       Comp. Science. Feb 10 2020    Initial version.
 * Joseph D       Comp. Science. Feb 11 2020    Added error handling.
*/

//Header file for fprintf, printf
#include <stdio.h>
// Header file for atoi
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int x, y;
	char op;

  // Check if we were given the offset as an argument, else report error and terminate.
  if(argc != 4)
  {
    printf("Error: usage is simplecalc <x> <op> <y>\n");
    return 1;
  }

  x=atoi(argv[1]); // parse the value of x from the input argument.
	sscanf(argv[2], "%c", &op); // parse the value of op from the input argument.
  // op=argv[2][0]; // or do it this way
  y=atoi(argv[3]); // parse the value of y from the input argument.

	// Do the math and print the result.
	switch(op)
	{
		case '+':
			printf("%d\n", x+y);
			break;
		case '-':
			printf("%d\n", x-y);
			break;
		case '*':
			printf("%d\n", x*y);
			break;
		case '/':
			printf("%d\n", x/y);
			break;
		default: //If the operator is not in our repository
			printf("%c is not a valid operator\n", op);
			return 2;
	}

  return 0;
}
