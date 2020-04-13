#include<stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n-1);
    }

int main(int argc, char const *argv[])
{
    int n, result; 

    // Asks the user to input a single integer number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Pass that number to your recursive function 
    result = factorial(n);

    // Print result
    printf("Result: %d", result);
    return 0;
}
