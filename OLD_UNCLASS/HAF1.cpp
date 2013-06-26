#include <iostream>
using namespace std;
#define max 1003

int m,n;
int l[max][max];
int f[max][max];

int min(int ,int);
int min(int,int ,int);
int min(int a, int b, int c, int d);
void input();
void process();
int main()
{
    input();
    process();
}
void input(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        scanf("%d",&l[i][j]);
    }
}
void process()
{
    int i,j;
    int INF=100000;
    //initial
    for(i=1;i<=n;i++)
    {   f[0][i]=INF;
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
        f[i][j]=min(f[i-1][j],f[i][j-1])+l[i][j];
    for(j=n;j>=1;j--)
        f[i][j]=min(f[i][j],f[i][j+1]+l[i][j]);
    }
    //tim min cua f[m][]
    int shortLen=INF;
    for(i=1;i<=n;i++)
        if(shortLen>f[m][i]) shortLen=f[m][i];

    printf("%d\n",shortLen);
}

int min(int a,int b)
{
    if (a<b) return a;
    else return b;
}
int min(int a, int b, int c, int d){
    return min(min(a,b,c),d);
}
int min(int a,int b, int c ){
    int rs=a;
    if (rs>b) rs=b;
    if (rs>c) rs=c;
    return rs;
}
