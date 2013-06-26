#include <iostream>
using namespace std;
char W[100],X[100],tmp[100];
int countN=0;
bool isNumber(char* a);
int findQMark(char* a);
void attempt(int i);
int main(){
  
  do
  {
   cin >>W;
   if(strcmp(W,"#")==0) break;
   cin>>X;
   strcpy(tmp,W);
   countN=0;
   attempt(0);
   cout<<countN<<endl;                 
  }
  while(true);
  
}
void attempt(int i)
{
 if(!isNumber(tmp))
 {
 int j;
 int pos=findQMark(tmp);
  for( j='0'; j<='9';j++)
  {
   tmp[pos]=j;
   attempt(i+1);
   tmp[pos]='?';
   }
 }
 else if(strcmp(tmp,X)>0) countN++;  
    
}
bool isNumber (char *a){
     bool rs=true;
     int i=0;
     for(i=0;i<strlen(a);i++)
          if(a[i] <'0' || a[i] >'9') return false;
     return true;
}
int findQMark(char *a){
    int i=0;
    for(i=0;i<strlen(a);i++)
                            if(a[i]=='?') return i;
    return -1;
}
