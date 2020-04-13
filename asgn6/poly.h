/*
 * This is the header file for poly.c. It declares the functions that are available to the public.
 ****************************************************************************************
 * Author       Dept.           Date            Note
 ****************************************************************************************
 * Michael Li   Soft. Eng.      Apr 7 2020      Initial version with addPolyTerm, displayPolynomial and evaluatePolynomial function declarations
*/

/* Function that accepts two integer arguments (a coefficient and exponent) and assimilates that term into the existing Polynomial  */
int addPolyTerm(int coefficient, int exponent);

/* Function that displays the polynomial expression */
void displayPolynomial();

/* Function that accepts an integer value for x and returns an integer that is obtained by evaluating the polynomial 
This function will have to traverse the linked list, getting the values for coefficient and exponent from each node and using the powi function to perform computations.*/
int evaluatePolynomial(int x);
