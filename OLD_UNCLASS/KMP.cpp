#include <iostream>
using namespace std;
#include<conio.h>
#define MAX 100
#include<conio.h>
char X[MAX];
int next[MAX];
char A[MAX];
int n,m;

void init();
void process();
int main(){
    cout<<"Enter two String:"<<endl;
    cin>>A>>X;
    cout<<"Accept\n"<<X<<"\n"<<A;
    n=strlen(A);
    m=strlen(X);
    cout<<"\n"<<n;
    init();
    process();
    getch();
}
void init(){
     int j,jj;
     j=0;jj=0;
     next[0]=0;
     while(j<n)
     {
      while(jj>=0 && (X[j]!=X[jj])) jj=next[jj];
      j++;
      jj++;
      if(X[j]==X[jj]) next[j]=next[jj]; else next[j]=jj;           
     }
     cout<<"Initialized!";
}
void process(){
     int i,j;
     i=0;j=0;
     do{
     while(j>=0 &&(X[j]!=A[i])) j=next[j]    ;
     i++;
     j++;
     if(j>=n){
             cout<<"appears at "<<i-j+1;
             j=next[j];
             }
     }       
     while(i<=m); 
     
}
