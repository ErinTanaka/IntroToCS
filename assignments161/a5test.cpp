/************************************************
 *taking text and finding the corresponding morse 
 *
 *
 *
 * */
#include <iostream>
#include <cstring>
#include <istream>
using namespace std;

void get_input(char user[], int length);

int main(){
   char alpha[28]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '\0'};
   char  morse[28][8]={".-   ", "-...   ", "-.-.   ", "-..   ", ".   ", "..-.   ", "--.   ", "....   ", "..   ", ".---   ", "-.-   ", ".-..   ", "--   ", "-.   ", "---   ", ".--.   ", "--.-   ", ".-.   ", "...   ", "-   ", "..-   ", "...-   ", ".--   ", "-..-   ", "-.--   ", "--..   ", "    ",'\0'}; 
char user[2500];
get_input(user, 2500);
cout << "back in main" << endl;
cout << user << endl;
cout << "done" << endl;


return 0;   
}   
 
void get_input(char user[], int length){
//int length=2500; 
// char user[length];
   cin.get(user, length);
   
   for (int i=0; i<length; i++){
      if (i+1 == '\n') length=i;
   }

   cout << strlen(user)<< endl;
   cout << user << endl;
   cout << user[3] << endl;
}
   /* cout << "getting input from user: " << endl;
  int max = 3;
  int* a = new int[max];
  int n=0;
  while (cin >> a[n]){
     n++;
     if(n>=max){
	max = max*2;
	int* temp = new int[max];
	for (int i=0; i<n; i++){
	   temp[i]=a[i];
	}
	delete[] a;
	a=temp;  
     }    
  }
  cout << a[3] << endl;
*/
   /*
char user[20]={"....   ..   -.-.   "};

   int col=0, row=0 , index=0;
  while (row<28){
     if (user[index]=='\0'){
        break;
     }
     else if (user[index] == morse[row][col] && morse[row][col+1] == '\0'){
	   cout << alpha[row];
	   index++;
	   row=0;
	   col=0;
	 }
	else if (user[index] == morse[row][col]){
	    index++;
	    col++;
	 }
	else if (user[index] != morse[row][col]){
	   index=index-col;
	   row++;
	   col=0;
	}  
   }
cout << "\n";   
cout << "boom donezo" << endl;
*/
   
/*     int searchingmorse=0, readinput=0;
   while (readinput < 3){//3 is length of users input
     while (searchingmorse<28){ 
     
      if (input[readinput][0] == morse[searchingmorse][0]){
         //cout << input[readinput] << " is " << alpha[searchingmorse] << endl;
         break;	 

      }
      else{ 
        searchingmorse++;
      }
     }
   cout << "you made it out of the loop, on to the next letter?" << endl;
   readinput++;
   }
    cout << "youre done" << endl;  
*/


