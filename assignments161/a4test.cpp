/***************************************************************************
 *Program Filename:
 *Author: Erin Tanaka
 *Date: February 15, 2016
 *Description: Wheel of Fortune game for 1-3 players
 *Input: Number of players; how many rounds; puzzle to be guessed; choice to spin, buy vowel, or solve; letter guesses; guess of puzzle
 *Output: game info as puzzle is solved, round totals and gametotals, winner over all
 **************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <istream>

using namespace std;

// functions
void get_puzzle(string &original_phrase, string &comparing_phrase, string &guessing_phrase, int current_round); 
string convert_string(string str);
string make_space(string str);
void players_rounds(int &num_players, int &round_total);
bool choice_spinwheel(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase);
int spin_wheel();
void bankrupt(int current_player, int &p1_round, int &p2_round, int &p3_round);
bool guess_consonant(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase, int count, int spin_result);
bool choice_buyvowel(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase);      
int update_puzzle(string guess, string comparing_phrase, string &guessing_phrase);
bool check_money(int current_player, int p1_round, int p2_round, int p3_round);
bool check_puzzle(string comparing_phrase, string guessing_phrase);
bool choice_solve( string original_phrase, string comparing_phrase, string &guessing_phrase);      
int update_round(int spin, int count, int &p1_round, int &p2_round, int &p3_round, int current);
void end_round(int num_players,int current_player, int current_round, int &p1_round, int &p2_round, int &p3_round, int &p1_total, int &p2_total, int &p3_total);
void end_game (int p1_total, int p2_total, int p3_total);
void disp_rndtotals (int &p1_round, int &p2_round, int &p3_round, int p1_total, int p2_total, int p3_total);
void disp_turninfo (int current_round, int current_player, string guessing_phrase);
string to_upper (string str);
string check_guess1(string guess);

int main(){
   string original_phrase, comparing_phrase, guessing_phrase;
   int num_players=0, round_total=0, current_player=1, current_round=1, p1_round=0, p2_round=0, p3_round=0, p1_total=0, p2_total=0, p3_total=0,choice; 
   bool round=false, player=true, check=false;

   players_rounds(num_players, round_total);
   get_puzzle(original_phrase, comparing_phrase, guessing_phrase, current_round);
   cout << endl;
   do{ //Continues game until total number of rounds has been completed
      current_player=1;
      do{ //Runs current round until puzzle gets solved
	 do{ //Lets current player guess until they guess incorrect or sucessfully solve the puzzle
            disp_turninfo(current_round, current_player, guessing_phrase); //Displays rond player and options
	    cin >> choice; //1 spin, 2 vowel, 3 solve
                  if (choice==1) {
	             player = choice_spinwheel(current_player, p1_round, p2_round, p3_round, comparing_phrase, guessing_phrase);
		     check=check_puzzle(comparing_phrase, guessing_phrase); //Was the puzzle solved?
		        if (check==true) break;
	          }
	          else if (choice==2){ 
	             player = choice_buyvowel(current_player, p1_round, p2_round, p3_round, comparing_phrase, guessing_phrase);
		     check=check_puzzle(comparing_phrase, guessing_phrase); //Was the puzzle solved?
		        if (check==true) break;
	          }
	          else if (choice==3){ 
	             player = choice_solve( original_phrase, comparing_phrase, guessing_phrase);
	             if (player==true) break; //Cuts to end of round if guessed correct
	          }  
	       cout << endl;

	 }while(player==true);

            current_player++; //Changes player
               if (current_player > num_players) current_player=1; //Back to player1 if all players have guessed
            round = check_puzzle(comparing_phrase, guessing_phrase); //Was the puzzle solved? 
	 
      }while (round==false);

      end_round(num_players,current_player, current_round, p1_round, p2_round, p3_round,  p1_total, p2_total, p3_total); //Declare winner and update totals
      current_round++;
         if (current_round > round_total)break; //Cuts to end of game
      get_puzzle(original_phrase, comparing_phrase, guessing_phrase, current_round); //Get new guessing phrase
   
   }while (current_round <= round_total);
   end_game(p1_total, p2_total, p3_total); //Declare overall winner
   
   return 0;
}



/**********************************************************************
 * Funtion: get_puzzle
 * Description: gets puzzle from user; adds spaces inbetween each 
                element and changes each non letter to underscores
 * Parameters: address of original phrase, comparing phrase and guessing 
               phrase; and number of current round
 * Pre-Conditions: current round is 1+
 * Post-Conditions: original phrase gets string; comparing phrase= 
                    original with spaces; guessing phrase= underscores 
		    corresponding to comparing
**********************************************************************/ 
void get_puzzle(string &original_phrase, string &comparing_phrase, string &guessing_phrase, int current_round){ 
   cout << "Please enter a word or phrase to be guessed:";
   if (current_round==1){
      cin.ignore(); //Ignores null character
      getline(cin, original_phrase);
      original_phrase=to_upper(original_phrase); //Convert to upper case
   }
   else{
      getline(cin, original_phrase);
      original_phrase=to_upper(original_phrase); //Convert to upper case
   }
   comparing_phrase = make_space(original_phrase); //Adds 1 space between each element of string 
   guessing_phrase = convert_string(comparing_phrase); //Converts all nonspace to underscore
   system("clear"); //Hides puzzle
}   

