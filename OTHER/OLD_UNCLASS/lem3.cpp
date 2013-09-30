#include<iostream.h>
long n,c[16][16],mu[17],s[66000][16];
int nhap();
int xuli();
int inkq();
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    nhap();
    xuli();
    inkq();
    return 0;
}
int nhap()
{
    cin >> n;
    int i,j;
    for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    cin >> c[i][j];
    mu[0]=1;
    for (i=1;i<=16;i++) mu[i]=mu[i-1]*2;
    return 0;
}
int xuli()
{
    long i,j,k;
    for (k=1;k<=mu[n]-1;k++)
    {
        for (i=0;i<n;i++)
        if ((k&mu[i])!=0)
        {
              if (k==mu[i]) s[k][i]=0;
              else
              {
              s[k][i]=1000000;
              for (j=0;j<n;j++)
              if (((k&mu[j])!=0)&&(i!=j))
              {
                 if (s[k-mu[i]][j]+c[j][i]<s[k][i]) s[k][i]=s[k-mu[i]][j]+c[j][i];
              }
              }
        }
    }
    return 0;
}
int inkq()
{
    long max=1000000,i;
    for (i=0;i<n;i++)
    if (s[mu[n]-1][i]<max) max=s[mu[n]-1][i];
    cout << max;
    return 0;
}
    
