#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
   void *line = NULL;
  void *tmp = NULL;
   int size =0, index=0;
   int ch =EOF;
cout << "enter text:";
   while (ch){
      ch= getc(stdin);

      if (ch='\n')
	 ch=0;
      if (size <= index){
         
	 tmp= realloc(line, size);
	 if(!tmp){
	    free(line);
	    line = NULL;
	    break;
	 }
         line=tmp;
      }
      line[index++];
   }
   cout <<line<< endl;
   return 0;
}
