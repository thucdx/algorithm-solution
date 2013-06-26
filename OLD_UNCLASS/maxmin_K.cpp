#include <iostream>
using namespace std;
#include <conio.h>
int sub[]={1,3,5,7,8,9,4,2,6,8,9,3,4,3};
int n=14;
int k;
int minL=100;
int pos=-1;

void process();
int main()
{   
     k=19;
     process();
     getch();
}
void process()
{
 int i,j;
 int sum=0;
 bool found=true;
 j=0;
 for(i=0;i<n;i++)
 {
  while(j<n && sum<k)
  {
   sum=sum+sub[j];  
   j++;
         
  }
  if(sum>=k){
             if(j-i<minL)
             {
              minL=j-i;
              pos=i;            
             }
             j=i+1;
             sum=0;
  }                
  else { break;}
 }
 //getch();
 if(pos!=-1){
      for(j=pos;j<=pos+minL-1;j++)
      cout<<sub[j]<<';';     
      }
      else cout<<"-1"<<endl;
 
      
}
