/*********************************************************************
 * Program Filename: assignment3.cpp
 * Author: Erin Tanaka
 * Date: January 31, 2016
 * Description:find a path for the rover given user inputs for
 * starting and ending coordinates 
 * Input: Starting and ending (x,y) coordinates
 * Output: Path from starting point to end printed step by step
 ********************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/********************************************************************
 * Function: print_grid
 * Description: prints grid out with x's marking where rover has travelled
 * Parameters: One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1,
 * 	        Three2, Three3, Three4, Four1, Four2, Four3, Four4
 * Return: none
 * Pre-conditions: xCoor and yCoor are valid ints
 * Post conditions: xCoor and yCoor have not been changed and grid w/ path
  		    will have been printed to screen
********************************************************************/

void print_grid(char One1, char One2, char  One3,char One4,char Two1,char Two2,char Two3,char Two4,char Three1,char Three2,char Three3,char Three4,char Four1,char Four2,char Four3,char Four4){
 

//printing grid

	cout << "---------" << endl;
	cout << "|" << One4 << "|" << Two4 << "|" << Three4 << "|" << Four4 << "|" << endl;
	cout << "---------" << endl;
	cout << "|" << One3 << "|" << Two3 << "|" << Three3 << "|" << Four3 << "|" << endl;
	cout << "---------" << endl;
	cout << "|" << One2 << "|" << Two2 << "|" << Three2 << "|" << Four2 << "|" << endl;
	cout << "---------" << endl;
	cout << "|" << One1 << "|" << Two1 << "|" << Three1 << "|" << Four1 << "|" << endl;
	cout << "---------" << endl;
	
}



/********************************************************************
 *Function: find_path
 *Description: Finds path from starting position to ending position
 	       and pronts path to screen
 *Parameters: xStart, yStart, xEnd, yEnd
 *Return: None
 *Pre-condtitions: all parameters are valid intergers
 *Post conditions:No change to parameters and path will be printed
 		  to screen  
********************************************************************/
   
