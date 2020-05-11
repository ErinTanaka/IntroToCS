/******************************************************
 *Program: assign6.cpp
 *Author: Erin Tanaka
 *Date: 3/13/2016
 *Description: game minesweeper 
 *Input: command line arguments for number of rows columns and mines
 *Output: gameplay
 *****************************************************/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;


struct spot{
   bool mine;
   bool flag;
   bool visible;
   int value;
   bool visited;   
};
void error_mssg();
void start_game(int r, int c, int m);
bool guess_coor(spot *a[], int r, int c);
bool flag_coor(spot *a[], int r, int c);
void print_board(spot *a[], int r, int c);
void assign_mines(spot *a[], int mine, int row, int col);
void count_around(spot *a[], int row, int col);
spot** make_board(int r, int c);
bool check_win(spot *a[], int r, int c);
void game_over(spot* a[], int r, int c);
void end_game();
void rec_call(spot *a[], int r, int c, int x, int y);

int main(int argc, char *argv[]){
   srand (time(NULL));
   int row = -1, col = -1, mine = -1;
   for (int i = 1; i < argc; i += 2){  //iterate through command line arguments
      if(strcmp(argv[i], "-c") == 0 && col == -1){  //if there is a -c and col hasnt recieved a valid value
	 if(atoi(argv[i+1]) > 0) {  //if rows is a positive int
	    col = atoi(argv[i+1]);  //assign value to col variable
	 }
	 else error_mssg();  //row isn't a pos int
      }
      else if(strcmp(argv[i], "-r") == 0 && row == -1){  //if arg is -r and row hasnt recieved a value
	 if(atoi(argv[i+1]) > 0) {  //if row is a pos int
	    row = atoi(argv[i+1]);  //assign value to row variable
	 }
	 else error_mssg();
      }
      else if(strcmp(argv[i], "-m") == 0 && mine == -1){
	 if(atoi(argv[i+1]) > 0) {
	    mine = atoi(argv[i+1]);
	 }
	 else error_mssg();
      }
      else error_mssg();

   }
   start_game(row, col, mine); 
   return 0;
}
/**************************************************
 * Function: error_mssg
 * Description: displays error message and exits
 * Parameters: none
 * Pre-Conditions: user entered bad arg
 * Post-Conditions: program exited
 *************************************************/
void error_mssg(){
   cout << "invalid input exiting, please try again"<< endl;
   exit(1);
}

/**************************************************
 * Function: start_game
 * Description: begins game by making board and prpmoting player
 * Parameters: values of row, col, and mines
 * Pre-Conditions: user entered valid numbers
 * Post-Conditions: board is made and user begins gameplay
 *************************************************/
void start_game(int r, int c, int m){
   int choice;
   bool play = true;
   spot **board;  
   board = make_board(r,c);  //function to make board
   assign_mines(board, m, r, c);  // assigns mines randomly
   do{
      print_board(board, r, c);
      cout << "Would you like to open(1) or flag(2): ";
      cin >> choice;
         if (choice==1) play=guess_coor(board, r, c);
         else play=flag_coor(board, r, c);
      play=check_win(board, r, c);  //check if all non mine spots are opened
	 
   }while (play==true);
   end_game();
}

/**************************************************
 * Function: guess_coor
 * Description: prompts for user to enter coordinates, error checks for ints displays opened spot or game over if a mine is revealed
 * Parameters: board, number of rows and cols
 * Pre-Conditions: user chose to open space
 * Post-Conditions: opened space is revealed and if it contained a mine gameover
 *************************************************/
bool guess_coor(spot *a[], int r, int c){
   int x, y;
   bool check=false ;
   while (check==false){
      cout << "Please enter row number 0-" << r-1 << ": ";
      cin >> x;
      cout << "Please enter col nmber 0-" << c-1 << ": ";
      cin >> y;
     if ((x<c && x>=0) && (y<r && y>=0)){ //location is in the board
         if (a[x][y].visible==true){  //location already opened
         cout << "Already open please enter new coordinates" << endl;
         }
	 else if (a[x][y].mine==true){ //location contains a mine
	    game_over(a, r, c);
	 }
	 else{ //location not open yet and doesnt contain mine
	    a[x][y].visible=true;
	    if (a[x][y].value==0) rec_call(a, r, c, x, y);
	    check=true;
	 }
      }
      else {  //bad coordinates
         cout << "invalid coordinates please enter new coordinates" << endl;
      }
   }
   return true;
}
/**************************************************
 * Function: flag_coor
 * Description: prompts user to enter coordinates error checks ints and displays f in location flagged
 * Parameters: board, number of rows and cols
 * Pre-Conditions: user chose to flag a spot
 * Post-Conditions: flagged location is visible in printed board
 *************************************************/
