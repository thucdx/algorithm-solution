#include <iostream>
#include <algorithm>
using namespace std;
int n,m,p[1005];
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        
        scanf("%d",&p[i]);
    }   
    sort(p,p+m);
    int low=max(m-n,0),rs=-1,price;
    for(int i=m-1;i>=low;i--)
    {
        if(p[i]*(m-i)> rs)
        {
            rs=p[i]*(m-i);
            price=p[i];   
        }
    }
    printf("%d %d", price, rs);
}
