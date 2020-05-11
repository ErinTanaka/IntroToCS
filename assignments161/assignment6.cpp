#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

void error_mssg();
int** make_board(int r, int c);
void play_game(int r, int c, int m);
void print_board(int *a[], int r, int c);
void assign_mines(int *a[], int mine, int row, int col);
void count_around(int *a[], int row, int col);


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

   play_game(row, col, mine); 
   return 0;
}

void error_mssg(){
   cout << "invalid input, please try again"<< endl;
   exit(1);
}

void play_game(int r, int c, int m){
   //cout << " beginning game" << endl;
   int **playboard;
   int **compboard;
   int f_g, x,y
   playboard = make_board(r,c);
   //cout << "board one has been made" << endl;
   compboard = make_board(r,c);
   //cout << "board 2 has been made \n";
   
  // cout << playboard[1][1] << endl;
 //  print_board(playboard, r, c); //delete later
   
   assign_mines(compboard, m, r, c);
   //cout << "now youre ready to start the game" << endl;
   print_board(playboard, r,c);
   
   cout << "Flag(1) or Open(2): ";
   cin >> f_g;
      if(f_g==1){
         flag(compboard, playboard, r, c);
      }
      if(f_g==2){
         open(compboard, playboard, r, c);
      }
      

}

int** make_board(int r, int c){
   int **board;
   board = new int *[r];
   for (int i=0; i<r; i++){
      board[i]=new int[c];
   }
   return board;
}

void print_board(int *a[], int r, int c){//temp function
   cout << "printing board \n";
   for (int i=0; i<r; i++){
      for (int h=0; h<c; h++){
      cout << " -";
      }
      cout << "\n";
      for (int j=0; j<c; j++){
         cout << "|" << a[i][j]; 
      }
      cout << "|\n";
   }
}


void assign_mines(int *a[], int mine, int row, int col){
 //  cout << "assigning mines" << endl;
   int x, y;
   for (int i=0; i<mine; i++){
      x=rand() % (row);
      y=rand() % (col);
      if (a[x][y]==0){
         a[x][y]=-1;
      }
      else i--;
   }
   cout << "printing board with mines\n";
   print_board(a, row, col);

   cout << "printing board with counts" << endl;
   count_around(a, row, col);
   print_board(a,row,col);
}
void count_around(int *a[], int row, int col){
   for (int i=0; i<row; i++){
      for (int j=0; j<col; j++){
         if (a[i][j]==-1){
	    if(a[i][j+1]>=0 && (j+1)<=col) a[i][j+1]++;
	    if(a[i][j-1]>=0 && (j-1)>=0) a[i][j-1]++;
	    if((i+1)<row && a[i+1][j]>=0) a[i+1][j]++;
	    if((i+1)<row && (j+1)<=col && a[i+1][j+1]>=0) a[i+1][j+1]++;
	    if((i+1)<row && (j-1)>=0 && a[i+1][j-1]>=0) a[i+1][j-1]++;
	    if(i-1>=0 && a[i-1][j]>=0) a[i-1][j]++;
	    if((i-1)>=0 && (j+1)<=col && a[i-1][j+1]>=0) a[i-1][j+1]++;
	    if((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]>=0) a[i-1][j-1]++;
	 }
//	 cout << "mine at row, col: " << i << "," << j << endl;    
      }
   }
}

