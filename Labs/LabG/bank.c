#include<stdio.h>

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
    // Create local array, called accounts, in main(), of 100 cells of type BANK_ACCOUNT
    struct BANK_ACCOUNT accounts[100];

    // Create variable will be used to track where in the array accounts the next account will be created. ALl spots to the left of nextSpot are array cells with account information. To the right of nextSpot cells are not used
    int nextSpot = 0; 
    
    // Prompt the user for the number of accounts they would like to create. Store that in an integer variable called newAccounts.
    int newAccounts;
    printf("Number of accounts to create: ");
    scanf("%d", &newAccounts);

    // prompt the user for the information to input into the bank accounts using a for loop 
    for(int i = 0; i < newAccounts; i++ ) { 
        // first ask user for type of account 
        printf("What is the type of the account ('C'/'S'): ");
        scanf(" %c", &accounts[nextSpot].type);
        

        // ask for balance
        printf("How much money does the account hold: ");
        scanf(" %lf", &accounts[nextSpot].balance); // notice %lf is used for doubles

        if (accounts[nextSpot].type == 'S'){
            // for savings account ask for withdrawal charge
            printf("What is the charge on the account: ");
            scanf(" %lf", &(accounts[nextSpot].specific.charge));
        } else if (accounts[nextSpot].type == 'C') { 
            // for checking account ask for account credit
			printf("What is the account credit score: ");
            scanf(" %d", &(accounts[nextSpot].specific.credit_score));
        } 

        nextSpot++;        
		printf(" - Account Created - \n");
    }

    // program ends by displaying all the cells of the array from 0 to nextSpot, to confirm that the information was input correctly.
    for(int j = 0; j < nextSpot; j++) {
		printf("Account #%d of type %c holding: %.2f$", j, accounts[j].type, accounts[j].balance);
		if (accounts[j].type == 'C') {
			printf(" with a credit score of %d\n", accounts[j].specific.credit_score);
		} else if (accounts[j].type == 'S') {
			printf(" with a charge of %.2f$\n", accounts[j].specific.charge);
		}
	}
    return 0;
}
