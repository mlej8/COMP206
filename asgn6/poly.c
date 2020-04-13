#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

/*
 * File that implements a Linked list and can be used to store a polynomial of arbitrary length.
 ****************************************************************************************
 * Author       Dept.           Date            Note
 ****************************************************************************************
 * Michael Li   Soft. Eng.      Apr 7 2020      Initial version  with PolyTerm and head global variable. 
 * Michael Li   Soft. Eng.      Apr 7 2020      Done implementing addPolyTerm
 * Michael Li   Soft. Eng.      Apr 8 2020      Done implementing displayPolynomial
 * Michael Li   Soft. Eng.      Apr 8 2020      Done implementing evaluatePolynomial
*/

#ifndef PolyTerm
struct PolyTerm
{
    int coeff;             // coefficient field
    int expo;              // exponent field
    struct PolyTerm *next; // pointer to next poly term
};
#endif

/* Create a global variable head to keep track of the polynomail linked list. */
struct PolyTerm *head = NULL;

/* Function that inserts a node at the beginning of a linked-list */
int insertStart(int coefficient, int exponent){
        // allocate space for newTerm using malloc
        struct PolyTerm *newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));

        if (newTerm == NULL) return 1; // return 1 if failed to allocate space in memory for new term to add term to polynomial

        // Adding new term to polynomial at head
        newTerm->expo = exponent;
        newTerm->coeff = coefficient;
        newTerm->next = head; // make newTerm.next point to NULL
        head = newTerm;
        return 0;        
}

/* Function to insert at the end of linked-list */ 
int insertEnd(int coefficient, int exponent, struct PolyTerm *prev){
    // allocate space for newTerm using malloc
    struct PolyTerm *newTerm = (struct PolyTerm*) malloc(sizeof(struct PolyTerm));

    if (newTerm == NULL) return 1; // return 1 if failed to allocate space in memory for new term to add term to polynomial

    // Adding new term to polynomial at head
    newTerm->expo = exponent;
    newTerm->coeff = coefficient;
    newTerm->next = NULL; // make newTerm.next point to NULL
    prev->next = newTerm;
    return 0;
}

/* Function that accepts two integer arguments (a coefficient and exponent) and assimilates that term into the existing Polynomial.
Returns an integer: 0 (success) or -1 (failure, e.g. ran out of memory, so could not add a new node to the polynomial linked list)
*/
int addPolyTerm(int coefficient, int exponent)
{
    if (!head)
    { // Case 1: if head is NULL directly create first node
        return insertStart(coefficient, exponent);
    } else { 

        // If head is not null make a copy of head pointer to traverse linked list
        struct PolyTerm *tmp = head;
        struct PolyTerm *prev = head; // use a second pointer to track the previous element

        // Traverse polynomial using tmp
        while (tmp != NULL)
        {
            if (tmp->expo >= exponent)
            { // polynomial should be stored in the increasing order
                break;
            }
            prev = tmp;
            tmp = tmp->next; // move to next element in linked-list, equivalent to tmp = (*tmp).next;
        }

        if (tmp == head) { 
            // Case 2: Insert at the beginning of Linked-list
            return insertStart(coefficient, exponent);        
        } else if (!tmp) { 
            // Case 3: Insert at the end of Linked-list (if a term with the exponent passed as argument is not found in the polynomial, e.g. tmp=NULL, or its exponent is larger than all exponents in the linked-list, create it and append it to the end of linked list)
            return insertEnd(coefficient,exponent,prev);
        } else {
            // Case 4: Insert in the middle of Linked-list
            if (tmp->expo == exponent)
            { // a term with the same coefficient is found; simply update the coefficient of the polynomial term
                tmp->coeff += coefficient;
            } else { // tmp->expo > exponent

                // allocate space for newTerm using malloc
                struct PolyTerm *newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));

                if (newTerm == NULL) return 1; // return 1 if failed to allocate space in memory for new term to add term to polynomial

                // Adding new term to polynomial in between its smaller and bigger exponent
                newTerm->expo = exponent;
                newTerm->coeff = coefficient;
                newTerm->next = tmp; // make newTerm.next point to the polynomial term with the bigger exponent
                prev->next = newTerm; // make previous term (prev->coeff < coefficient) point to newTerm
            }
        }
    }

    // return 0 if successfully added term to polynomial
    return 0;
}

/* Function that displays the polynomial expression */
void displayPolynomial()
{
    if (head != NULL)
    {
        // print first element
        printf("%dx%d", head->coeff, head->expo);

        // create tmp pointer to traverse the list starting from second element in linked-list
        struct PolyTerm *tmp = head->next;

        while (tmp != NULL)
        {   
            if (tmp->coeff >= 0) printf("+%dx%d", tmp->coeff, tmp->expo);
            else printf("%dx%d", tmp->coeff, tmp->expo);
            tmp = tmp->next;
        }

        printf("\n"); // add newline for formatting
    }


}

/* Function that accepts an integer value for x and returns an integer that is obtained by evaluating the polynomial 
This function will have to traverse the linked list, getting the values for coefficient and exponent from each node and using the powi function to perform computations.*/
int evaluatePolynomial(int x)
{
    // initialize variable for storing result
    int y = 0;

    // create temporary poiner to traverse linked list
    struct PolyTerm *tmp = head;

    while (tmp != NULL)
    {
        // evaluate current term
        y += tmp->coeff*powi(x, tmp->expo);

        // navigate to next term
        tmp = tmp->next;
    }

    // create a pointer to
    return y;
}
