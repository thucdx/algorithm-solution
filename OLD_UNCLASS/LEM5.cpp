#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100005],n,f[100005][105];

multimap<int, int> s; //val ,i;
multimap<int,int>::iterator it;
pair<multimap<int,int>::iterator,multimap<int,int>::iterator> ret;
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    scanf("%d",&n);
    int rs=-1,d;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]); 
        for(d=1;d<=100;++d)
        {
            ret=s.equal_range(a[i]-d);
            for(it=ret.first; it!=ret.second;++it)
            {   
                f[i][d]=max(f[i][d],f[(*it).second][d]+1);    
            }                  
            if(f[i][d]>rs) rs=f[i][d];
        }
        s.insert(pair<int,int>(a[i],i));
        
    }
    printf("%d",rs+1);
}
    
