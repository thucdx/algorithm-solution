/*
KINV
*/
#include <iostream>
using namespace std;
#include <conio.h>

int n,k;
int A[10000];
int RS[10000][11];

void input();
void initial();
void process();
int main()
{
 input();
 initial();
 process(); 
 getch();   
}
void initial()
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<=k;j++)
  RS[i][j]=0;
 for(i=0;i<=n;i++)
 {
   RS[i][1]=1;   
   RS[i][0]=0;
 }
}
void input()
{
 cin>>n;
 cin>>k;
 int i;
 for(i=0;i<n;i++)
 {
                 cin>>A[i];
 }     
}
void process()
{
 int i,j,t;
 for(i=1;i<n;i++)
 {
    for(j=0;j<i;j++)
    {
      if(A[j]>A[i]) //j<i
      {
        for(t=1;t<=k;t++)
        RS[i][t]=(RS[j][t-1]+RS[i][t])%1000000000;            
      }              
    }               
 }
 
 //Ket qua
 int sum=0;
 for(i=k-2;i<n ;i++)
     sum=(sum+RS[i][k])%1000000000;
  cout<<sum;   
}
