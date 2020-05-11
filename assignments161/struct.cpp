#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct spot{
   bool mine;
   bool flag;
   bool visible;
   int value;
};

int main(){
   srand(time(NULL));
   int row=4, col=4, mine=3;
  
   spot **board;
   board= new spot *[row];
   cout << "single splat allocated" << endl;
      for (int i=0; i<row; i++){
         for (int j=0; j<col; j++){
	    board[i] = new spot[col];
	    cout << "spot allocated" << endl;
	    //board[i][j]= new spot;
           // for (int i=0; i<row; i++){
             //  for (int j=0; j<col; j++){
               //   cout << endl;
		 // board[i][j].mine=false;
	// 	  board[i][j].flag=false;
	  //	  board[i][j].value=0;
	 //	  board[i][j].visible=false;
	   //    }
//	    }
	 }
      }
 
 /*  for (int i=0; i<row; i++){
	 
 */     
   for (int i=0; i<row; i++){
      for (int j=0; j<col; j++){
         board[i][j].mine=false;
	 board[i][j].flag=false;
	 board[i][j].visible=false;
	 board[i][j].value=0;
	 //board[i][j].visited=false;  for extra credit
      }
   }   
   for (int m=0; m<mine; m++){
      int my= rand() % (row);
      int mx = rand() % (col);
      if (board[mx][my].mine==true) m--;
      else board[mx][my].mine=true;
   }
   for (int i=0; i<row; i++){
      for (int j=0; j<col; j++){
         if (board[i][j].mine==true)
	    cout << i << "," << j << endl; 
      }
   }   
   return 0;
}

