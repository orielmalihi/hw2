/*
 * myBank.c
 *
 *  Created on: 19 Nov 2019
 *      Author: oriel
 */
#define NumOfAccounts 50
#define AccountStatus 2

#include "stdio.h"


double bank[AccountStatus][NumOfAccounts] = {{0},{0}};

void clearInputBuffer(){
	char c = 'a';
	while ( c != '\n' && c!=' '){
		c = getchar();
	}
}

void open(){
	double deposit;
	int accountNumber;
	for(int i = 0; i<NumOfAccounts; i++){
		if(bank[0][i]==0.0){
			bank[0][i]=1.0;
			accountNumber = i + 901;
			printf("Initial deposit?\n");
			scanf(" %lf",&deposit);
			if(deposit<0){
				printf("Depoisit was unsuccessful.\nCan not deposit a negative amount.\n");
				return;
			}
			bank[1][i] += deposit;
			printf("your account number is %d , and your current balance is %0.2lf\n", accountNumber, bank[1][i]);
			return;
		}

	}
	printf("Could not open an account.\nall accounts are occupied.\n");

}
void balance(){
	int accountNumber;
	printf("Account number?\n");
	scanf(" %d", &accountNumber);
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[0][accountNumber]==0.0){
		printf("This account is closed\n");
	}
	else{
		printf("your current balance is %0.2lf\n", bank[1][accountNumber]);
	}
}

void deposit(){
	int accountNumber;
	double amount;
	printf("Account number?\n");
	scanf(" %d", &accountNumber);
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[0][accountNumber]==0){
		printf("This account is closed\n");
	}else{
		clearInputBuffer();
		printf("Amount?\n");
		scanf(" %lf", &amount);
		if(amount<0){
			printf("Depoisit was unsuccessful.\nCan not deposit a negative amount\n");
			return;
		}
		bank[1][accountNumber] += amount;
		printf("your current balance is %0.2lf\n", bank[1][accountNumber]);
	}
}

void withrow(){
	int accountNumber;
	double amount;
	printf("Account number?\n");
	scanf(" %d", &accountNumber);
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[0][accountNumber]==0){
		printf("This account is closed\n");
	}else{
		clearInputBuffer();
		printf("Amount?\n");
		scanf(" %lf", &amount);
		if(amount<0){
			printf("Withrow was unsuccessful.\nCan not withrow a negative amount\n");
			return;
		}
		bank[1][accountNumber] -= amount;
		printf("your current balance is %0.2lf\n", bank[1][accountNumber]);
	}
}

void close(){
	int accountNumber;
	printf("Account number?\n");
	scanf(" %d", &accountNumber);
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[0][accountNumber]==1.0){
		bank[0][accountNumber]=0.0;
		bank[1][accountNumber]=0.0;
		printf("Closing the account was successful\n");
	}
	else{
		printf("This account is already closed\n");
	}
}

void interestRate(){
	double interestRate;
	printf("Interest rate? (in Decimal number)\n");
	scanf(" %lf", &interestRate);
	interestRate /= 100;
	interestRate += 1;
	for(int i = 0; i<NumOfAccounts; i++){
		if(bank[0][i]==1.0)
			bank[1][i] *= interestRate;
	}
}

void printAccounts(){
	for(int i = 0; i<NumOfAccounts; i++){
		if(bank[0][i]==1.0){
			int accountNumber = i+901;
			printf("Account number %d has balance of %0.2lf $\n", accountNumber, bank[1][i]);
		}
	}
}

void end(){
	for(int i = 0; i<NumOfAccounts; i++){
		if(bank[0][i]==1.0){
			bank[0][i]=0.0;
			bank[1][i]=0.0;
		}
	}
	printf("All accounts have been closed successfully.\nGood bye!\n");
}




