/*
Chinh hop chap k cua n phan tu 
*/
#include <iostream>
using namespace std;
#include<conio.h>
#define MAX 100

int k,n;
bool a[MAX];
int x[MAX];

void init();
void printResult();
void attempt(int i);

int main(){
    cout<<"k, n= ";
    cin>>k>>n;
    cout<<"Accept: k= "<<k <<" n= "<<n;
    init();
    attempt(0);
    cin >>k;
}
void init(){
     for(int i=0;i<MAX;i++)
          a[i]=true;//not chosen yet
} 
void printResult(){
     
     cout<<endl<<'(';
     for(int i=0;i<k;i++)
     cout<<x[i]<<' ';
     cout<<')';
}
void attempt(int i){
     int j;
     for(j=0;j<n;j++){
           if(a[j]){
                      x[i]=j;
                      if(i==k-1) printResult();
                      else{
                           a[j]=false;
                           attempt(i+1);
                           a[j]=true;
                           }           
     }
     }
}
