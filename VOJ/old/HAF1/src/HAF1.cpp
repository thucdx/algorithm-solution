#include <iostream>
using namespace std;
#include <stdio.h>
#define max 1003

long long m,n;
long long l[max][max];
long long f[max][max];

long long min(long long ,long long);
long long min(long long,long long ,long long);
long long min(long long a, long long b, long long c, long long d);
void input();
void process();
int main(){
    input();
    process();
}
void input(){
    long long i,j;
    scanf("%lld%lld",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        scanf("%d",&l[i][j]);
    }
}
void process()
{
    long long i,j;
    long long INF=1000000000+1;
    //initial
    for(i=1;i<=n;i++)
    {   f[0][i]=0;
        f[1][i]=l[1][i];
        f[m+1][i]=INF;
    }
    for(i=1;i<=m;i++)
    {
        f[i][0]=INF;
        f[i][n+1]=INF;
    }
    //qui hoach dong lan 1.
    for(i=2;i<=m;i++)
    {
    for(j=1;j<=n;j++)
        f[i][j]=min(f[i-1][j],f[i][j-1])  +l[i][j];
    for(j=n;j>=1;j--)
        f[i][j]=min(f[i][j], f[i][j+1]+l[i][j]);
    }
    //tim min cua f[m][]
    long long shortLen=INF;
    for(i=1;i<=n;i++)
        if(shortLen>f[m][i]) shortLen=f[m][i];

    printf("%lld\n",shortLen);
}

long long min(long long a,long long b)
{
    if (a<b) return a;
    else return b;
}
long long min(long long a, long long b, long long c, long long d){
    return min(min(a,b,c),d);
}
long long min(long long a,long long b, long long c ){
    long long rs=a;
    if (rs>b) rs=b;
    if (rs>c) rs=c;
    return rs;
}
