// Link on pointers: https://www.guru99.com/c-pointers.html
#include <stdio.h>
#include <string.h>

int main () {
    char *str = "Hello World!";
    char *p; 

    p = str; 
    printf("First character is: %c\n", *p); // dereferencing content at address p

    p = p + 1; 
    printf("Next character is: %c\n", *p);

    printf("Printing all the characters in a string\n");
    p = str; // reset the pointer

    /* 
    // For loop implementation
    for (int i = 0; i < strlen(str); i++ ){
        printf("%c\n", *p);
        p++;
    }
    */

    // While loop implementation 
    while (*p != '\0') {
        printf("%c\n", *p);
        p++;
    }

    return 0;
}