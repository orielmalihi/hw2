/*
 * myBank.c
 *
 *  Created on: 19 Nov 2019
 *      Author: oriel
 */
#define Num_Of_Accounts 50
#define Account_Info 2
#define Account_status 0
#define Account_balance 1
#define CLOSE 0
#define OPEN 1

#include "stdio.h"


double bank[Account_Info][Num_Of_Accounts] = {{0},{0}};

void clearInputBuffer(){
	char c = 'a';
	while ( c != '\n' && c!=' '){
		c = getchar();
	}
}

void open(double amount){
	int accountNumber;
	for(int i = 0; i<Num_Of_Accounts; i++){
		if(bank[Account_status][i]==CLOSE){
			bank[Account_status][i]=OPEN;
			accountNumber = i + 901;
			if(amount<0){
				printf("Depoisit was unsuccessful.\nCan not deposit a negative amount.\n");
				return;
			}
			bank[Account_balance][i] += amount;
			printf("your account number is %d , and your current balance is %0.2lf\n", accountNumber, bank[Account_balance][i]);
			return;
		}

	}
	printf("Could not open an account.\nall accounts are occupied.\n");

}
void balance(int accountNumber){
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[Account_status][accountNumber]==CLOSE){
		printf("This account is closed\n");
	}
	else{
		printf("your current balance is %0.2lf\n", bank[Account_balance][accountNumber]);
	}
}

void deposit(int accountNumber, double amount){
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[Account_status][accountNumber]==CLOSE){
		printf("This account is closed\n");
		return;
	}else if(amount<0){
		printf("Depoisit was unsuccessful.\nCan not deposit a negative amount\n");
		return;
	}
	bank[Account_balance][accountNumber] += amount;
	printf("your current balance is %0.2lf\n", bank[Account_balance][accountNumber]);
}


void withrow(int accountNumber, double amount){
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[Account_status][accountNumber]==CLOSE){
		printf("This account is closed\n");
		return;
	}else if(amount<0){
		printf("Withrow was unsuccessful.\nCan not withrow a negative amount\n");
		return;
	}
	bank[Account_balance][accountNumber] -= amount;
	if(bank[Account_balance][accountNumber]<0.0){
		bank[Account_balance][accountNumber] += amount;
		printf("Withrow was unsuccessful.\nYou do not have enugh money in this account.\n");
		return;
	}
	printf("your current balance is %0.2lf\n", bank[Account_balance][accountNumber]);
}


void close(int accountNumber){
	accountNumber -= 901;
	if(accountNumber<0 || accountNumber>49){
		printf("This account is not in our bank\n");
		return;
	}
	if(bank[Account_status][accountNumber]==OPEN){
		bank[Account_status][accountNumber]=CLOSE;
		bank[Account_balance][accountNumber]=0;
		printf("Closing the account was successful\n");
	}
	else{
		printf("This account is already closed\n");
	}
}

void interestRate(double interestRate){
	interestRate /= 100;
	interestRate += 1;
	for(int i = 0; i<Num_Of_Accounts; i++){
		if(bank[Account_status][i]==OPEN)
			bank[Account_balance][i] *= interestRate;
	}
}

void printAccounts(){
	for(int i = 0; i<Num_Of_Accounts; i++){
		if(bank[Account_status][i]==OPEN){
			int accountNumber = i+901;
			printf("Account number %d has balance of %0.2lf $\n", accountNumber, bank[Account_balance][i]);
		}
	}
}

void end(){
	for(int i = 0; i<Num_Of_Accounts; i++){
		if(bank[Account_status][i]==OPEN){
			bank[Account_status][i]=CLOSE;
			bank[Account_balance][i]=0;
		}
	}
	printf("All accounts have been closed successfully.\nGood bye!\n");
}




