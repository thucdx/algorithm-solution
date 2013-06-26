#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1005],f[1005],n;
multiset<int> s;

bool exist(int i, int j)
{
    int k=s.count(j-i);
    if(j==2*i)
    {
        return (k>1);    
    }   
    return k>=1;
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    sort(a,a+n);
    int rs=-1;
    for(int i=n-1;i>=0;i--)
    {
          for(int j=i+1;j<n;j++)
          {
            if(exist(a[i],a[j]))
            {
                f[i]=max(f[i],f[j]+1);    
            }          
          }
          if( f[i] >rs) rs=f[i];  
    }
    printf("%d",rs+1);
    
    
}