bool flag_coor(spot *a[], int r, int c){
   int x, y;
   bool check=false;
   while(check==false){
      cout << "Please enter row number 0-" << r-1 << ": ";
      cin >> x;
      cout << "Please enter col nmber 0-" << c-1 << ": ";
      cin >> y;
      if ((x<c && x>=0) && (y<r && y>=0)){ //location is in the board
         if (a[x][y].flag==true){  //location already flagged
         cout << "already flagged please enter new coordinates" << endl;
	 }   
	 else{ //location not flagged yet
	    a[x][y].flag=true;
	    check=true;
	 }
      }
      else{  //bad cordinates
         cout << "invalid coordinates" << endl;
      }   
   }
   return true;
   }

/**************************************************
 * Function: make_board
 * Description: dynamically allocated 2d array
 * Parameters: number of rows and cols
 * Pre-Conditions: user entered valid numbers for rows and cols
 * Post-Conditions: **spot is returned
 *************************************************/
spot** make_board(int r, int c){
   spot **board;  //dynamically allocating memory for board
   board = new spot *[r]; 
   for (int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	 board[i]= new spot[c];
      }
   }
   for (int i=0; i<r; i++){  //setting al members to defaults
      for (int j=0; j<c; j++){
         board[i][j].mine=false;
         board[i][j].flag=false;
         board[i][j].visible=false;
         board[i][j].value=0;
         board[i][j].visited=false;
      }
   }
   return board;
}

/**************************************************
 * Function: print_board
 * Description: prints out board to screen
 * Parameters: board, number of rows and cols
 * Pre-Conditions: board has been made
 * Post-Conditions: board is printed to screen
 *************************************************/
void print_board(spot *a[], int r, int c){
   for (int i=0; i<r; i++){
      for (int l=0; l<c; l++){
	 cout << " -";
      }
      cout << "\n";
      for (int j=0; j<c; j++){
	 cout << "|";
         if (a[i][j].visible==true && a[i][j].mine==true ) cout << "*";  //for game over to see where board contains mines
	 else if (a[i][j].flag==true) cout << "F";  //displaye "f" where mines are located
         else if (a[i][j].visible==true) cout << a[i][j].value;  //
	 else cout << " ";
      }
      cout << "|\n";
      }
      for (int l=0; l<c; l++){
	 cout << " -";
      }
      cout << endl;
}
/**************************************************
 * Function: assign_mines
 * Description: randomly assigns mines to locations of board
 * Parameters: boars, number of mines, rows and cols 
 * Pre-Conditions: user enterd valid number of mines, board has been made
 * Post-Conditions: mines are assigned to random locations
 *************************************************/
void assign_mines(spot *a[], int mine, int row, int col){
   int x, y;
   for (int i=0; i<mine; i++){  //keep track of how many mines are places
      x=rand() % (row);  //random row
      y=rand() % (col);  //random col
      if (a[x][y].mine==true) i--;  //location already as a mine
      else a[x][y].mine=true;  //places mine
   }
   count_around(a, row, col);  //function to give values to non mine locations
}
/**************************************************
 * Function: count_around
 * Description: finds locations with mines and increments counts of surrounding non mine spots
 * Parameters: board, number of rows and cols
 * Pre-Conditions: mines have been assigned
 * Post-Conditions: numbers corresponding to the number of mines they are touching are saved in struct
 *************************************************/
void count_around(spot *a[], int row, int col){
   for (int i=0; i<row; i++){
      for (int j=0; j<col; j++){
         if (a[i][j].mine==true){
	    if((j+1)<=col && a[i][j+1].mine==false) a[i][j+1].value++;  //sopt directly to right of mine
	    if((j-1)>=0 && a[i][j-1].mine==false) a[i][j-1].value++;  //spot directly to left of mine
	    if((i+1)<row && a[i+1][j].mine==false) a[i+1][j].value++;  //spot directly below mine
	    if((i+1)<row && (j+1)<=col && a[i+1][j+1].mine==false) a[i+1][j+1].value++;  //spot down and right of mine
	    if((i+1)<row && (j-1)>=0 && a[i+1][j-1].mine==false) a[i+1][j-1].value++;  //spot down and left of mine
	    if(i-1>=0 && a[i-1][j].mine==false) a[i-1][j].value++;  //spot directly above mine
	    if((i-1)>=0 && (j+1)<=col && a[i-1][j+1].mine==false) a[i-1][j+1].value++;  //spot up and right of mine
	    if((i-1)>=0 && (j-1)>=0 && a[i-1][j-1].mine==false) a[i-1][j-1].value++;  //spot up and left of mine
	 }    
      }
   }
}

