#include <iostream>
#include <string>

using namespace std;

string get_sentence(string s){
   cout << "please enter a sentence:";
   getline(cin,s); 
return s;
}


int main(){

   string s;

   s = get_sentence(s);
   cout << s << endl;

return 0;
}
