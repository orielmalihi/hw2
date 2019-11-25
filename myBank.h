/*
 * myBank.h
 *
 *  Created on: 19 Nov 2019
 *      Author: oriel
 */

#ifndef MYBANK_H_
#define MYBANK_H_

void open(double amount);
void balance(int accountNumber);
void deposit(int accountNumber, double deposit);
void withrow();
void close();
void interestRate();
void printAccounts();
void end();
void clearInputBuffer();



#endif /* MYBANK_H_ */
