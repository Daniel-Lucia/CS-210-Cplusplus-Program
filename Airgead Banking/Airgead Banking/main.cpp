/*
 * main.cpp
 *
 *  Date: 11/27/2022
 *  Author: Daniel Lucia
 */
#include "InterestCalc.h"
#include <iomanip>
#include <iostream>
using namespace std;

//Sets the values for public variables using instances
Savings::Savings(double t_investment, double t_monthDeposit, double t_annualRate,
	int t_years) {
	this->m_initialDeposit = t_investment;
	this->m_monthlyDeposit = t_monthDeposit;
	this->m_interestRate = t_annualRate;
	this->m_numYears = t_years;
}
//Prints the report without additional monthly deposit
void Savings::noAdditionalDeposits() {
	//Prints the heading
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout <<
		"==========================================================================" <<
		endl;
	//Prints the table headings
	cout << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout <<
		"--------------------------------------------------------------------------" <<
		endl;
	//Loop for given years and calculating the interest earned
	int currentYear = 1;
	double yearEndBalance = this->m_initialDeposit;
	while (currentYear <= this->m_numYears) {
		//Calculates interest
		double interestEarned = yearEndBalance * this->m_interestRate / 100;
			//Adds it to the year end balance for total
			yearEndBalance += interestEarned;
		//Prints the results
		cout << right << setw(10) << currentYear << fixed << setprecision(2)
			<< setw(20) << yearEndBalance
			<< setw(35) << interestEarned << endl;
		//Increase the year by one until the users year is reached
		currentYear++;
	}
}
//Prints report with additional monthly deposit
void Savings::withAdditionalDeposits() {
	//Prints the heading
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout <<
		"==========================================================================" <<
		endl;
	//Prints the table headings
	cout << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout <<
		"--------------------------------------------------------------------------" <<
		endl;
	//Loop for given years and calculating interest earned just like previous loop
	int currentYear = 1;
	double yearEndBalance = this->m_initialDeposit;
	while (currentYear <= this->m_numYears) {
		//Calulates interest monthly and then finds total interest
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBalance = yearEndBalance;
		while (month <= 12) {
			//Add additional monthly deposit
				monthEndBalance += this->m_monthlyDeposit;
			//Calculates the monthly interest for the year
				double monthlyinterest = monthEndBalance * this->m_interestRate / (100 * 12);
			//Adds the monthly interest to yearly interest earned
			interestEarned += monthlyinterest;
			//Adds the interest to month end balance
			monthEndBalance += monthlyinterest;
			//Increase the month by 1 until reaches 12
			month++;
		}
		//After 12 months
		yearEndBalance = monthEndBalance;
		//Prints the results
		cout << right << setw(10) << currentYear << fixed << setprecision(2)
			<< setw(20) << yearEndBalance
			<< setw(35) << interestEarned << endl;
		//Increase the year count by one
		currentYear++;
	}
}