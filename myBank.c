/*
 * myBank.c
 *
 *  Created on: 19 Nov 2019
 *      Author: oriel
 */
#define NumOfAccounts 50
#define AccountStatus 2

double bank[AccountStatus][NumOfAccounts] = {{0},{0}};

void open(){
	double deposit;
	int accountNumber;
	for(int i = 0; i<NumOfAccounts; i++){
		if(bank[0][i]==0.0){
			bank[0][i]=1.0;
			accountNumber = i + 901;
			printf("Initial deposit?\n");
			scanf("%lf", &deposit);
			bank[1][i] += deposit;
			printf("your account number is %d , and your current balance is %0.2lf\n", accountNumber, bank[1][i]);
			return;
		}

	}
	printf("Could not open an account\nall accounts are occupied\n");
	return;
}
void balance(){
	int accountNumber;
	printf("Account number?\n");
	scanf("%d", &accountNumber);
	accountNumber -= 901;
	if(bank[0][accountNumber]==0.0){
		printf("The account is closed\n");
	}
	else{
		printf("your current balance is %0.2lf\n", bank[1][accountNumber]);
	}
}



