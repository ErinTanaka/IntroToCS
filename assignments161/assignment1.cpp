#include <iostream>
#include <cmath>
#include <climits>


using namespace std;

int main(){

//******************************************************************************

// Part 1

// Setting Pi as a variable

	double  Pi;
	Pi=4.0*atan(1.0);

// Basic trignometric and logarithmic functions

	cout <<"cos(2Pi/3)=" << cos(2*Pi/3) << endl;
	cout <<"2sin(2Pi/3)=" << 2*sin(2*Pi/3) << endl;
	cout <<"tan(-3Pi/4)=" << tan(-3*Pi/4) << endl;
	cout <<"log 55 =" << log10(55) << endl;
	cout <<"ln 60 =" << log(60) << endl;

// Logarithms with bases other than e or 10

	cout <<"log base b of x = (lnx)/(lnb)" << endl;
	cout <<"log base 2 of 15 = ln15/ln2 = " << log(15)/log(2) << endl; 
	cout <<"log base 4 of 40 = ln40/ln4 = " << log(40)/log(4) << endl;

// Expononetials using function pow()

	cout <<"3^(sinx)" << endl;
	cout <<"x=1 3^sin(1) = " << pow (3.0, sin(1)) << endl;
	cout <<"x=10 3^sin(10) = " << pow (3.0, sin(10)) << endl;
	cout <<"x=100 3^sin(100) = " << pow (3, sin(100)) <<endl;

// Logarithms with exponents

	cout <<"log base 2 of (x^2 +1)" << endl;
	cout <<"x=1 log base 2 of (1^2 +1)" << endl;
	cout <<"1^2 +1 = " << pow (1, 2) + 1 << endl;
	cout <<"log base 2 of 2 = ln2/ln2 = " << log(2)/log(2) << endl;

	cout <<"x=10 log base 2 of (10^2 +1)" << endl;
	cout <<"10^2 +1 = " << pow (10, 2) + 1 << endl;  
	cout <<"log base 2 of (101) = ln101/ln2 = " << log(101)/log(2) << endl;

	cout <<"x=100 log base 2 of (100^2 +1)" << endl;
	cout <<"100^2 +1 = " << pow (100, 2) + 1 << endl;
	cout <<"log base 2 of (10001) = ln10001/ln2 = " << log(10001)/log(2) << endl;

//****************************************************************************** 
// Part 2

// Print short, int, & long; signed & unsigned; max and min

	cout <<"min short int:" << SHRT_MIN << endl;
	cout <<"short int:" << SHRT_MAX << endl;
	cout <<"unsigned short int:" << USHRT_MAX << endl;
	
	cout <<"min int:" << INT_MIN << endl;
	cout <<"int:" << INT_MAX << endl;
	cout <<"unsigned int:" << UINT_MAX << endl;
	
	cout <<"min long int:" << LONG_MIN << endl;
	cout <<"long int:" << LONG_MAX << endl;
	cout <<"unsigned long int:" << ULONG_MAX << endl;

// Creating variables for max & min; short, int, & long; signed & unsigned

 	short shortmin = pow(-2, sizeof(short)*8-1);
	short shortmax = pow(2, sizeof(short)*8-1)-1;
	unsigned short ushortmax = pow(2, sizeof(unsigned short)*8)-1;

	int intmin = pow(-2, sizeof(int)*8-1);
	int intmax = pow(2, sizeof(int)*8-1)-1;
	unsigned int uintmax = pow(2, sizeof(unsigned int)*8)-1;
 	
	long longmin = (long)pow(-2, sizeof(long)*8-1);
	long longmax = (long)pow(2, sizeof(long)*8-1)-1;
	unsigned long ulongmax = (unsigned long)pow(2, sizeof(unsigned long)*8)-1;


	cout << shortmin << endl;
	cout << shortmax << endl;
	cout << ushortmax << endl;
	cout << intmin << endl;
	cout << intmax << endl;
	cout << uintmax << endl;
	cout << longmin << endl;
	cout << longmax << endl;
	cout << ulongmax << endl;


	return 0;
}
