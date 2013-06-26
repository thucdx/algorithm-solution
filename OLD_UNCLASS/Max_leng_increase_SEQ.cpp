#include <conio.h>
#include <iostream>
using namespace std;
#define MAX 1000000

int a[MAX];
int L[MAX];
int After[MAX];
int StartOf[MAX];
int n,maxlen;
void initial()
{
     a[0]=-MAX-1;
     a[n+1]=MAX+1;
     L[n+1]=1;  
     StartOf[1]=n+1;
     maxlen=1; 
}
int find(int i) //find i in StartOf
{
    int inf, sup,median,j;
    inf=1;sup=maxlen+1;
    do
    {
        median=(inf+sup)/2;
        j=StartOf[median];
        if(a[j]>a[i]) inf=median;
        else  sup=median;             
    }
    while(inf+1!=sup);
    return StartOf[inf];
}
void optimize()
{
    int i,j,k;
    for(i=n;i>=0;i--)
    {
         j=find(i);
         k=L[j]+1;
     if(k>maxlen)
     {
          maxlen=k;
          StartOf[k]=i;
     }
     else
         if(a[StartOf[k]] <a[i])
         StartOf[k]=i;
     L[i]=k;
     After[i]=j;               
    }   
}
void result()
{
     int i=After[0];
     cout<<"Maxlen:" <<maxlen-2<<endl;
     while(i!=n+1)
     {           
                 cout<<a[i]<<' ';
                 i=After[i];
     }     
     cout<<endl;
}
int main()
{
     int i,j;
     
     //Input
     cout<<"n= ";
     cin >>n;
     for(i=1;i<=n;i++)
     {
      cin>>a[i];                 
     }
     //
     initial();
     optimize();
     result();
     getch();  
}
