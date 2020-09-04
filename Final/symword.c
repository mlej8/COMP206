#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * Program that checks if a word passed as its argument is symmetric.
 * A word is symmetric if it spells the same from left to right and right to left (e.g. mum, madam, level).
 * The program should terminate with exit code 0 for a symmetric word and 1 for a non symmetric word.  
 * To simplify things, you can assume that the argument consists of a word consisting of only lowercase letters.
 * However, your program logic should work for a word of any length.
 * Your program must not use any arrays (other than the one used to capture the arguments passed to the main).
 *************************************************************
 * Author 	    Dept.		Date		Note
 *************************************************************
 * Michael Li 	Soft. Eng	Apr 29 2020	Initial version
 */

int main(int argc, char const *argv[])
{
    // make sure that the program is called with a single argument (e.g. show error message if program is called without a string argument or more than 1 arguments).
    if (argc != 2) {
        puts("Error: wrong usage.\nCorrect usage: ./symword string");
        exit(2);
    }

    // create indecies to track start and end of string passed as argument
    int start = 0;
    int end = strlen(argv[1])-1;
    
    // compare each pair of characters (e.g. first and last, second and second-last, etc.) until we have seen all pairs, this will ignore the middle character if string's length is odd.
    while (start < end) {
        // if the two characters are not equal, it is a non symmetric word. 
        if (argv[1][start++] != argv[1][end--]) {
            // exit with 1 for non symmetric word
            return 1;
        }
    }
    
    // exit with 0 for symmetric word 
    return 0;
}
