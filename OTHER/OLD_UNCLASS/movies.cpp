#include<iostream.h>
#include<string.h>
#include<math.h>
long  long m,n,sl;
char s[50];
long long kq;
struct ghe{long u,v;};
ghe a[50];
int nhap();
int xuli();
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("movies_demo.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    cin >> s;
    while (strcmp(s,"[END]")!=0)
    {
          nhap();
          xuli();
          cout << kq<< "\n";
          cin >> s;
    }
}
int nhap()
{
    cin >> n;
    cin >> m;
    char ss[15];
    cin >> ss;
    sl=0;
    cin >> ss;
    while (strcmp(ss,">>")!=0)
    {
          sl++;
          a[sl].u=atol(ss);
          cin>> ss;
    }
    cin >> ss;
    int i;
    for (i=1;i<=sl;i++) cin >> a[i].v;
    cin >> s;
    return 0;
}
bool ss(ghe a ,ghe b)
{
     if (a.u!=b.u) return (a.u>b.u);
     return (a.v>b.v);
}
int xuli()
{
    int i,j;
    ghe tg;
    kq=(m-1)*n;
    a[sl+1].u=0;
    for (i=sl;i>=2;i--)
    for (j=1;j<=i-1;j++)
    if (ss(a[j],a[j+1])){tg=a[j];a[j]=a[j+1];a[j+1]=tg;}
    for (i=1;i<=sl;i++)
    {
        if (a[i].v>1) kq--;
        if (a[i].v<m) kq--;
        if ((a[i+1].u==a[i].u)&&(a[i+1].v==a[i].v+1)) kq++;
    }
    return 0;
}