/**********************************************************************
 * Funtion: make_space
 * Description: adds one space in between each element of original phrase
 * Parameters: string original phrase
 * Pre-Conditions: str contains a string
 * Post-Conditions: string str will have spaces inbetween each element
                    ex input hello str post function h e l l o
**********************************************************************/ 

string make_space(string str){

   string insert=" ";
   int x = str.length();
   for(x; x > 0; x--){
      str.insert(x,insert);
   }
   return str;
}
/**********************************************************************
 * Funtion: convert_string
 * Description: changes all non whitespace characers to underscores
 * Parameters: string comparing string
 * Pre-Conditions: comparing string contains a string
 * Post-Conditions: all non whitespace characters in initial string are 
                    underscores
**********************************************************************/ 
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

/**********************************************************************
 * Funtion: players_rounds
 * Description: gets number of players and number of rounds they want 
                to play
 * Parameters: addresses on number of players and total number of rounds
 * Pre-Conditions: none
 * Post-Conditions: number of players stored in address; and number of 
                    rounds stored in address
**********************************************************************/ 
void players_rounds(int &num_players, int &round_total){
   cout << "Number of players: ";
   cin >> num_players;
   cout << "Number of rounds/puzzles: ";
   cin >> round_total;

}

/**********************************************************************
 * Funtion: choice_spinwheel
 * Description: spins wheel; takes in guess if applicable; checks if 
                guess is in puzzle; displays nmber of times; updates 
		puzzle; updates round total
 * Parameters: current player; addresses of round totals; comparing 
               phrase; and address of guessing phrase
 * Pre-Conditions: player chose to spin wheel comparing phrase and 
                   guessing phrase contain strings
 * Post-Conditions: number spun is printed; if bankrupt runs bankrupt 
                    function; if end turn returns false; valid guess 
                    is displayed in puzzle; round total is displayed
**********************************************************************/ 
bool choice_spinwheel(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase){
   bool consonant;
   int spin_result, temptotal, count;
   spin_result = spin_wheel();
   cout << "Your spin: " <<  spin_result << endl;
      if (spin_result == 0){
	 bankrupt(current_player, p1_round, p2_round, p3_round); 
	 return  false;   
      }
      else if(spin_result==21){
	 cout << "End of turn" << endl;
	 return  false;
      }
      else{   
   	  consonant=guess_consonant(current_player, p1_round, p2_round, p3_round, comparing_phrase, guessing_phrase, count, spin_result);
	  return consonant;
      }
}

/**********************************************************************
 * Funtion: spin_wheel
 * Description: generates random number between 0 and 21
 * Parameters: none
 * Pre-Conditions: player made choice to spin wheel
 * Post-Conditions: returns random number within given range
**********************************************************************/ 
int spin_wheel(){
   int spin = rand() % 22;
   return spin;
}