/**************************************************
 * Function: game_over
 * Description: ends game displays all contents of board and prompts user if they want to play again
 * Parameters: board, number of rows and cols
 * Pre-Conditions: mine was opened
 * Post-Conditions: message is displayed, board is printed  and user is prompted to play again
 *************************************************/
void game_over(spot *a[], int r, int c){
   int play;
   int row, col, mine;
   cout << "BOOM!" << endl;
   for (int i=0; i<r; i++){
      for(int j=0; j<c; j++){
         a[i][j].visible=true;  //sett all locations to visibe
      }
   }
   print_board(a, r, c);  //print board and all contents
   cout << "Gameover!" << endl;
   end_game();  //prompting for new game and game info
}
/**************************************************
 * Function: end_game
 * Description: askd user to play again if yes prompts for mines rows and cols for new game; if not exits program
 * Parameters: none
 * Pre-Conditions: user has opened all non mine spots or has opened a bomb
 * Post-Conditions: game is either exited or a new one begins
 *************************************************/
void end_game(){
   int choice, mines, rows, cols;
   bool check=false;
   cout << "Would you like to play again yes(1) no(2): ";
   cin >> choice;
   if (choice==2){
      exit(1);
   }
   else if (choice==1){
      cout << "please enter info for next game" << endl;
      while(check==false){
         cout << "Rows: ";
         cin >> rows;
            if (rows>0) check=true;
	    else cout << "Rows must be greater than 0 ";
      }
      check=false;
      while (check== false){
         cout << "Columns: ";
         cin >> cols;
            if (cols>0) check=true;
	    else cout << "Columns must be greater than 0 ";
      }
      check=false;
      while (check==false){
         cout << "Mines: ";
	 
	 cin >> mines;
	    if (mines>0 && mines<rows*cols) check=true;
	    else if (mines>= rows*cols) cout << "Too many mines for board ";
	    else cout << "Mines must be greater than 0 ";
      }
      start_game(rows, cols, mines);     
   }
}

/**************************************************
 * Function: check_win
 * Description: checks if user has opened all of the non mine locations returns bool
 * Parameters: board number of rows and cols
 * Pre-Conditions: user has opened spots
 * Post-Conditions: bool is returned depending on if user has finished game
 *************************************************/
bool check_win(spot *a[], int r, int c){
   for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
         if(a[i][j].visible==false && a[i][j].mine==false) return true;  //checks if location hasnt been opened yet    
      }
   }
   cout << "You Win!" << endl;
   return false;
}
/**************************************************
 * Function: rec_call
 * Description: recursively displays all adjacent zeros to zero revealed
 * Parameters: board, number of rows and cols, coordinates of current location
 * Pre-Conditions: user opened a location containing a zero
 * Post-Conditions: all adjacent locations containing zeros set to visible
 *************************************************/
void rec_call(spot *a[], int r, int c, int x, int y){
   a[x][y].visited=true;
   a[x][y].visible=true;
   if((y+1)<=c && a[x][y+1].value==0 && a[x][y].visited==false)  rec_call(a, r, c, x, y+1);  //directly right of current spot
   if((y-1)>=0 && a[x][y-1].value==0 && a[x][y-1].visited==false) rec_call(a, r, c, x, y-1);  //directly left of spot
   if((x+1)<r && a[x+1][y].value==0 && a[x+1][y].visited==false)  rec_call(a, r, c, x+1, y);  //directly below spot
   if((x+1)<r && (y+1)<=c && a[x+1][y+1].value==0 && a[x+1][y+1].visited==false) rec_call(a, r, c, x+1, y+1);  //down and to the right
   if((x+1)<r && (y-1)>=0 && a[x+1][y-1].value==0 && a[x+1][y-1].visited==false) rec_call(a, r, c, x+1, y-1);  //down and to the left
   if(x-1>=0 && a[x-1][y].value==0 && a[x-1][y].visited==false) rec_call(a, r, c, x-1, y);  //directly above spot
   if((x-1)>=0 && (y+1)<=c && a[x-1][y+1].value==0 && a[x-1][y+1].visited==false) rec_call(a, r, c, x-1, y+1);  //up and to the right
   if((x-1)>=0 && (y-1)>=0 && a[x-1][y-1].value==0 && a[x-1][y-1].visited==false) rec_call(a, r, c, x-1, y-1);  //up and to the left
}
	   
