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
   for(x; x>0; x--){
      str.insert(x,insert);
   }
   return str;
}

/********************************************************************/
int update_puzzle(char guess, string comparing_phrase, string &guessing_phrase){
   int count=0;
   for(int i=0; i < comparing_phrase.length(); i++){
      if (comparing_phrase[i] == guess){
	 count++;
    	 guessing_phrase[i]= guess;
      }   
   }
   return count;
}
/***********************************************************************/
int update_round(int spin, int count, int &p1_round, int &p2_round, int &p3_round, int current_player){
   int x= spin*count;
   
   if (current_player==1){
      p1_round=x;
   }
   else if (current_player==2){
      p2_round = x;
   }
   else{
      p3_round = x;
   }
   return x;
}
/***********************************************************************/
void bankrupt(int current_player, int &p1_round, int &p2_round, int &p3_round){
   if (current_player==1){
      p1_round=0;
   }
   else if(current_player==2){
      p2_round=0;
   }
   else{
      p3_round=0
   }
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
void consonant(){
}
/***********************************************************************/
int main(){

   string original_phrase, comparing_phrase, guessing_phrase;//regarding the puzzle   
   char  guess_consonant, guess_vowel;
   string guess_all;//what player is inputting to make guess
   int num_players, current_player, round_total, current_round;//info regarding game
   int choice, spin_result, temptotal;
   int p1_total, p2_total, p3_total;
   int p1_round, p2_round, p3_round;
   int count;//number of letters guessed in puzzle
   bool chg_rnd = true; //will tell program when puzzle is guessed correctly
   bool player = true; //will tell program when to end player's turn
   bool mon_vowel;  
   srand (time(NULL));


//following takes in initial phrase, adds spaces inbetween each character and turns any non space characters into underscores
   cout << "Please enter a word or phrase to be guessed:";
   getline(cin, original_phrase);
   comparing_phrase = make_space(original_phrase);  
   cout << "phrase with spaces: "<< comparing_phrase << endl; //delete this line before turning in
   guessing_phrase = convert_string(comparing_phrase);
   cout << "puzzle to be displayed: " << guessing_phrase << endl; //delete this line before turning in
   
   cout << "Number of players (1-3): ";
   cin >> num_players;

   cout << "Number of rounds: ";
   cin >> round_total;

// setting round and player to begin the game
   current_round= 1;
   current_player=1; 

   do{ 
      cout << "Round " << current_round << endl;  
      do{
//	 int right_wrong=1;
         cout << "Player " << current_player << endl;

         cout << guessing_phrase << endl;

         cout << "Spin (1), Buy a Vowel (2), Solve (3): ";
         cin >> choice;
//spinning wheel
         if (choice==1){
	    cout << "Your spin:";
            spin_result = spin_wheel();
   	    cout << spin_result << endl;
	    if (spin_result==0){
	       cout << "bankrupt" << endl;
	       temptotal = 0;
	       bankrupt(current_player, p1_round, p2_round, p3_round); 
               cout << "Round total; " << temptotal << endl;
	       player = false;   
	    }
	    else if(spin_result==21){
	       cout << "End of turn";
	       player = false;
	    }
	    else{}
	       cout << "Guess a consonant";
	       cin >> guess_consonant;
	       count = update_puzzle(guess_consonant, comparing_phrase, guessing_phrase);

	       cout << "Number in puzzle: " << count << endl;
	          if (count==0){
	             player=false;	  
		  }
		  else{
		     temptotal=update_round(spin_result, count, p1_round, p2_round, p3_round, current_player);
		     cout << "round total: " << temptotal << endl;
                     player=true;
		  }
	       cout << "the puzzle is: " << guessing_phrase << endl;
         }   
//buying a vowel      
         else if (choice == 2){
            mon_vowel = check_money(current_player, p1_round, p2_round, p3_round);
	    if (mon_vowel == true){
	       cout << "Guess a vowel: ";
	       cin >> guess_vowel;
	       count = update_puzzle(guess_vowel, comparing_phrase, guessing_phrase);
	       cout << "number in puzzle: " << count << endl;
	          if (count==0){
	             player = false;
	          }
	          else{
	             player=true;
	          }
	    }
	 }
// solving the puzzle
         else if(choice == 3){
	   cout << "Enter guess for solving puzzle: ";
	   getline(cin, guess_all);
	      if (guess_all== original_phrase){
	      cout << "correct!" << endl;
	         update_gametotals(round)

	      }

         }
     }while(player == true);
// changes player once they guess wrong
      if (player == false){
        current_player++;
	   if (current_player > num_players){
	      current_player=1
	   }
     }
        
          
   }while(current_round < round_total);



   return 0;
}
