#include <iostream>
using namespace std;
#include<conio.h>
#define MAX 100
int n;
bool a[MAX];
bool b[2*MAX];
bool c[2*MAX];
int x[MAX];
void init();
void printResult(){
     cout<<"\nresult:"<<endl;
     for(int i=0;i<n;i++)
      cout<<'('<<i<<','<<x[i]<<')';
}
void attempt(int i)
{
 int j;
 for ( j=0;j<n;j++)
 if(a[j] && b[i+j] && c[i-j+n])
 {
  x[i]=j;
  if(i==n-1) printResult();
  else 
  {
   a[j]=false;
   b[i+j]=false;
   c[i-j+n]=false;
   attempt(i+1);
   a[j]=true;
   b[i+j]=true;
   c[i-j+n]=true;        
  }        
 }                
}
int main()
{   
    init();
    cout<<"n= ";
    cin>>n;
    cout<<"Accept n= "<<n<<endl;
    attempt(0);  
    getch();       
}
void init(){
     int i;
     for(i=0;i<MAX;i++){
          a[i]=true;
     }
     for(i=0;i<2*MAX;i++){
      b[i]=true;c[i]=true;
     }
     
}
