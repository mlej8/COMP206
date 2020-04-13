#include<stdio.h> 
#include<stdlib.h>

int main(int argc, char *argv[]) { 
    /* You must write this algorithm without using additional library functions from string.h and stdio.h (for example, you cannot use the sprint() function, you cannot use the strcpy() function). */
    char name[30], multipleNames[1000]; 
    int numberOfTimes, index = 0, n = -1;
    
    if (argc == 2) numberOfTimes = atoi(argv[1]); 
    else numberOfTimes = 2;

    printf("Enter a name: "); 

    // read a word of characters using getc(stdin)    
    do {
        name[++n] = getc(stdin);        
    } while(name[n] != '\n');
    
    // Mark the end of the string
    name[n] = '\0';
    
    // Copy the word in the array name into the array multipleNames for numberOfTimes
    for (int i = 0; i < numberOfTimes; i++){
        for (int j = 0; j < name[j] != '\0'; j++){
            multipleNames[index] = name[j];
            index += 1;
        }
    }

    // Mark the end of string
    multipleNames[index] = '\0';

    printf("%s\n", multipleNames); 

    
    /* 
    // Test: What does this code do? 
    char array[50]; 
    char s[] = {'a','b','c','\0'};
    int i,j;

    for(i = 0; i<strlen(s); i++) array[i] = s[i]; 
    for(j=i, i=0; i<strlen(s); i++, j++) array[j] = s[i]; 
    
    array[j] = '\0';

    printf("%s", array);
    */
}