/**********************************************************************
 * Funtion: update_puzzle
 * Description: counts number of occurences of letter guessed; and 
                changes underscores in guessing phrase to letter guessed
 * Parameters: letter guessed by user, comparing phrase, address of 
               guessing phrase
 * Pre-Conditions: user has guessed a character 
 * Post-Conditions: count= number of times guess appered in comparing phrase;
                    guessing phrase has been updated to contain guessed letter
**********************************************************************/ 
int update_puzzle(string guess, string comparing_phrase, string &guessing_phrase){
   int count = 0;
    for(int i = 0; i < comparing_phrase.length(); i++){
      if (comparing_phrase[i] == guess[0]){
	 count++;
    	 guessing_phrase[i] = guess[0];
      }   
   }
   return count;
}

/**********************************************************************
 * Funtion: update_round
 * Description: adds money to round total depnding on current player
 * Parameters: number spun on wheel; number of times guess occured in 
               puzzle; addresses of round totals; and current player
 * Pre-Conditions: round totalsare positive ints, spin and count are ints
 * Post-Conditions:depending on current player their round total will be udated
**********************************************************************/ 
int update_round(int spin, int count, int &p1_round, int &p2_round, int &p3_round, int current_player){
   int x = spin*count;
   if (current_player == 1){
      p1_round = p1_round+x;
      return p1_round;
   }
   else if (current_player == 2){
      p2_round = p2_round+x;
      return p2_round;
   }
   else{
      p3_round = p3_round+x;
      return p3_round;
   }
}

/**********************************************************************
 * Funtion: bankrupt
 * Description: of player spins 0 then they lose all of their money in 
                current round
 * Parameters: current player; and addresses of round totals
 * Pre-Conditions: player spun 0 
 * Post-Conditions:current players's round total=0 and their turn will be over 
**********************************************************************/ 
 void bankrupt(int current_player, int &p1_round, int &p2_round, int &p3_round){
   cout << "Bankrupt" << endl;
   cout << "Round total: $0" << endl;
   if (current_player == 1){
      p1_round = 0;
   }
   else if(current_player == 2){
      p2_round = 0;
   }
   else{
      p3_round = 0;
   }
   
}
/*********************************************************************
 * Function: guess_consonant 
 * Description: has player guess consonant; checks if guess in puzzle; 
                updates puzzle and inc round total if yes; if no ends turn
 * Parameters: current player; addresses of round totals; comparing 
               phrase; address of guessing phrase; count; spin result
 * Pre-Conditions: player spun 1-20
 * Post-Conditions:puzzle and total are updated; round total and updated 
                   puzzle printed to screen; number of times guess 
		   occurs in puzzle printed
 ********************************************************************/
bool guess_consonant(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase, int count, int spin_result){
   string guess;
   int temptotal;
         cout << "Guess a consonant: ";
	 cin >> guess;
	 guess = check_guess1(guess);
	 count = update_puzzle(guess, comparing_phrase, guessing_phrase);
         cout << "Number in puzzle: " << count << " ";
	    if (count == 0){	       
	       cout << endl;
	       return false;	  
  	    }
            else{
	       temptotal = update_round(spin_result, count, p1_round, p2_round, p3_round, current_player);
	       cout << " Round total: $" << temptotal << endl;
	       cout << "The puzzle is: " << guessing_phrase << endl;   
	       return true;	  
	    }    	  
}
/**********************************************************************
 * Funtion: choice_buyvowel
 * Description: checks if user can buy vowel; if yes decrements total, 
                asks for guess, checks occurances and updates puzzle; 
		if no sends back to choice
 * Parameters: current player; addresses of round totals; comparign phrase; 
               and address of guessing phrase
 * Pre-Conditions: player has chosen to buy a vowel
 * Post-Conditions:if player cant afford vowel, print they dont have 
                   enough money and return to choice; if can afford vowel 
		   decrement round total, cin guess, check if in puzzle, 
		   y= update puzzle n=end turn
**********************************************************************/ 

