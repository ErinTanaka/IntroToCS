#include <iostream>

using namespace std;

int main() {

   int store_a, store_b, store_c;
   // getting user input
   cout << "Please enter today's sales rounded to the nearest hundred:\n";
   cout << "Store A: ";
   cin >> store_a;

   cout << "Store B: ";
   cin >> store_b;
   
   cout << "Store C: ";
   cin >> store_c;

   // calculating number of asterisks for bar graph
   
   int count_a, count_b, count_c;

   count_a = store_a / 100;
   count_b = store_b / 100;
   count_c = store_c / 100;

  // cout << count_a << endl;
  // cout << count_b << endl;
  // cout << count_c << endl;

   
   // printing asterisks
   cout << "Daily Sales:" << endl;
   cout << "each * = $100" << endl;

int x;

   cout << "Store A: ";
   
      for( x = 1 ; x <= count_a; x++){
   	   cout << "*";
      }  
      cout << "\n";

   cout <<"Store B: ";
      for(x = 1; x <= count_b; x++){
	   cout << "*";
      }
      cout << "\n";

   cout <<"Store C: ";
      for(x = 1; x <= count_c; x++){
	   cout << "*";
      }
      cout << "\n";

return 0;
}