void find_path(int xStart, int yStart, int xEnd, int yEnd){
   
//Chars will correspond to locations on grid
	
   char One4=' ', Two4=' ', Three4=' ', Four4=' ';
   char One3=' ', Two3=' ', Three3=' ', Four3=' '; 
   char One2=' ', Two2=' ', Three2=' ', Four2=' ';
   char One1=' ', Two1=' ', Three1=' ', Four1=' '; 
 
   int xCoor = xStart, yCoor = yStart;
  		
//X coordinates

	if (xStart < xEnd){
	   for (xCoor = xStart; xCoor < xEnd; xCoor++){
	      
	      if(xCoor == 1 && yCoor == 1) One1 = 'X';
	      else if(xCoor == 1 && yCoor == 2) One2 = 'X';
	      else if(xCoor == 1 && yCoor == 3) One3 = 'X';
	      else if(xCoor == 1 && yCoor == 4) One4 = 'X';
	      else if(xCoor == 2 && yCoor == 1) Two1 = 'X';
	      else if(xCoor == 2 && yCoor == 2) Two2 = 'X';
	      else if(xCoor == 2 && yCoor == 3) Two3 = 'X';
	      else if(xCoor == 2 && yCoor == 4) Two4 = 'X';
	      else if(xCoor == 3 && yCoor == 1) Three1 = 'X';
	      else if(xCoor == 3 && yCoor == 2) Three2 = 'X';
	      else if(xCoor == 3 && yCoor == 3) Three3 = 'X';
	      else if(xCoor == 3 && yCoor == 4) Three4 = 'X';
	      else if(xCoor == 4 && yCoor == 1) Four1 = 'X';
	      else if(xCoor == 4 && yCoor == 2) Four2 = 'X';
	      else if(xCoor == 4 && yCoor == 3) Four3 = 'X';
	      else if(xCoor == 4 && yCoor == 4) Four4 = 'X';
	      
	      print_grid(One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1, Three2, Three3, Three4, Four1, Four2, Four3, Four4);
	      cout << "\n";
	   }	
	}

	else if (xStart > xEnd){
	   for (xCoor =xStart; xCoor > xEnd; xCoor--){
	      
	      if(xCoor == 1 && yCoor == 1) One1 = 'X';
	      else if(xCoor == 1 && yCoor == 2) One2 = 'X';
	      else if(xCoor == 1 && yCoor == 3) One3 = 'X';
	      else if(xCoor == 1 && yCoor == 4) One4 = 'X';
	      else if(xCoor == 2 && yCoor == 1) Two1 = 'X';
	      else if(xCoor == 2 && yCoor == 2) Two2 = 'X';
	      else if(xCoor == 2 && yCoor == 3) Two3 = 'X';
	      else if(xCoor == 2 && yCoor == 4) Two4 = 'X';
	      else if(xCoor == 3 && yCoor == 1) Three1 = 'X';
	      else if(xCoor == 3 && yCoor == 2) Three2 = 'X';
	      else if(xCoor == 3 && yCoor == 3) Three3 = 'X';
	      else if(xCoor == 3 && yCoor == 4) Three4 = 'X';
	      else if(xCoor == 4 && yCoor == 1) Four1 = 'X';
	      else if(xCoor == 4 && yCoor == 2) Four2 = 'X';
	      else if(xCoor == 4 && yCoor == 3) Four3 = 'X';
	      else if(xCoor == 4 && yCoor == 4) Four4 = 'X';
	      
	      print_grid(One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1, Three2, Three3, Three4, Four1, Four2, Four3, Four4);
	      cout << "\n";
	   }
	}

	else {
	   if(xCoor == 1 && yCoor == 1) One1 = 'X';
	   else if(xCoor == 1 && yCoor == 2) One2 = 'X';
    	   else if(xCoor == 1 && yCoor == 3) One3 = 'X';
	   else if(xCoor == 1 && yCoor == 4) One4 = 'X';
    	   else if(xCoor == 2 && yCoor == 1) Two1 = 'X';
    	   else if(xCoor == 2 && yCoor == 2) Two2 = 'X';
    	   else if(xCoor == 2 && yCoor == 3) Two3 = 'X';
    	   else if(xCoor == 2 && yCoor == 4) Two4 = 'X';
    	   else if(xCoor == 3 && yCoor == 1) Three1 = 'X';
    	   else if(xCoor == 3 && yCoor == 2) Three2 = 'X';
    	   else if(xCoor == 3 && yCoor == 3) Three3 = 'X';
    	   else if(xCoor == 3 && yCoor == 4) Three4 = 'X';
    	   else if(xCoor == 4 && yCoor == 1) Four1 = 'X';
	   else if(xCoor == 4 && yCoor == 2) Four2 = 'X';
	   else if(xCoor == 4 && yCoor == 3) Four3 = 'X';
	   else if(xCoor == 4 && yCoor == 4) Four4 = 'X';
	   
	   print_grid(One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1, Three2, Three3, Three4, Four1, Four2, Four3, Four4);
	   cout << "\n";
	}

//Y coordinates


	if (yStart < yEnd){
	   for (int yCoor = yStart; yCoor <= yEnd; yCoor++){
	      if(xCoor == 1 && yCoor == 1) One1 = 'X';
	      else if(xCoor == 1 && yCoor == 2) One2 = 'X';
	      else if(xCoor == 1 && yCoor == 3) One3 = 'X';
	      else if(xCoor == 1 && yCoor == 4) One4 = 'X';
    	      else if(xCoor == 2 && yCoor == 1) Two1 = 'X';
    	      else if(xCoor == 2 && yCoor == 2) Two2 = 'X';
    	      else if(xCoor == 2 && yCoor == 3) Two3 = 'X';
    	      else if(xCoor == 2 && yCoor == 4) Two4 = 'X';
    	      else if(xCoor == 3 && yCoor == 1) Three1 = 'X';
    	      else if(xCoor == 3 && yCoor == 2) Three2 = 'X';
    	      else if(xCoor == 3 && yCoor == 3) Three3 = 'X';
    	      else if(xCoor == 3 && yCoor == 4) Three4 = 'X';
    	      else if(xCoor == 4 && yCoor == 1) Four1 = 'X';
	      else if(xCoor == 4 && yCoor == 2) Four2 = 'X';
	      else if(xCoor == 4 && yCoor == 3) Four3 = 'X';
	      else if(xCoor == 4 && yCoor == 4) Four4 = 'X';
	      
	      print_grid(One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1, Three2, Three3, Three4, Four1, Four2, Four3, Four4);
	      cout << "\n";   
	   }
	       	
	}
	
	else if (yStart > yEnd){
	   for (int yCoor = yStart; yCoor >= yEnd; yCoor--){
	      if(xCoor == 1 && yCoor == 1) One1 = 'X';
	      else if(xCoor == 1 && yCoor == 2) One2 = 'X';
	      else if(xCoor == 1 && yCoor == 3) One3 = 'X';
	      else if(xCoor == 1 && yCoor == 4) One4 = 'X';
	      else if(xCoor == 2 && yCoor == 1) Two1 = 'X';
	      else if(xCoor == 2 && yCoor == 2) Two2 = 'X';
	      else if(xCoor == 2 && yCoor == 3) Two3 = 'X';
	      else if(xCoor == 2 && yCoor == 4) Two4 = 'X';
	      else if(xCoor == 3 && yCoor == 1) Three1 = 'X';
	      else if(xCoor == 3 && yCoor == 2) Three2 = 'X';
	      else if(xCoor == 3 && yCoor == 3) Three3 = 'X';
	      else if(xCoor == 3 && yCoor == 4) Three4 = 'X';
	      else if(xCoor == 4 && yCoor == 1) Four1 = 'X';
	      else if(xCoor == 4 && yCoor == 2) Four2 = 'X';
	      else if(xCoor == 4 && yCoor == 3) Four3 = 'X';
	      else if(xCoor == 4 && yCoor == 4) Four4 = 'X';
	      
	      print_grid(One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1, Three2, Three3, Three4, Four1, Four2, Four3, Four4 );   
	      cout << "\n";
	   }
	     
	}
	
	else{
	   if(xCoor == 1 && yCoor == 1) One1 = 'X';
	   else if(xCoor == 1 && yCoor == 2) One2 = 'X';
	   else if(xCoor == 1 && yCoor == 3) One3 = 'X';
	   else if(xCoor == 1 && yCoor == 4) One4 = 'X';
	   else if(xCoor == 2 && yCoor == 1) Two1 = 'X';
	   else if(xCoor == 2 && yCoor == 2) Two2 = 'X';
	   else if(xCoor == 2 && yCoor == 3) Two3 = 'X';
	   else if(xCoor == 2 && yCoor == 4) Two4 = 'X';
	   else if(xCoor == 3 && yCoor == 1) Three1 = 'X';
	   else if(xCoor == 3 && yCoor == 2) Three2 = 'X';
	   else if(xCoor == 3 && yCoor == 3) Three3 = 'X';
	   else if(xCoor == 3 && yCoor == 4) Three4 = 'X';
	   else if(xCoor == 4 && yCoor == 1) Four1 = 'X';
	   else if(xCoor == 4 && yCoor == 2) Four2 = 'X';
	   else if(xCoor == 4 && yCoor == 3) Four3 = 'X';
	   else if(xCoor == 4 && yCoor == 4) Four4 = 'X';
	   
	   print_grid(One1, One2, One3, One4, Two1, Two2, Two3, Two4, Three1, Three2, Three3, Three4, Four1, Four2, Four3, Four4 );
	   
	   cout << "\n";
	}

}

