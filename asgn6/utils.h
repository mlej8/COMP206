/*
 * This is the header file for utils.c. It declares the functions that are available to the public.
 *****************************************************************************************
 * Author       Dept.           Date            Note
 *****************************************************************************************
 * Michael Li   Soft. Eng.      Apr 7 2020      Added parse and powi functions
*/

/* Function that accepts a string, and two integer pointers as its arguments. */
void parse (char* str, int* coefficientPtr, int* exponentPtr);

/* Function that accepts two integers as argument (x and exponent) and returns an integer which is x raised to the power of exponent  */
int powi(int x, int exponent);
