#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//write a program that calculates 
//1) the amount of money in an account after a certain amount of time, interest rate, and with a starting balance.
//2) the required starting balance of an account given a final amount, time, and interest rate.


double calculateFinalAmount(float principal, float interest_rate, float time, int periods) {
	double return_value = principal*pow(1 + (interest_rate/periods), time * periods);
	return return_value;
}

double calculatePrincipalAmount(float amount, float interest_rate, float time, int periods) {
	double a = log(amount) / (time * periods);
	double b = a - log(1 + interest_rate / periods);
	double return_value = exp(b);	
	return return_value;
}


void promptValues(char choice, bool &exit) {

	float balance, interest_rate, time, periods;
	
	if (choice == 49) {
		cout << "Calculating future value." << endl;

		cout << "Please enter principal amount:";
		cin >> balance;

		cout << "Please enter the interest rate:";
		cin >> interest_rate;

		cout << "Please enter the unit time length which the interest is applied on:";
		cin >> time;

		cout << "Please enter how many periods there are:";
		cin >> periods;

		cout << "Final account balance: " << calculateFinalAmount(balance, interest_rate, time, periods) << endl;

	}

	else if (choice == 50) {
		cout << "Calculating past value." << endl;

		cout << "Please enter the current amount:";
		cin >> balance;

		cout << "Please enter the interest rate:";
		cin >> interest_rate;

		cout << "Please enter the unit time length which the interest is applied on:";
		cin >> time;

		cout << "Please enter how many periods there are:";
		cin >> periods;

		cout << "Final account balance: " << calculatePrincipalAmount(balance, interest_rate, time, periods) << endl;

	}
	else if (choice == 48) {
		cout << "\nThank you for using our program! Exiting now.\n";
		exit = true;
	}
}

int main() {

	bool exit = false;

	while (!exit) {

		char choice;

		cout << "-------------------" << endl;
		cout << "Welcome to financial calculations app!" << endl;
		cout << "-------------------" << endl;

		cout << "Enter 1 if you want to find a future amount." << endl;
		cout << "Enter 2 if you want to find a past amount." << endl;
		cout << "Enter 0 if you want to exit." << endl;

		cout << "Your choice: ";


		cin.get(choice);

		promptValues(choice, exit);
		cin.ignore();
	}
	
	return 0;
}