/*********************************************************************
 *Function: check_int
 *Description: check users input, if valid int 1-4: continues program
	       if not, promts user for new input 
 *Parameters: string taken from ser input for xStart, yStart, xEnd and yEnd
 *Return: int for use as coordinate
 *Pre-conditions: user has entered characters other than spaces
 *Post Conditions: valid integers have been set as coordinates
 ********************************************************************/

int check_int(string input){
 
   int coor;

// determine if string 1st character in string is valid input
   
   for(int x=0; x<1; x++){
      do{
	 for (int i=0; i < input.length(); i++){
	    if(!(input.at(i) >= '1' && input.at(i) <= '4')){
	       cout << "Invalid input. Please enter number 1-4: ";
	       cin >> input;
	       i=-1;
	    }
	 }
	 
      
// convert sring to integer      
      
	 coor = atoi(input.c_str());

// determine if input is 1-4 or just started with 1-4 
     
      if (coor>4 || coor==0){
	cout << "Invalid input. Please enter number 1-4: ";
	cin >> input;
	
     } 
     else{
	break;
     }
      } while(1);
     }
   


   return coor;
}


/*********************************************************************
 *Function: zero_or_one
 *Description: check users input, if valid int 0 or 1, continues program
	       if not, promts user for new input 
 *Parameters: string taken from user input to plot again or exit
 *Return: int to continue or terminate loop
 *Pre-conditions: user has entered characters other than spaces
 *Post Conditions: valid int set to x
 ********************************************************************/

