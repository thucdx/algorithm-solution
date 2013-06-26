#include <iostream>
using namespace std;
#include <conio.h>
__int64 rs[100];

int main()
{
 //
 int i,j;
 rs[1]=1;
 rs[2]=2;
 for(i=3;i<=100;i++)
  rs[i]=rs[i-1]+rs[i-2];    
 //
 int nTest;
 int t;
 cin>>nTest;
 for(i=1;i<=nTest;i++)
 {
  cin>>t;
  cout<<rs[t]<<endl;                     
 } 
 getch();
}