bool choice_buyvowel(int current_player, int &p1_round, int &p2_round, int &p3_round, string comparing_phrase, string &guessing_phrase){      
   string guess_vowel;
   int count, total, pay_vowel;
   bool can_pay = check_money(current_player, p1_round, p2_round, p3_round);
   if (can_pay == true){
      cout << "Guess a vowel: ";
 
      cin >> guess_vowel;
 
      guess_vowel= check_guess1(guess_vowel);

      count = update_puzzle(guess_vowel, comparing_phrase, guessing_phrase);
 
      cout << "Number in puzzle: " << count << endl;
 
      total=update_round(1,-10, p1_round, p2_round,p3_round, current_player); //Will decrement player's round total by 10
 
      if (count == 0){
	 cout << "Round total: $" << total << endl; 
	 return false;	          
      }	          
      else{
         cout << "Round total: $" << total << endl; 
	 cout << "The puzzle is: " << guessing_phrase << endl;
	 return true;	          
      }	    
   }
   else{
      cout << "You do not have enough money" << endl;
      return true;
   }   
}

/**********************************************************************
 * Funtion: check_money
 * Description: checks if current user has at least $10 in their round total
 * Parameters: current player; round totals
 * Pre-Conditions:player chose to buy a vowel
 * Post-Conditions: returns true if player has atleast 10 in rount total;
                    returns false if not
**********************************************************************/ 
bool check_money(int current_player, int p1_round, int p2_round, int p3_round){
   if (current_player == 1){
      //cout << "you have: " << p1_round << endl;
      if (p1_round >= 10) return true;
      else return false;
   }   
   else if (current_player == 2){
      //cout << "you have: " << p2_round << endl;
      if (p2_round >= 10) return true;
      else return false;
   }   
   else{
      //cout << "you have: " << p3_round << endl;
      if (p3_round >= 10) return true;
      else return false;
   }   
}

/**********************************************************************
 * Funtion: choice_solve
 * Description: player guesses solution to puzzle if right reurns to end 
                round; if wrong ends turn
 * Parameters: original phrase; comparing phrase; address of guessing phrase
 * Pre-Conditions:player chose to solve puzzle
 * Post-Conditions:if player is correct displays corret and returns to 
                   end round; if incorrect returns to end turn
**********************************************************************/ 
bool choice_solve(/*int current_player, int &p1_round, int &p2_round, int &p3_round,*/ string original_phrase, string comparing_phrase, string &guessing_phrase){
   string guess_all;
   cout << "Enter guess for solving puzzle: ";
   cin.ignore();
   getline(cin, guess_all);
   guess_all= to_upper(guess_all);
   if (guess_all==original_phrase){
      cout<< "correct!" << endl;
      guessing_phrase=comparing_phrase;
      return true;
   }	   
   else{
   return false;
   }
}

/**********************************************************************
 * Funtion: check_puzzle
 * Description: checks to see if comparing phrase matches guessing phrase
 * Parameters: guessing phrase and comparing phrase
 * Pre-Conditions:none
 * Post-Conditions:returns true if match; false if not
**********************************************************************/ 
bool check_puzzle(string comparing_phrase, string guessing_phrase){
   if (comparing_phrase == guessing_phrase){
      return true;
   }
   else{
      return false;
   }
}

/**********************************************************************
 * Funtion: end_roundaddresses of game totals and round totals
 * Description: updates game totals; displays round totals
 * Parameters: addresses of game totals and round totals
 * Pre-Conditions: none
 * Post-Conditions:game totals are updated and round totals are printed to screen
**********************************************************************/ 
void end_round(int num_players, int current_player, int current_round, int &p1_round, int &p2_round, int &p3_round, int &p1_total, int &p2_total, int &p3_total){ 
   if (current_player==1){
      current_player=num_players; 
   }
   else if(current_player==2){
      current_player=1; 
   }
   else if(current_player==3){
      current_player=2;
   }
  
   cout << "Player " << current_player << " wins round " << current_round << endl;
  
   if (current_player==1){
      p1_total = p1_total + p1_round;
   }
   if (current_player==2){
      p2_total = p2_total + p2_round;
   }
   if (current_player==3){
      p3_total = p3_total + p3_round;
   }
   disp_rndtotals(p1_round, p2_round, p3_round, p1_total, p2_total, p3_total);
}

