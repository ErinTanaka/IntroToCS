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
void key_board(spot *a[], int r, int c);
void print_board(spot *a[], int r, int c);
void assign_mines(spot *a[], int mine, int row, int col);
void count_around(spot *a[], int row, int col);
spot** make_board(int r, int c);
bool check_win(spot *a[], int r, int c);
void game_over(spot* a[], int r, int c);
void end_game();


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
   cout << "rows: " << row << endl;
   cout << "cols: " << col << endl;
   cout << "mines: " << mine << endl;

   start_game(row, col, mine); 
   return 0;
}

void error_mssg(){
   cout << "invalid input exiting, please try again"<< endl;
   exit(1);
}

void start_game(int r, int c, int m){
   int choice;
   bool play = true;
   cout << " beginning game" << endl;
   spot **board;
   
   board = make_board(r,c);
  // cout << "board has been made" << endl;
   assign_mines(board, m, r, c);
 //  cout << "now youre ready to start the game note board will print and display all mines and values at current moment" << endl;
   cout << "key"<< endl;
   key_board(board, r,c);
   do{
      print_board(board, r, c);
      cout << "would you like to open(1) or flag(2): ";
      cin >> choice;
         if (choice==1) play=guess_coor(board, r, c);
         else play=flag_coor(board, r, c);
      play=check_win(board, r, c);
	 
   }while (play==true);
   end_game();
}

bool guess_coor(spot *a[], int r, int c){
   int x, y;
   bool check=false ;
   while (check==false){
      cout << "Please enter row number 0-" << r-1 << ": ";
      cin >> x;
      cout << "please enter col nmber 0-" << c-1 << ": ";
      cin >> y;
     if ((x<c && x>=0) && (y<r && y>=0)){ //location is in the board
         if (a[x][y].visible==true){  //location already opened
         cout << "already open please enter new coordinates" << endl;
         }
	 else if (a[x][y].mine==true){ //location contains a mine
	    game_over(a, r, c);
	 }
	 else{ //location not open yet and doesnt contain mine
	    a[x][y].visible=true;
	    //print_board(a, r, c);
	    check=true;
	 }
      }
      else {  //bad coordinates
         cout << "invalid coordinates please enter new coordinates" << endl;
      }
   }
   return true;
}
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
//	    print_board(a, r, c);
	    check=true;
	 }
      }
      else{
         cout << "invalid coordinates" << endl;
      }   
   }
   return true;
   }

spot** make_board(int r, int c){
   spot **board;
   board = new spot *[r];
   for (int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	 board[i]= new spot[c];
      }
   }
   for (int i=0; i<r; i++){
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

void key_board(spot *a[], int r, int c){//temp function to see contents of board
   cout << "printing board \n";
   for (int i=0; i<r; i++){
      for (int h=0; h<c; h++){
      cout << " -";
      }
      cout << "\n";
      for (int j=0; j<c; j++){
         cout << "|"; 
	 if (a[i][j].mine==true){
	    cout << "*";
	 }
//	 else if(a[i][j].flag==true){
//	    cout << "X";
//	 }
	 else cout << a[i][j].value; 
      }
      cout << "|\n";
   }
}


void print_board(spot *a[], int r, int c){
  // for (int n=0; n<c; n++){ // top line of numbers
    //  cout << " " << n;
  // }
  // cout << endl;
//   for (int n=0; n<r; n++){
   for (int i=0; i<r; i++){
      for (int l=0; l<c; l++){
	 cout << " -";
      }
      cout << "\n";

  //       cout << n;
      
         for (int j=0; j<c; j++){
	    cout << "|";
            if (a[i][j].visible==true && a[i][j].mine==true ) cout << "*";
	    else if (a[i][j].flag==true) cout << "F";
	    else if (a[i][j].visible==true) cout << a[i][j].value;
	    else cout << " ";
         }
      
      cout << "|\n";
      }
  //` }
}
void assign_mines(spot *a[], int mine, int row, int col){
 //  cout << "assigning mines" << endl;
   int x, y;
   for (int i=0; i<mine; i++){
      x=rand() % (row);
      y=rand() % (col);
      if (a[x][y].mine==true) i--;
      else a[x][y].mine=true;
   }
  // cout << "printing board with mines\n";
  // print_board(a, row, col);

 //  cout << "printing board with counts" << endl;
   count_around(a, row, col);
 //  print_board(a,row,col);
}
void count_around(spot *a[], int row, int col){
   for (int i=0; i<row; i++){
      for (int j=0; j<col; j++){
         if (a[i][j].mine==true){
	    if((j+1)<=col && a[i][j+1].mine==false) a[i][j+1].value++;
	    if((j-1)>=0 && a[i][j-1].mine==false) a[i][j-1].value++;
	    if((i+1)<row && a[i+1][j].mine==false) a[i+1][j].value++;
	    if((i+1)<row && (j+1)<=col && a[i+1][j+1].mine==false) a[i+1][j+1].value++;
	    if((i+1)<row && (j-1)>=0 && a[i+1][j-1].mine==false) a[i+1][j-1].value++;
	    if(i-1>=0 && a[i-1][j].mine==false) a[i-1][j].value++;
	    if((i-1)>=0 && (j+1)<=col && a[i-1][j+1].mine==false) a[i-1][j+1].value++;
	    if((i-1)>=0 && (j-1)>=0 && a[i-1][j-1].mine==false) a[i-1][j-1].value++;
	 }
//	 cout << "mine at row, col: " << i << "," << j << endl;    
      }
   }
}
//}
void game_over(spot *a[], int r, int c){
   int play;
   int row, col, mine;
   cout << "BOOM!" << endl;
   for (int i=0; i<r; i++){
      for(int j=0; j<c; j++){
         a[i][j].visible=true;
      }
   }
   print_board(a, r, c);
   cout << "Gameover! Would you like to play again yes(1)/ no(2): ";
   cin >> play;
   if (play==1){
      cout << "how many rows: ";
      cin >> row;
      cout << "how many col: ";
      cin >> col;
      cout << "how many mines: ";
      cin >> mine;
      start_game(row, col, mine);
   }
   else if(play==2){
      exit(1);
   }
}
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
	    if (mines>0 && mines < rows*cols) check==true;
	    else if (mines>= rows*cols) cout << "Too many mines for board ";
	    else cout << "MInes must be greater than 0 ";
      }
      start_game(rows, cols, mines);     

   }

}

bool check_win(spot *a[], int r, int c){
   for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
         if(a[i][j].visible==false && a[i][j].mine==false) return true;     
      }
   }
   cout << "You Win!" << endl;
   return false;
}
