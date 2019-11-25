/*
 * main.c
 *
 *  Created on: 19 Nov 2019
 *      Author: oriel
 */
#include "stdio.h"
#include "myBank.h"

int main(){
	printf("Please enter a specific letter (MUST BE A BIG LETTER) to do one of this transaction type:\n\n");
	printf("O : to open an account and deposit inital money\n");
	printf("B : to get the balance in your account\n");
	printf("D : to deposit into your account\n");
	printf("W : to widrow from your account\n");
	printf("C : to close your account\n");
	printf("I : to add interest rate to all accounts\n");
	printf("P : print all open accounts and their balance\n");
	printf("E : close all open accounts and ending the program\n\n");
	char ans = 'a';
	double amount;
	double rate;
	int accountNumber;
	while(ans!='E'){
		printf("Transaction type?\n");
		scanf(" %c",&ans);
		clearInputBuffer();
		switch (ans)
		{
		case 'O':
			printf("Initial deposit?\n");
			scanf(" %lf",&amount);
			open(amount);
			break;
		case 'B':
			printf("Account number?\n");
			scanf(" %d", &accountNumber);
			balance(accountNumber);
			break;
		case 'D':
			printf("Account number?\n");
			scanf(" %d", &accountNumber);
			clearInputBuffer();
			printf("Amount?\n");
			scanf(" %lf", &amount);
			deposit(accountNumber, amount);
			break;
		case 'W':
			printf("Account number?\n");
			scanf(" %d", &accountNumber);
			clearInputBuffer();
			printf("Amount?\n");
			scanf(" %lf", &amount);
			withrow(accountNumber, amount);
			break;
		case 'C':
			printf("Account number?\n");
			scanf(" %d", &accountNumber);
			close(accountNumber);
			break;
		case 'I':
			printf("Interest rate?\n");
			scanf(" %lf", &rate);
			interestRate(rate);
			break;
		case 'P':
			printAccounts();
			break;
		case 'E':
			end();
			break;
		default:
			printf("you eneterd incorrect letter, try again please.\n");
			break;
		}
		if(ans != 'P' && ans != 'E')
			clearInputBuffer();
	}
	return 0;
}


