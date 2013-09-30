/*
  Name: 
  Copyright: 
  Author: 
  Date: 04/06/11 01:48
  Description: BAG
*/

#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 101
int F[MAX][MAX];
int W[MAX],V[MAX];
int weight,n;

void input();
void initial();
void optimize();
void result();

int main()
{
    input();
    initial();
    optimize();
    result();    
    getch();
}
void input(){
     cout<<"n= , weight= ";
     cin>>n>>weight;
     for(int i=1;i<=n;i++)
     {
      cin>>W[i]>>V[i];        
     }
}
void initial()
{
     for(int i=0;i<=weight;i++)
          F[0][i]=0;   
}
void optimize()
{
     int i,j;
     for(i=1;i<=n;i++)
     for(j=0;j<=weight;j++)
     {
         F[i][j]=F[i-1][j];
         if(j>=W[i] &&(F[i-1][j-W[i]]+ V[i] >F[i][j]))
         {
          F[i][j]=F[i-1][j-W[i]]+V[i];          
         }           
     }     
}
void result()
{
     cout<<"MAX VALUE:"<<F[n][weight]<<endl;
     int i=n, j=weight;
     while(i!=0)
     {
      if(F[i][j]==F[i-1][j])
      i--;
      else
      {
          cout<<i<<" ";
          
          j=j-W[i];    
          i--;
      }           
     }     
}
