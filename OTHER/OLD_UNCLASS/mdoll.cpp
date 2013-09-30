#include<iostream.h>
#include<stdio.h>
long n,test,d[20005],star[20005],l[20005],m;
struct go{long l,w;};
go a[20001];
int nhap();
int xuli();
int inkq();
int main()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "rt", stdin);
      freopen("output.txt", "wt", stdout);
    #endif
    cin >> test;
    for (long t=1;t<=test;t++)
    {
        nhap();
        xuli();
        inkq();
    }
}
int nhap()
{
    scanf("%ld",&n);
    for (long i=1;i<=n;i++) 
    {
        scanf("%ld%ld",&a[i].l,&a[i].w);
        d[i]=0;
    }
}
bool ss(go a,go b)
{
     if (a.l!=b.l) return (a.l>b.l);
     return (a.w<b.w);
}
int upheap(long i,long n)
{
    long j;
    go khoa=a[i];
    while ((i<<1)<=n)
    {
          j=(i<<1);
          if ((j<n)&&(ss(a[j+1],a[j]))) j++;
          if (ss(khoa,a[j])) break;
          a[i]=a[j];
          i=j;
    }
    a[i]=khoa;
}
int xuli()
{
    long i;
    go tg;
    for (i=n/2;i>=1;i--) upheap(i,n);
    for (i=n;i>=2;i--)
    {
        tg=a[1];a[1]=a[i];a[i]=tg;
        upheap(1,i-1);
    }
}
long timkiem(long x)
{
     long l=1,r=m,mid,k;
     while (l<=r)
     {
           mid=(l+r)/2;
           if (d[star[mid]]<=x) {k=mid;l=mid+1;}else r=mid-1;
     }
     return k;
}
int inkq()
{
    long kq=0,i,j,hw,k;
    for (i=1;i<=n;i++) d[i]=a[i].w;
    d[n+1]=0;
    star[1]=n+1;
    l[n+1]=1;
    m=1;
    for (i=n;i>=1;i--)
    {
        k=timkiem(d[i]);
        if (k==m)
        {
                 m++;
                 star[m]=i;
        }
        else
        if (d[i]<d[star[k+1]]) star[k+1]=i;
        l[i]=k+1;
    }
    cout << m-1<<"\n";
}