/**********************************************************************
 * Funtion: end_game
 * Description: ends game; displays game totals and determines winner
 * Parameters: game totals
 * Pre-Conditions: current round> total rounds
 * Post-Conditions: print game over; final earnings for all players; 
                    who winner is
**********************************************************************/ 
void end_game (int p1_total, int p2_total, int p3_total){
 
   cout << endl;

   cout << "Game over" << endl;

   cout << endl;

   cout <<"Final earnings:" << endl;
   cout << "Player 1: $" << p1_total << endl;
   cout << "Player 2: $" << p2_total << endl;
   cout << "Player 3: $" << p3_total << endl;

   cout << endl;
//Determining the winner   
   if (p1_total > p2_total && p1_total > p3_total) cout << "Player 1 Wins!" << endl;
   if (p2_total > p1_total && p2_total > p3_total) cout << "Player 2 Wins!" << endl;
   if (p3_total > p1_total && p3_total > p2_total) cout << "Player 3 Wins!" << endl;
}

/**********************************************************************
 * Funtion: disp_rndtotals
 * Description: displays round and game totals; resets round totals to 0
 * Parameters: addresses of round totals; game totals
 * Pre-Conditions:
 * Post-Conditions:round and game totals are printed to screen; all 
                   round totals are set to 0
**********************************************************************/ 
void disp_rndtotals (int &p1_round, int &p2_round, int &p3_round, int p1_total, int p2_total, int p3_total){
   
   
   cout << endl;
   
   cout << "Game Totals:" << endl;
   cout << "Player 1: $" << p1_total << endl;
   cout << "Player 2: $" << p2_total << endl;
   cout << "Player 3: $" << p3_total << endl;
  
   cout << endl;

   // reseting round totals   
   p1_round=0;
   p2_round=0;
   p3_round=0;
}

/**********************************************************************
 * Funtion: disp_turninfo
 * Description:displays genersl information at beginning of each turn
 * Parameters: current round; current player; guessing phrase
 * Pre-Conditions:
 * Post-Conditions:current round; current player; guessing phrase; and 
                   options are printed to screen
**********************************************************************/ 
void disp_turninfo (int current_round, int current_player, string guessing_phrase){
   cout << endl;
   cout << "Round: " << current_round << " Player: " << current_player << endl;
   cout << "The puzzle is: " << guessing_phrase << endl;
   cout << "Spin (1), Buy a vowel(2), Solve(3): ";
}
/**********************************************************************
 * Funtion: to_upper
 * Description:converts input to uppercase
 * Parameters: string to get converted
 * Pre-Conditions:
 * Post-Conditions: if not already uppercase each char is returned as 
                    all upper case 
**********************************************************************/ 
string to_upper(string str ){
   for(int i=0; i<= str.length(); i++){
      if (str[i]>96 && str[i]<123){
          str[i]= str[i]-32;
      }
      else if(str[i]>91 && str[i] <64 ){
          str[i]=str[i];
      }
      else if (str[i]== 32){
          str[i]= 32;
      }
   }
   return str;
}

/**********************************************************************
 * Funtion: check_guess1
 * Description:makes sure guess is a valid input; if not will ask for new untill is good
 * Parameters: string guess
 * Pre-Conditions: player has made guess
 * Post-Conditions: if guess invalid will get new until it is valid if is valid will return
**********************************************************************/
string check_guess1(string guess){
  int goodlen=1;
  do{
     if (guess.length()>1){
        cout << "Please enter a single letter:";
	cin.ignore();
	getline(cin, guess);
     }
       else{ 
	  if(guess[0]>96 && guess[0]<123) goodlen=0;
	  else if(guess[0]>91 && guess[0] <64) goodlen=0;
          else{
             cout << "invalid character try again: ";
       	     cin.ignore();
	     getline (cin, guess);
	  }  
       } 	    
   }while (goodlen==1);
  guess=to_upper(guess);

return guess;  
}
/*********************************************************************
 * Function: check_guess_string
 * Description: checks to make sure all characters in string are leters or spaces
 * Parameters: string guess
 * Pre-Conditions: player has entered string
 * Post-Conditions: if string is invalid will rompt for new until valid
 ********************************************************************/





