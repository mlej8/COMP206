#include <stdio.h>
#include <stdlib.h>

/*
 * File that contains utility functions 
 *****************************************************************************************
 * Author       Dept.           Date            Note
 *****************************************************************************************
 * Michael Li   Soft. Eng.      Apr 7 2020      Implemented parse and powi functions
*/



/* Function that accepts a string, and two integer pointers as its arguments. It will be used by the main function to parse a line that was retrieved from the data file using fgets and store the coefficient and exponent to the address provided in the integer pointers */
void parse (char *line, int* coefficientPtr, int* exponentPtr) {
        // Store coefficient and exponent their corresponding addresses given by their pointers.
        sscanf(line,"%d %d", coefficientPtr, exponentPtr);
}

/* Function that accepts two integers as argument (x and exponent) and returns an integer which is x raised to the power of exponent  */
int powi(int x, int exponent){

        if (exponent == 0){
        return 1;
        }

        // Initiate variable to store result 
        int result = x;
 
        // Compute result using a while loop
        while (--exponent > 0) { 
                result *= x; 
        }

        return result;
}
