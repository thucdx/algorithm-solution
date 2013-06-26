/*
VSTEPS
*/
#include <iostream>
using namespace std;
#include <conio.h>
#define RM 14062008
int n,k;
bool f[100000];
int rs[100000];
void input();
void initial();
void process();
int main(){
    initial();
    input();
    process();
    getch();
}
void initial()
{
 memset(f,1,100000);
 memset(rs,0,100000);
}
void input()
{
 int i,pos;
 cin>>n;
 cin>>k;
 for(i=0;i<k;i++)            
 {
  cin>>pos;
  f[pos]=false;
 }
}
void process()
{
 int i;
 rs[1]=1;
 if(f[2]) rs[2]=1;
 for(i=3;i<=n;i++)
 {                
     if(f[i-1]) rs[i]=(rs[i]+rs[i-1])%RM;
     if(f[i-2]) rs[i]=(rs[i]+rs[i-2])%RM;
     //cout<<i<<'-'<<rs[i];             
 }
 cout<<rs[n];    
}
