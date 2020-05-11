#include <iostream>
#include <cstring>
#include <istream>

using namespace std;

//prototyping functions
int user_choice();
void text_morse(char text[28], char morse[28][8]);
void morse_text(char text[28], char morse[28][8]);
int get_input(char user[], int length);


int main(){
   char text[28]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '\0'};
   char morse[28][8]={".-   ", "-...   ", "-.-.   ", "-..   ", ".   ","..-.   ", "--.   ", "....   ", "..   ", ".---   ", "-.-   ", ".-..   ", "--   ", "-.   ", "---   ", ".--.   ", "--.-   ", ".-.   ", "...   ", "-   ", "..-   ", "...-   ", ".--   ", "-..-   ", "-.--   ", "--..   ", "    ", '\0'};
   int choice;
  
   cout << "What would you like to do?" << endl;
 
   cout << "Translate text to morse (1) or morse to text(2): ";
 
   choice = user_choice();
 
   cout << "\n";

   if (choice==1) text_morse(text, morse);
   else morse_text(text, morse);
 
   return 0;
}
/************************************************
 *Function: user_choice
 *Description: takes in users choice of whether to translate from morse cod to text or vise-versa error checks ints only no symbols or letters at cutternt time
 *Parameters: none
 *Pre-conditions: none
 *Post-conditions: int 1 or 2 will be returned
 ***********************************************/
int user_choice(){
   int choice;
   bool good = false; //determine if user has enerted in 1 or 2
   cin >> choice; 
   while (good == false){
      if (choice == 1){
         good = true;
      }
      else if(choice == 2){
         good = true;
      }
      else {
         cout << "please choose 1 or 2: ";
         cin >> choice;  //getting new input 
      }
   }
   return choice;
}


/************************************************
 *Function: text_morse
 *Description: translates text to morse code to use as "libraries"
 *Parameters: arrays of morse code and text
 *Pre-conditions:users choice was 1
 *Post-conditions: morsecode printed to screen
 ***********************************************/
void text_morse(char text[28], char morse[28][8]){
   //char input[6]={'h','e', 'l', 'l', 'o', '\0' };
   cout << "translation from text to morse code" << endl;
   cout << "\n";
   cout << "note: please enter 3 spases after last letter" << endl; 
   int searchtext = 0, readinput = 0, length;
   
   char input[256];
   length = get_input(input, 256);
   
   while (readinput < length){  //indexing through users input
      searchtext = 0;
      while (searchtext < 28){
         if (input[readinput] == text[searchtext]){  // comparing element to alphabet
	 cout << morse[searchtext];  // print corresponding letter of morse code
	    break;
	 }
	 else searchtext++;  // move to next letter in alphabet
      }
      readinput ++;  //move on to next element in user array
   }
}
/************************************************
 *Function: morse_text
 *Description: translate morsecode to text
 *Parameters: arrays of text and morse code to use as "libraries" 
 *Pre-conditions: users choice was 2
 *Post-conditions: text printed to screen
 ***********************************************/
void morse_text (char text[28], char morse[28][8]){
   cout << "Translation from morse to text" << endl;
   int index = 0, row = 0, col = 0, length = 500;
   char user[500];
   length = get_input(user, 500);
   //cout << "user[3]" << user[3] << endl;
   //cout << "now to translate" << endl; 
  
   while (row < 28){
     if (user[index] == '\0'){  //at the end of users input
       	break;
     }
     else if (user[index] == morse[row][col] && morse[row][col+1] == '\0'){ // letters match completely
	cout << text[row];
	index++;  //next user
	row = 0;  //start back at beginning of morse alphabet
	col = 0;  //startback at beginning of morse alphabet
     }
     else if (user[index] == morse[row][col]){  // one . or - matches
	index++;  //look at next element of user array
	col++;  //look at next element of letter in morse alphabet
     }
     else if (user[index] != morse[row][col]){  //nothing matches
	index = index-col;  //go back to beginning of current letter in user array
	row++;  // look at next in morse alphabet
	col = 0;  //reset to first element of morse letter
     }
  }
 cout << "\n";
// cout << "MISSION COMPLETION" << endl;
  }
/************************************************
 *Function: get_input
 *Description: takes input from user and stores in an array
 *Parameters: address of array to be translated
 *Pre-conditions: none
 *Post-conditions: user input gets stored in array user and returns length of array
 ***********************************************/
int get_input(char user[], int length){
   cout << "what would you like to translate: ";
      cin.ignore();
      cin.get(user, length);
      for (int i = 0; i < length; i++){
         if (user[i+1] == '\0') length = i+1;
      }

return length;    

}

/***********************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-conditions:
 * Post-conditions:
***********************************************/

