#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "replace.h"

/*
 * Program that opens the text file provided at the command-line and replaces all occurrences of word1 by word2 from within the file.
 * When the program ends, the file's contents have changed (word1 occurrences are replaced by word2).
 *************************************************************
 * Author 	    Dept.		Date		Note
 *************************************************************
 * Michael Li 	Soft. Eng	Apr 30 2020	Initial version
 */

/* The arguments at the command line follow these rules: 
- argv[1]: the filename may or may not have a path
- argv[2] and argv[3]: both word1 and word2 are single words without spaces and without special characters like a punctuation.
Assume the user inputs the arguments correctly. Do not do data validation. */
int main(int argc, char const *argv[])
{   
    // create a filename for the temporary text file to which we will write to
    char *tmp = "temp";
    
    // create a file pointer to read word by word until "\n" or " "
    FILE *frptr = fopen(argv[1], "rt"); // file read pointer
    FILE *fwptr = fopen(tmp, "wt"); // file write pointer to temporary file

    // verify if file was successfully read
    if (frptr == NULL) {  
        printf("Failed to read %s.", argv[1]);
        exit(EXIT_FAILURE);
    }

    // verify successfully created a pointer to temp file
    if (fwptr == NULL){
        printf("Failed to open temporary file to write in.");
        exit(EXIT_FAILURE);
    }

    // use more readable local variable to store reference to words
    const char *word1 = argv[2];
    const char *word2 = argv[3];
    
    while (!feof(frptr)) {
        
        // Create an array to store a word, assuming words are no longer than 30 characters
        char word[30];

        // read an entire word into memory
        fscanf(frptr, "%s", word);
        
        // using the replace function to see if we should replace word
        char *newWord = replace(word, word1, word2); // newWord is a pointer to the word returned by replace function

        // write word choosen by the replace function to the temporary textfile
        fprintf(fwptr,"%s", newWord);

        // reading space characters (whitespace, tabs, newlines, etc.) by character to preserve format 
        char c = getc(frptr);

        // while it is not a character or end of line
        while (! isalpha(c) && !feof(frptr)) {
            // write space or newline in temporary text file
            putc(c, fwptr);

            // get next character
            c = getc(frptr); 
        }
        
        // since we know that we will only exit the while loop if we encounter a character, put that character back in the stream for the next iteration which reads the entire word.
        ungetc(c, frptr);
    }

    // close file pointers when we are done with it to release ressource
    fclose(frptr);
    fclose(fwptr);

    // replace the original file with the temporary file
    remove(argv[1]); // remove old file 
    rename(tmp, argv[1]); // replace it with new file

    return 0;
}
