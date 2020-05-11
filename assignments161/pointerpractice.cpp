#include <iostream>
#include <string>

using namespace std;

int change_string(string guess, string comparing, string *changelet){
   
   int x=0;
   for(int i=1; i<= comparing.length(); i++){
      if (comparing[i] == guess[0]){
         x++;
	 changelet[i]=guess;
	return x;    
      }
   }
}

string make_puzzle(string original, string mystr){
   
   for( int i=0; i< original.length(); i++){
      if(original[i] == ' '){}
      else{
          mystr[i]='_';
      }
   }
   cout << mystr << endl;
      return mystr;
}



int main(){
   string mystr, guess, original;
   string *changelet;
      changelet= &mystr;
   int numinstr;

   cout << "enter a puzzle: ";
   getline(cin, original);

   original=mystr;
   mystr=make_puzzle(original, mystr);

   cout << "the puzzle is:" << mystr << endl;

//   cout << "guess a letter";
//   getline(cin, guess);

//   guess_lett(original, guess, &mystr);

   cout << original << endl;
   cout << mystr << endl;

      
   cout << "enter a guess: ";
   getline(cin, guess);

   cout << "your current puzzle is:" << mystr << endl;

   numinstr=change_string(guess, original, &mystr);
   cout << "number of times you guess occurs: " << numinstr << endl;
   cout << "your updated puzzle is:" << mystr << endl;
      
   return 0;
}
