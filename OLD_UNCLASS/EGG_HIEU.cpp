#include <cstdio>
#include <conio.h>
#include <iostream>
using namespace std;
    //#include <conio.h>
int a[1000][1000],t,n,m,x;
int main()
{
    
    for(int i=0;i<1000;i++)
    {
    a[0][i]=1;
    a[i][0]=1;
    }
    for(int i=1;i<10;i++)
    for(int j=1;j<10;j++)
    {
        a[i][j]=a[i][j-1]+a[i-1][j-1];
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
    scanf("%d %d",&n,&m);
    for(int j=0;j<1000;j++)
    {
    m=m-a[n-1][j];
    if(m<=0)
    {
        x=j;
        break;
    }
    }
    printf("%d\n",x+1);
}
    //getch();
    }

