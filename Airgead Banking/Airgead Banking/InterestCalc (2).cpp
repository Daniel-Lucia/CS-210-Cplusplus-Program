/*
 * InterestCalc.cpp
 *
 *  Date: 11/27/2022
 *  Author: Daniel Lucia
 */
#include <iostream>
#include <string>
#include "InterestCalc.h"
using namespace std;

int main() {
	while (1) {
		//Shows user the Menu
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
		system("PAUSE");
		system("CLS");

		//Gets inputs from the user
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: $";
		double intInvestment, monthlyDeposit, interestRate;
		int years;
		cin >> intInvestment;
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest: %";
		cin >> interestRate;
		cout << "Number of years: ";
		cin >> years;
		system("PAUSE");
		system("CLS");
		

			//Creates savings object using users inputs
			Savings mySavings = Savings(intInvestment, monthlyDeposit, interestRate,
				years);
		cout << endl;

		//Calls the report methods
		mySavings.noAdditionalDeposits();
		cout << endl;

		//Calls monthly deposit report if there is monthly deposit with at least $1
		if (monthlyDeposit > 0) {
			mySavings.withAdditionalDeposits();
		}

		//Lets the user enter new values
		cout << endl << "Do you want to enter new values? (y/n): ";
		string userInput;
		cin >> userInput;

		//If user does not want to the loop breaks 
		if (userInput != "y") {
			break;
		}
		cout << endl;
	}
	return 0;
}
