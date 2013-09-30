#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int a[1000005];
int main()
{
    //freopen("gra.in", "rt", stdin);    
    //freopen("gra.out", "wt", stdout);    
    scanf("%d%d", &n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);    
    }
    a[m]=n+1;
    sort(a,a+m+1);
    int dis=0;
    if(a[m-1]==n-1) printf("1");
    else
    {
        for(int i=0;i<m;++i)
            dis+=a[i+1]-a[i]-1;
        //cout<<dis<<endl;
        if(dis%2==0 ) printf("0");
        else 
        printf("%d",dis/2);
    }
    
}
