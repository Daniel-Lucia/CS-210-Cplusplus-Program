/*
 * InterestCalc.h
 *
 *  Date: 11/27/2022
 *  Author: Daniel Lucia
 */
#ifndef InterestCalc_h
#define InterestCalc_h
#include <stdio.h>
// Sets Class public and privite variables
class Savings {
public:
	Savings(double t_investment, double t_monthDeposit, double t_annualRate,
		int t_years);
	void noAdditionalDeposits();
	void withAdditionalDeposits();

private:
	double m_initialDeposit;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numYears;
};
#endif