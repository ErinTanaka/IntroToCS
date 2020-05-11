/***************************************************************************
 *Program Filename:
 *Author:
 *Date:
 *Description:
 *Input:
 *Output:
 **************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// functions
void get_puzzle(string &original_phrase, string &comparing_phrase, string &guessing_phrase); 
string convert_string(string str);
string make_space(string str);
void players_rounds(int &num_players, int &round_total);
bool choice_spin(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase);
int spin_wheel();
int bankrupt(int current_player, int &p1_round, int &p2_round, int &p3_round);
bool choice_vowel(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase);      
int update_puzzle(char guess, string comparing_phrase, string &guessing_phrase);
bool check_money(int current_player, int p1_round, int p2_round, int p3_round);
bool check_puzzle(string &comparing_phrase, string &guessing_phrase);
bool choice_solve(int current_player, int &p1_round, int &p2_round, int &p3_round, string original_phrase);      
int update_round(int spin, int count, int &p1_round, int &p2_round, int &p3_round, int current);



int main(){
   string original_phrase, comparing_phrase, guessing_phrase;
   int num_players=0, round_total=0, current_player=1, current_round=1, p1_round, p2_round, p3_round, p1_total, p2_total, p3_total;
   int choice; 
   bool round=true, player=true;

   get_puzzle(original_phrase, comparing_phrase, guessing_phrase);
   players_rounds(num_players, round_total);
   do{
      cout << "The puzzle is: " << guessing_phrase << endl;
      cout << "Spin (1), Buy a vowel(2), Solve(3): ";
      cin >> choice;
	 if (choice==1)  player = choice_spin(current_player, p1_round, p2_round, p3_round, comparing_phrase, guessing_phrase); 
	 else if (choice==2) player = choice_vowel(current_player, p1_round, p2_round, p3_round, comparing_phrase, guessing_phrase);
	 else if (choice==3) player = choice_solve(current_player, p1_round, p2_round, p3_round, original_phrase);


   }while(player=true);   
   player++; 
   return 0;
}

/**************************************************************************/
void players_rounds(int &num_players, int &round_total){
   cout << "Number of players: ";
   cin >> num_players;
   cout << "Number of rounds/puzzles: ";
   cin >> round_total;

}


/**************************************************************************/
int spin_wheel(){
   int spin = rand() % 22;
   return spin;
}

/*************************************************************************/
string convert_string(string str){
   int x = 0, strlen = str.length();
   do{
      if (str[x] == ' '){
      }
      else{
	 str[x] = '_';
      } 
      x=x+1;
   }while (x <= strlen);
   
   return str;
}
/***********************************************************************/
string make_space(string str){

   string insert=" ";
   int x = str.length();
   for(x; x > 0; x--){
      str.insert(x,insert);
   }
   return str;
}

/********************************************************************/
int update_puzzle(char guess, string comparing_phrase, string &guessing_phrase){
   int count = 0;
   for(int i = 0; i < comparing_phrase.length(); i++){
      if (comparing_phrase[i] == guess){
	 count++;
    	 guessing_phrase[i] = guess;
      }   
   }
   return count;
}
/***********************************************************************/
int update_round(int spin, int count, int &p1_round, int &p2_round, int &p3_round, int current_player){
   int x = spin*count;
   if (current_player == 1){
      p1_round = x;
   }
   else if (current_player == 2){
      p2_round = x;
   }
   else{
      p3_round = x;
   }
   return x;
}
/***********************************************************************/
int bankrupt(int current_player, int &p1_round, int &p2_round, int &p3_round){
   if (current_player == 1){
      p1_round = 0;
   }
   else if(current_player == 2){
      p2_round = 0;
   }
   else{
      p3_round = 0;
   }
   return 0;
}
/***********************************************************************/
bool check_money(int current_player, int p1_round, int p2_round, int p3_round){
   if (current_player == 1){
      if (p1_round >= 10) return true;
      else return false;
   }   
   else if (current_player == 2){
      if (p2_round >= 10) return true;
      else return false;
   }   
   else{
      if (p3_round >= 10) return true;
      else return false;
   }   
}
/***********************************************************************/
void get_puzzle(string &original_phrase, string &comparing_phrase, string &guessing_phrase){ 
   cout << "Please enter a word or phrase to be guessed:";
   getline(cin, original_phrase);
   comparing_phrase = make_space(original_phrase);
   guessing_phrase =  convert_string(comparing_phrase);
}   
/*********************************************************************/
bool choice_spin(int current_player, int &p1_round, int &p2_round, int &p3_round, string &comparing_phrase, string &guessing_phrase){
   char guess_consonant;
   int spin_result, temptotal, count;
   spin_result = spin_wheel();
   cout << "Your spin: " <<  spin_result << endl;
      if (spin_result == 0){
	 cout << "bankrupt" << endl;
	 temptotal = bankrupt(current_player, p1_round, p2_round, p3_round); 
         cout << "Round total; " << temptotal << endl;
	 return  false;   
      }
      else if(spin_result==21){
	 cout << "End of turn" << endl;
	 return  false;
      }
      else{
         cout << "Guess a consonant";
	 cin >> guess_consonant;
	 count = update_puzzle(guess_consonant, comparing_phrase, guessing_phrase);
         cout << "Number in puzzle: " << count << endl;
	    if (count == 0){
	       return false;	  
  	    }
            else{
	       temptotal = update_round(spin_result, count, p1_round, p2_round, p3_round, current_player);
	       cout << "round total: " << temptotal << endl;
               return true;	  
	    }
      }
}
/***********************************************************************/

bool choice_vowel(int current_player, int &p1_round, int &p2_round, int &p3_round, string &comparing_phrase, string &guessing_phrase){      
   char guess_vowel;
   int count;
   int pay_vowel = check_money(current_player, p1_round, p2_round, p3_round);
   if (pay_vowel == true){
      cout << "Guess a vowel: ";
      cin >> guess_vowel;
      count = update_puzzle(guess_vowel, comparing_phrase, guessing_phrase);
      cout << "number in puzzle: " << count << endl;
      if (count == 0){
	 return false;	          
      }	          
      else{            
	 return true;	          
      }	    
   }
   else{
      cout << "You do not have enough money" << endl;
      return false;
   }   
}
/*********************************************************************/
bool choice_solve(int current_player, int &p1_round, int &p2_round, int &p3_round, string original_phrase){
   string guess_all;
   cout << "Enter guess for solving puzzle: ";
   getline(cin, guess_all);
   check_puzzle(guess_all, original_phrase);
	   

   { }
}
/**********************************************************************/

bool check_puzzle(string &comparing_phrase, string &guessing_phrase){
   if (comparing_phrase == guessing_phrase){
      return true;
   }
   else{
      return false;
   }
}




