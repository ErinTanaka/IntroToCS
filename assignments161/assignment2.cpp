/*********************************************************************
 *  Program Filename: assignment2.cpp
 *  Author: Erin Tanaka
 *  Date: January 18, 2015
 *  Description: Financial Calculator
 *  Input:
 *  Output:
 ********************************************************************/


#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{

	cout << "Hello, welcome to your financial calculator!" << endl;
	cout << "Which of the following would you like to calculate?" << endl;
	cout << "1 - Loan Balance" << endl;
	cout << "2 - Continuously Compounded Interest" << endl;
	cout << "3 - Future Value" << endl;

	int choice;
	cin >> choice;


// 1. Loan Balance

		if (choice == 1)
		{	
			cout << "You selected 1 -  Loan Balance" << endl;
			cout << "Please enter values as prompted." << endl;
			
			int  n;
			float A, i, P,  goal;
			
			cout << "Initial Investment(in dollars eg 45000): $";
			cin >> A;
			cout << "Interest rate per period (as decimal): ";
			cin >> i;
			cout << "Amount of each equal payment (in dollars eg 600): $";
			cin >> P;
			cout << "Number of payment periods: ";
			cin >> n;
			cout << "Goal (balance after n payment periods): $";
			cin >> goal;

	//Calculation B = A(1+i)^n - (P/i) * [(1+i)^n - 1]

			float B;
			B = A * pow((1+i), n) - (P/i)*(pow((1+i), n) - 1);

	//Print balance and compare to goal

			cout << " Your balance will be: $";
			printf ("%.2f \n", B ); 

				if (B > goal)
				{
					cout << "Sorry, you will not meet your goal" << endl;
				}
				else if (B < goal)
				{
					cout << "Congrats, you will exceed  your goal!" << endl;
				}
				else
				{
					cout << "Congrats, you will meet your goal!" << endl;
				}
		
		}

// 2. Continually Compounded Interest

		else if (choice == 2)
		{
			cout << "You have selected 2 - Continuously Compounded Interest" << endl;
			cout << "Please enter values as prompted." << endl;
			
			int  t;
			float P, r, goal;
			
			cout << "Principal investment: $";
			cin >> P;
			cout << "Annual interest rate (as decimal eg 9% would be 0.09): ";
			cin >> r;
			cout << "Number of years compounding: ";
			cin >> t;
			cout << "Goal amount in dollars by provided time: $";
			cin >> goal;

	// Calculation A = P * r^t
	
			float A;
 			A = P * exp (r * t);
			cout << "You will have: $";
			printf ("%.2f \n", A ); 

	//Print balance and compare to goal
	
				if (A == goal)
				{
					cout << "Congrats, you will meet your goal!" << endl;
				}
				else if (A > goal)
				{
					cout << "Congrats, you will exceed your goal!" << endl;
				}
				else
				{
					cout << " Sorry, you will not meet your goal." << endl;
				}
		}
// 3. Future Value
		else if (choice == 3)
		{
			cout << "You have selected 3 - Future value" << endl;
			cout << "Please enter values as prompted." << endl;
			
			int n;
			float C, r, goal;
			
			cout << "Initial Value : $";
			cin >> C;
			cout << "Rate of return (as decimal eg 9% would be 0.09): ";
			cin >> r;
			cout << "Number of periods: ";
			cin >> n;
			cout << "Goal value after n time periods: $";
			cin >> goal;

	// Calculation FV = C * (1 + r)^n

			float FV;
			FV = C * pow(1 + r, n);
			cout << "You will have: $";
			printf ("%.2f \n", FV ); 
	
	// Print balance and compare to goal	
				if (FV == goal)
				{
					cout << "Congrats, you will meet your goal!" << endl;
				}
				else if (FV > goal)
				{
					cout << "Congrats, you will exceed your goal!" << endl;
				}
				else
				{
					cout << "Sorry, you will not meet your goal." << endl;
				}

		}
		else
		{
			cout << "Enter values 1 2 or 3" << endl;
		}
	return 0;


}



