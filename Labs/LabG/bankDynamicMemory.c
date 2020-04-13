#include<stdio.h>
#include<stdlib.h>

/* Question One done with calloc and pointer references */

struct BANK_ACCOUNT
{
    char type; // ‘S’=savings, ‘C’=checking
    double balance;
    union ACCOUNT_SPECIFIC {
        double charge;    // for withdrawal from savings accounts
        int credit_score; // for checking account
    } specific;
};

int main(int argc, char const *argv[])
{

    // Create a pointer of bank accounts
    struct BANK_ACCOUNT *accounts = NULL;
    
    // Use calloc to allocate 100 cells 
    accounts = (struct BANK_ACCOUNT *) calloc(100, sizeof(struct BANK_ACCOUNT));    

    if (accounts == NULL) {
        printf("Failed to allocate space for accounts");
        exit(1);
    }
    
    // Create a pointer variable that will be used to track where in the array accounts the next account will be created. ALl spots to the left of nextSpot are array cells with account information. To the right of nextSpot cells are not used
    struct BANK_ACCOUNT *nextSpot = accounts; 
    
    // Prompt the user for the number of accounts they would like to create. Store that in an integer variable called newAccounts.
    int newAccounts, numberOfAccounts = 0;
    printf("Number of accounts to create: ");
    scanf("%d", &newAccounts);

    // prompt the user for the information to input into the bank accounts using a for loop 
    for(int i = 0; i < newAccounts; i++ ) { 
        // first ask user for type of account 
        printf("What is the type of the account ('C'/'S'): ");
        scanf(" %c", &(nextSpot->type));        

        // ask for balance
        printf("How much money does the account hold: ");
        scanf(" %lf", &(nextSpot->balance)); // notice %lf is used for doubles

        if (nextSpot->type == 'S'){
            // for savings account ask for withdrawal charge
            printf("What is the charge on the account: ");
            scanf(" %lf", &(nextSpot->specific.charge));
        } else if (nextSpot->type == 'C') { // equivalent to *(nextSpot).type
            // for checking account ask for account credit
			printf("What is the account credit score: ");
            scanf(" %d", &(nextSpot->specific.credit_score));
        } 

        nextSpot++;        
        numberOfAccounts++;
		printf(" - Account Created - \n");
    }
    
    (" --- Displaying Accounts --- \n");

    // program ends by displaying all the cells of the array from 0 to nextSpot, to confirm that the information was input correctly.
    for (int j = 0; j < numberOfAccounts; j++) {
		printf("Account #%d of type %c holding: %.2f$", j, accounts[j].type, accounts[j].balance);
		if (accounts[j].type == 'C') {
			printf(" with a credit score of %d\n", accounts[j].specific.credit_score);
		} else if (accounts[j].type == 'S') {
			printf(" with a charge of %.2f$\n", accounts[j].specific.charge);
		}
	}

    // free memory
    free(nextSpot);
    free(accounts);

    return 0;
}
