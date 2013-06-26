#include <iostream>
using namespace std;
#include<conio.h>
#define MAX 100
#include<conio.h>
char str[MAX];
int smin=100;
int nC=0;
int n;
bool hasResult=false;

void init(){
}
void printResult();
void attempt(int i);
bool check(char * st,int size);
int main(){
    cout<<"n= ";
    cin >>n;
    attempt(0);
    //cout<<   check("CBCAA",5);
    getch();
}
void attempt(int i){
     if(hasResult) return;
     int j;
     for(j='A'; j<='C';j++)
     {
      str[i]=j;
      if(i==n-1 && !check(str,i+1)) {printResult(); hasResult=true;return;}
      if(j=='C') nC++;
      if(!check(str,i+1) && (nC+(n-i)/4)<smin)
      {
          attempt(i+1); 
                                   
      } 
      if(j=='C') nC--;
     }
}
void printResult(){
     cout<<"\nResult: "<<endl;
     for(int i=0;i<n;i++)
     cout<<str[i];
    
}

bool check(char *a ,int size){
     int i,j,t;
     int min;
     for(i=0;i<size;i++) 
     { if(i<size/2) min=i-1; else min=2*i-size;
     for(j=i-1;j>=min;j--){
            
            if(a[j]==a[i]){
                           t=j+1;
                           while(a[t]==a[i+t-j] && t<i) t++;
                           if (t==i) return true;                     
            }                   
     }
     }
     return false;
}
