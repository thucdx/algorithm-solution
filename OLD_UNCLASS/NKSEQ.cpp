/*
NKSEQ
*/
#include <iostream>
using namespace std;
#define MAX 100000
#include <conio.h>
int n;
int a[MAX];
int sum[MAX];
int number();
int main(){
    
   int i=0;
   cin>>n;
   cin>>a[0];
   sum[0]=a[0];
   for(i=1;i<n;i++)
   {
      cin>>a[i];
      sum[i]=sum[i-1]+a[i];   
   }
   cout<<number(); 
   getch();
}

int number(){
    int count=0,i,j;
    bool isGood=true;
    //check phan tu dau tien
    for(j=0;j<n;j++)
       if(sum[j]<=0) {isGood=false;}
    if (isGood) count++;
    //check phan tu thu 2 tro den het
    for(i=1;i<n;i++)
    {
     bool isGood=true;
     //check a[i] co phai vi tri tot ko.
     for(j=0;j<n;j++)
     {
         sum[j]=sum[j]+(a[(i+j)%n]-a[i-1]);
         cout<<i<<"- "<<j<<"= "<<sum[j]<<endl;
         if(sum[j]<=0) isGood=false;
     }
     if (isGood) count++;            
    }
    return count;
}
