#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
 * Program to implement Caesar Cipher which replaces each letter in the alphabet with another letter that is 'X' offset away from it to scramble the message.
 **************************************************************************
 * Author 	Dept.		Date		Note
 **************************************************************************
 * Michael Li 	Soft. Eng.	Feb 10 2020 	Initial version.
 * Michael Li 	Soft. Eng. 	Feb 20 2020 	Use return code from fgets as condition for the while loop.
 */

int main(int argc, char const *argv[])
{
	// If the user didn't pass the offset argument, display an error message and terminate with error code 1
	if (argc != 2){
		puts ("Error: usage is caesarcipher <offset>");
		return 1;
	}

	// Store offset passed as argument from the command line
	int offset = atoi(argv[1]);

	// Initialize an unsigned char variable and an unsigned char array of size 1024 to store the message. We use unsigned, because it is assumed that these variables in our program will be storing ASCII code for characters which is always positive
	unsigned char ch, message[1024];

	while(fgets(message,sizeof(message)-1,stdin) != NULL) { // reserve a slot for putting '\0' at the end

		// Since the '\0' character is appended to the end of the array, we need to loop strlen(message) - 1 times
		for (int i = 0; i < strlen(message)-1; i++){
			ch = message[i];

			// Only encrypt lowercase english alphabets (a-z) and print all other characters as is
			if (ch >= 'a' && ch <= 'z'){
				// modify character
				ch += offset; 

				// If the resulting new character is bigger than z or smaller than a, round it
				if (ch > 'z') {
				       	ch = (ch - 'z') + 'a' - 1;
				} else if (ch < 'a') {
					ch = 'z' + 1 - ('a' - ch);	
				}
			}
			message[i] = ch;
		}
	
		// Output encrypted message 
		printf("%s", message);
	} 
	
	// Return an error code of 0 if no error has produced
	return 0;
}
