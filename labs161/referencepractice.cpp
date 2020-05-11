#include <iostream>
#include <string>

using namespace std;


void get_sentence(string &s){
   cout << "please enter a sentence:";
   getline(cin, s); 

}


int main(){

   string s;

   get_sentence(s);
   cout << s << endl;

return 0;
}
