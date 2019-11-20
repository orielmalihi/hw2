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
	printf("E : close all open accounts and finish\n\n");
	char ans = 'a';
	while(ans!='E'){
		printf("Transaction type?\n");
		scanf(" %c", &ans);
		switch (ans)
		{
		case 'O':
			open();
			break;
		case 'B':
			balance();
			break;
		case 'D':
			deposit();
			break;
		case 'W':
			widrow();
			break;
		case 'C':
			close();
			break;
		case 'I':
			interestRate();
			break;
		default:
			printf("you eneterd incorrect letter, try again please.\n");
			break;
		}
	}
	return 0;
}


