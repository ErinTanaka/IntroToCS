#include <iostream>
#include <string>

using namespace std;
void dointhings(string &str);
int main(){
   string mystr;
   mystr="hello world";
   cout << "whole string: " << mystr << endl;
   cout << "3rd character in string: " << mystr[2] << endl;
   dointhings(mystr);
   cout << mystr << endl;

   cout << "dynamic 1-d array" << endl;

   int *a;
   a= new int[3];
   a[0]=1;
   a[1]=2;
   a[2]=9;

   cout << "2nd element of a: " <<  a[1] << endl;

   cout <<  "static 2d array" << endl;

   int 2darray[4][2];

   
   return 0;
}

void dointhings(string &str){
   str[0]='s';
   str[1]='t';
   str[2]='a';
   str[3]='r';
   str[4]='t';

}
