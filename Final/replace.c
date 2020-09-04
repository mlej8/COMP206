#include<string.h>

/*
 * Helper C module that implements the replace function.
 ***************************************************************
 * Author         Dept.             Date          Notes
 ***************************************************************
 * Michael Li     Soft. Eng.        Apr 30 2020   Initial version.
*/

/* Function that replaces all occurences of word1 in word2. 
 The module replace.c is responsible for detecting that the word read from the file matches word1.
 If it does match word1 then it returns word2, otherwise it returns the original word. */
char* replace (char word[], const char *word1, const char *word2) {
    // if the word read from the file matches word1, copy content of word2 into the word array, else return original word array
    if (strcmp(word,word1) == 0){
        strcpy(word,word2);
    }
    return word;
}
