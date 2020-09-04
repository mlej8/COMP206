/*
 * Header file to expose the replace function implemented in replace.c
 ***************************************************************
 * Author         Dept.             Date          Notes
 ***************************************************************
 * Michael Li     Soft. Eng.        Apr 30 2020   Initial version.
*/

#ifndef REPLACE_H
#define REPLACE_H

// Function that replaces all occurences of word1 by word2. 
char* replace(char *str, const char *word1, const char *word2);

#endif