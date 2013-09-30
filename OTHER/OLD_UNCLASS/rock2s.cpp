#include<iostream.h>
#include<stdio.h>
long n,dau[33000],d[15],day[33000];
bool ok;
int duyet(long a,long i);
int inkq();
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    cin >> n;
    ok=false;
    dau[0]=1;
    duyet(0,1);
    inkq();
}
int duyet(long a,long i)
{
    if (ok) return 0;
    if ((a==0)&&(i>1))
    {
         if (i==(1<<n)+1) ok=true;
         return 0;
    }
    long tg,j;
    for (j=0;j<n;j++)
    {
         day[i]=j;
         if ((a&(1<<j))==0) tg=a+(1<<j);else tg=a-(1<<j);
         if ((dau[tg]==0)|| ((dau[tg]==1)&&(tg==0)&&(i==(1<<n))))
         {  dau[tg]=1;
            duyet(tg,i+1);
            if (ok) return 0;
            dau[tg]=0;
         }
    }
}
int inkq()
{
    long i,j;
    //for (i=4;i<=(1<<n);i=i+4){ cout << day[i]+1 << " ";if (i==(1<<(n-1))) cout << "\n";}
    long a=0;
    for (i=1;i<=(1<<n);i++)
    {
        for (j=0;j<n;j++) if ((a&(1<<j))==0) printf("O");else printf("X");
        if ((a&(1<<day[i]))==0) a+=(1<<day[i]);else a-=(1<<day[i]);
        printf("\n");
    }
    for (j=0;j<n;j++) if ((a&(1<<j))==0) printf("O");else printf("X");
    return 0;
}
