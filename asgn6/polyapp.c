#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "poly.h"

/*
 * Program that implmenents a simple application that constructs a polynomial expression and evaluates it for certain predetermined values.
 ****************************************************************************************
 * Author       Dept.           Date            Note
 ****************************************************************************************
 * Michael Li   Soft. Eng.      Apr 7 2020      Initial version 
 * Michael Li   Soft. Eng.      Apr 7 2020      Implemented filename check
 * Michael Li   Soft. Eng.      Apr 7 2020      Integrated Parse function
 * Michael Li   Soft. Eng.      Apr 8 2020      Simplified Parse function to 1 line
 * Michael Li   Soft. Eng.      Apr 9 2020      Integrated addPolyTerm, displayPolynomial and evaluatePolynomial
 * 
*/

int main(int argc, char const *argv[])
{
    // Check if program is invoked with no file names as argument
    if (argc != 2)
    {
        fprintf(stderr, "Error, incorrect usage!\nUsage is polyapp filename.csv.");
        exit(1); // exit code for invalid usage is 1
    }

    // Store filename is a variable
    const char *filename = argv[1];

    // Create a pointer that points to the data file to read it
    FILE *csv = fopen(filename, "r");

    // Check if the pointer was succesfully initiated
    if (csv == NULL)
    {
        fprintf(stderr, "Error, unable to locate the data file %s.\n", argv[1]);
        exit(2); // exit code for invalid data file name
    }

    // Create an array to store each line
    char data[100];
    int *coefficient = (int *) malloc(sizeof(int));
    int *exponent = (int *) malloc(sizeof(int));

    // Read one line at a time from the data file.
    while (fgets(data, sizeof(data) - 1, csv) != NULL)
    {
        // use parse to parse each line retrieved from the data file using fgets and store the coefficient and exponent to the address provided in the integer pointers 
        parse(data, coefficient, exponent);

        // Add it to polynomial using addPolyTerm function
        int added = addPolyTerm(*coefficient, *exponent);

        if (added) { // addPolyTerm will return 1 if it failed to allocate memory 
            fprintf(stderr, "Error, failed to allocate memory for new polynomial term.");
            exit(3);
        }        
    }

    // close pointer to data file
    fclose(csv);

    // call displayPolynomial to print the polynomial expression to the screen
    displayPolynomial();

    // call evaluatePolynomial for the values (-2, -1, 0, 1, -2)
    for (int i = -2; i < 3; i++) {
        printf("for x=%d, y=%d\n",i,evaluatePolynomial(i));
    }

    return 0;
}
