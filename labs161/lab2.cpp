#include <iostream>

using namespace std;

int main(){

	
	int choice;
	cout << "You just won an all expenses paid trip!" << endl;
	cout << "You have the option to go to Switzerland or Venice, Italy" << endl;
	cout << "Enter 1 to go to Switzerlana or 2 to go to Venice" << endl;
	cin >> choice;

	if (choice == 1);
	{
		cout << "You have chosen to go to Switzerland\n";
		cout << "Would you like to go explore(1) or visit the Matterhorn(2)" << endl;
		cin >> choice;
			if (choice == 1)
			{
				cout << "As you walk around town you run into some mountainbikers"<< endl;
				cout << "They teach you an awesome and slightly hazardous new hobby, ";
				cout << "and you spend the rest of your time in Switzerland mountain biking" << endl;
			} 
			else if (choice == 2)
			{
				cout << "At the Matterhorn you get your picture taken with the famous st. bernard, and " << endl; 
				cout << "while picnicing you meet some seemingly nice strangers." << endl; 
			}



	}



	return 0;
}
