#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void print_fourth(int *a){
   cout << "the 4th char is:" << a[3] << endl;
}
int my_strlen(char *c){
   cout << "what got passed into function " << c << endl;
   int length =0;
   while (c[length] !='\0'){
      length++;
   }
   return length;
}
/*int* make_array(int size){
   int array[size];
   for (int i=0; i< size; i++)array[i]=i;
   cout << array << endl;
   return array;
}
*/
int main(){
   int arr[5] = {3, 2, 7, 10, 1};
   int *ptr = arr;
   int *arg;

   cout << ptr << endl;
   cout << "a: " << arr[2] << endl;
   cout << "b: " << ptr[2] << endl;
   cout << "c: " << *arr << endl;
   cout << "d: " << *ptr << endl;
   cout << "e: " << *(ptr+1) << endl;
   cout << "f: " << *(arr+3) << endl;
   cout << "g: " << *ptr+1 << endl;
   cout << "h: " << *arr+1 << endl;

   int array[5] = {1, 2, 3, 4, 5};
   int *a= array;
   print_fourth(a);

   int too_small[2] = {10,20};
   int *b= too_small;
   print_fourth(b);
   //print_fourth(too_small);
   
  // arg = make_array(4);
  //  cout << *arg << endl;
   
 
   char cstr[4] = {'H', 'i', '!', '\0'};
  cout << "the string is: " << cstr << endl;
   char *c = cstr;
  int length;
  length = my_strlen(c);
  cout << "length is " << length << endl;
   return 0;
}
