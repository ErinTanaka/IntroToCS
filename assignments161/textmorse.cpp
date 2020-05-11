/************************************************
 *taking text and finding the corresponding morse 
 *
 *
 *
 * */
#include <iostream>
#include <cstring>

using namespace std;

//void get_input;
//void morse_text;
//void text_morse

int main(){
   char alpha[28]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '\0'};
   char  morse[28][8]={".-   ", "-...   ", "-.-.   ", "-..   ", ".   ", "..-.   ", "--.   ", "....   ", "..   ", ".---   ", "-.-   ", ".-..   ", "--   ", "-.   ", "---   ", ".--.   ", "--.-   ", ".-.   ", "...   ", "-   ", "..-   ", "...-   ", ".--   ", "-..-   ", "-.--   ", "--..   ", "    ",'\0'}; 
  
  
  //cout << morse[23] << endl;
  // char morse
   
   //string *m = morse;
   int choice;
   char  input[3]={'c', 'h', '\0'};
   //char * midd = input;
   //char * text = alpha;
   //int location;
   //cout << "Please select one of the following: morse to text, text to morse, quit: ";
   //cin >> choice;
   
     // if (choice==1) morse_test(); 
     // else if (choice==2) text_morse();
     // else if (choice==3) return 0;
   

  // cout << "enter a phrase to be converted: ";
  // cin >> input;
   
  // cout << "your input: " << input << endl;
   
     int searchingalpha=0, readinput=0;
   while (readinput < strlen(input)){//3 is length of users input
      while (searchingalpha<28){ 
     
         if (input[readinput] == alpha[searchingalpha]){
            cout << input[readinput] << " is " << morse[searchingalpha] << endl;
            break;	 
	 }
         else{ 
            searchingalpha++;
	 }
     }
   cout << "you made it out of the loop, on to the next letter?" << endl;
   readinput++;
   }
    cout << "youre done" << endl;  

   return 0;
}
