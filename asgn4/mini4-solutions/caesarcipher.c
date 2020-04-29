/*
 Program to implement Caesar cipher
 *********************************************
 ***************************************************************
 * Author         Dept.             Date          Notes
 ***************************************************************
 * Joseph D       Comp. Science. Jan 21 2020    Initial version.
*/

// Header file for getchar
#include <stdio.h>
// Header file for atoi
#include <stdlib.h>

int main(int argc, char* argv[])
{
  // Number of alphabets
  const int NUMALPHABETS = 26;
  // Offset to record the number of letters to shift to implement the cipher.
  int offset;
  char c; // read input a character at a time.

  // Check if we were given the offset as an argument, else report error and terminate.
  if(argc != 2)
  {
    printf("Error: usage is caesarcipher <offset>\n");
    return 1;
  }

  offset=atoi(argv[1]); // parse the offset from input.
  offset=offset%NUMALPHABETS; // truncate the offset to -25 +25 range.

  // read one character at a time till out of input.
  while((c = getchar()) != EOF)
  {
    //By default, the new character to output is same as the input character.
    unsigned char newc = c; 
    if(c >='a' && c <= 'z') // if the input is a lowercase alphabet.
    {
      newc = c + offset; // apply the offset to get a new character.
      if(newc > 'z')  // if the new character is above 'z' then wrap around starting at 'a'
        newc = 'a' + (newc - 'z' - 1);
      else if(newc < 'a')  // if the new character is below 'a' then wrap around counting back from 'z'
        newc = 'z' - ('a' - newc - 1);
    }
    putchar(newc); // display the new character.
  }

  return 0;
}

/*
 *  Can you modify the solution to work for both lower case and upper case alphabets as well as digits?
*/
