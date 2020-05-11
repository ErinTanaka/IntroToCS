#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
 
struct county{
   string name;
   float avg_house;
};

struct state{
   string name;
   struct county * c;
   int counties;
};

int main(){
  /* state* list;
   list = new state[3];
   
   for (int i=0; i<3; i++){
      cout <<  "enter info as prompted" << endl;
      cout << "state name: ";
      cin >>  list[i].name;
      cout << "number of counties: 2";
      list[i].counties=2; 
      list[i].c= new county[2];
      cout << "made counties" << i << endl;
      for (int j=0; j< 2; j++){
	 list[i].c[j].avg_house=j;
         cout <<"set avg income to " << list[i].c[j].avg_house << endl;
      }
   
   }*/
  int m[]={5,6,0,1 };
  int temp, count;
  count=0;
  //print numbers
  for (int i=0; i<4; i++){
    cout << m[i] <<  " ";
  }
  cout << endl;
//switching numbers
  while (count!=4){
     cout <<"current count: " << count << endl;
     for (int i=3; i>0; i--){
        if ((i-1)>=0){
           if (m[i] < m[i-1]){
              temp=m[i];
	      m[i]=m[i-1];
	      m[i-1]=temp;
           }
        }
     }
  count++;
  }	
  for (int i=0; i<4; i++){
    cout << m[i] <<  " ";
  }
  cout << endl;
   return 0;
}
