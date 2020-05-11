/*
 * THERE ARE BUGS IN THE FOLLOWING CODE.
 * */
#include <iostream>
using namespace std;

int main(){

	int x=3, y, num;
	char myAnswer;

	y = x;
	cout << "y is set to: " << y << endl;
//is input greater than or less than x
	cout << "Please input a number: ";
	cin >> y;
	int again = true;
	while(again == true){
		if(x > y){
			cout << "X is greater than Y\n";
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?" << endl;
			cin >> again;
		}
	}

//count from 0-10	
	for(x = 0; x <= 10 ;x= x+1){
		cout << x << endl;
	}
//factorial for given number	
	
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
//	int 
	for(int x = num; x  > 1; x--){
		num  = num * (x-1);
		   cout << num << endl;

	}	

//y/n question
	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
		if(myAnswer == 'y'){
			cout << "YAY" << endl;
		}
		else{
			cout << "YOU WILL SOON!" << endl;
		}							
	return 0;
}
