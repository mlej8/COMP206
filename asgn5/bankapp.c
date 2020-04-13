#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Program that implmeents a simple banking application
 *************************************************************
 * Author 	Dept.		Date		Note
 *************************************************************
 * Michael Li 	Soft. Eng	Feb 20 2020	Initial version
 * Michael Li 	Soft. Eng	Feb 21 2020	Added \n to format output
 * Michael Li   Soft. Eng	Mar 10 2020	Added functions for each 
 */

int doesAccountExist(FILE *p, char *accountNumber){
	// this function iterates through a file to see if an account exists in the csv file, if it does, it will return 1, else 0.
	char account[100];
	while (fgets(account, sizeof(account) - 1, p) != NULL) {
		if (account[0] == 'A' && account [1] == 'C' && account[3] == accountNumber[0] && account[4] == accountNumber[1] && account[5] == accountNumber[2] && account[6] == accountNumber[3]){
			return 1; 
		}
	} 
	return 0;
}

double accountTotalFund(FILE *filePointer, char *accountNumber){
	// this function iterates through a file to compute the toatal fund of an account. 
	double totalFund = 0;
	char transaction[100];
	char *token;
	char *tokens[4];
	int counter = 0; 

	while (fgets(transaction, sizeof(transaction)-1, filePointer) != NULL){
		if (transaction[0] == 'T' && transaction[1] == 'X' && transaction[3] == accountNumber[0] && transaction[4] == accountNumber[1] && transaction[5] == accountNumber[2] && transaction[6] == accountNumber[3]) {
			// get the first token 
		 	token = strtok(transaction, ",");

				while (token != NULL) {
					// Store current token in string array 
					tokens[counter] = token;

					// Increment counter
					counter++;

					// Next token
					token = strtok(NULL, ",");
				}
			totalFund += atof(tokens[3]);
		}
		counter = 0;
	}
	return totalFund;
}

void createAccount(FILE *csv, char *accountNumber, FILE *writer, char *name){
	// if the account number already exists (as indicated by the AC records), the program should throw an error message to indicate this and terminate with error code 50.
	if (doesAccountExist(csv, accountNumber))
	{
		fprintf(stderr, "Error, account number %d already exists\n", atoi(accountNumber));
		exit(50);
	}
	else {
		fprintf(writer, "%s,%d,%s\n", "AC", atoi(accountNumber), name); // create a new account which will be appended to the data file bankdata.csv
	}
}

void deposit (FILE *csv, char *accountNumber, FILE *writer, char *date, char *amount){
	if (doesAccountExist(csv, accountNumber)){
		fprintf(writer, "%s,%d,%s,%s\n", "TX", atoi(accountNumber), date, amount); // create a new transaction which will be appended to the data file bankdata.csv
		}
	else {
		fprintf(stderr, "Error, account number %d does not exists\n", atoi(accountNumber));
		exit(50);
	}
}

void withdraw(FILE *csv, char *accountNumber, FILE *writer, char *date, char *amount) {
	if (doesAccountExist(csv, accountNumber)) {
		double totalFund = accountTotalFund(csv, accountNumber);
		if (totalFund > atof(amount)) {
			fprintf(writer, "%s,%d,%s,-%s\n", "TX", atoi(accountNumber), date, amount); // create a new transaction which will be appended to the data file bankdata.csv 
		} else {
			fprintf(stderr, "Error, account number %d has only %.2f\n", atoi(accountNumber),totalFund);
			exit(60);
		}
	} else {
		fprintf(stderr, "Error, account number %d does not exists\n", atoi(accountNumber));
		exit(50);
		}
}



int main(int argc, char *argv[]) { 
	
	if (argc == 1){
		// write error messages to stderr stream	
		 fprintf(stderr, "Error, incorrect usage!\n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTNUM DATE AMOUNT\n");
		 exit(1); // exit code for invalid usage is 1
				 }
	// Declare a local variable that points to the bankdata.csv file 
	FILE *csv = fopen("bankdata.csv","r");

	// If the file is not found, print an error message
	if (csv == NULL) {
		fprintf(stderr, "Error, unable to locate the data file bankdata.csv\n");
		exit(100);
	}
	
	FILE *writer = fopen("bankdata.csv", "a"); // writer that appends at the end of a file
	
	// Verify which action user specified
	switch (argv[1][1]){
		case 'a':
			if (argc != 4) {
			fprintf(stderr, "Error, incorrect usage!\n-a ACCTNUM NAME\n");
			exit(1);
			}
		createAccount(csv,argv[2],writer,argv[3]);	
		break;

		case 'd':
			if (argc != 5){
				fprintf(stderr, "Error, incorrect usage!\n-d ACCTNUM DATE AMOUNT\n");
				exit(1);
			}
			deposit(csv,argv[2], writer, argv[3], argv[4]);
			break; 
	
		case 'w':
			if (argc != 5) {
				fprintf(stderr, "Error, incorrect usage!\n-w ACCTNUM DATE AMOUNT\n");
				exit(1);
			}	
			withdraw(csv,argv[2], writer, argv[3], argv[4]);
			break; 
			}

	// closing file pointers
	fclose(csv);
	fclose(writer);
	return EXIT_SUCCESS;
}