int zero_or_one(string cont){
   
   int ans;
   for(int x=0; x<1; x++){
      do{
	 for (int i=0; i < cont.length(); i++){
	    if(!(cont.at(i) == '1' || cont.at(i) == '0')){
	       cout << "Invalid input. Enter 1(yes) or 0(no): ";
	       cin >> cont;
	       i=-1;
	    }
	 }

// convert sring to integer      
      
	 ans = atoi(cont.c_str());

// determine if input is 1/0  or just started with 1/0
     
      if (!(ans==1 || ans==0)){
	cout << "Invalid input. Enter 1(yes) or 0(no): ";
	cin >> cont;
	
     } 
     else{
	break;
     }
      } while(1);
     }
   


   return ans;
}



int main(){

//declaring variables for user inputs

	string xStart, yStart, xEnd, yEnd, cont; 

// beginning loop to repeat program as user desires	
	
	int x = 1;
  	
	do {

	cout << "Please enter coordinates according to grid given below" << endl;

  	cout << "|(1,4)|(2,4)|(3,4)|(4,4)|" << endl;
	cout << "|(1,3)|(2,3)|(3,3)|(4,3)|" << endl;
	cout << "|(1,2)|(2,2)|(3,2)|(4,2)|" << endl;
	cout << "|(1,1)|(2,1)|(3,1)|(4,1)|" << endl;

	cout << "Starting x coordinate: ";
	cin >> xStart;
	int var_x_st = check_int (xStart);

	cout << "Starting y coordinate: ";
	cin >> yStart;	
	int var_y_st =check_int (yStart);
	
	cout << "Ending x coordinate: ";
	cin >> xEnd;
	int var_x_end =check_int (xEnd);

	cout << "Ending y coordinate: ";
	cin >> yEnd;
	int var_y_end = check_int (yEnd);


	cout << "Starting point: (" << var_x_st << "," << var_y_st << ")" << endl;
	cout << "Ending point: (" <<var_x_end << "," << var_y_end << ")" << endl;


	find_path(var_x_st, var_y_st, var_x_end, var_y_end);



	cout << "Would you like to plot another path? yes:1 no:0" << endl;

	cin >> cont;
	x = zero_or_one(cont);
	
	} while(x != 0);	



	

	return 0;

}

