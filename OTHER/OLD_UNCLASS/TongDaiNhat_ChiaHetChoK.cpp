#include <iostream>
using namespace std;
#define MAX 10000
#define INF 100000
int a[MAX];
int n,k;
int f[MAX][MAX];

#include<conio.h>
void input();
void inputFile(char *fileName);
void initial();
void optimize();
void result();
int sub(int ,int ,int);

int main()
{
    input();
    initial();
    optimize();
    result(); 
    getch();
}
void inputFile(char *fileName)
{
    FILE *ip;
    freopen(fileName,"rt",ip);
    
}
void input()
{
 cin>>n>>k;
 int i;
 for(i=0;i<n;i++)
 {
  cin>>a[i];
  }
}
void initial()
{
 int i,j;
 for(i=0;i<k;i++)
  f[0][i]=INF;
  f[0][0]=0; 
}
int sub(int a,int b,int k)
{
 return (k+a%k-b%k)%k;    
}
void optimize()
{
     int i,t;
     for(i=1;i<n;i++)
     for(t=0;t<k;t++)
     {
      if(f[i-1][t] <1+f[i-1][sub(t,a[i],k)])
            f[i][t]=f[i-1][t];
      else 
           f[i][t]=1+f[i-1][sub(t,a[i],k)];        
     }
}
void result()
{
 int sumAll=0;   
 //print list;
 int i,j;;
 for(i=0;i<n;i++)
                 sumAll+=a[i];
 int count=0;                
 
 j=sumAll%k;
 if(f[n-1][j]==INF) cout<<n<<endl;
 else
 cout<<n-f[n-1][j]<<endl;
 
 
 
}
