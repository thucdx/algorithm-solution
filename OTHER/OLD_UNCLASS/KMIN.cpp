#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define INF 2000000005
using namespace std;
int a[50005],b[50004],m,n,k;
struct obj
{   
    int x, y;
    obj(){}
    obj(int a, int b){
        x=a;y=b;
    }
    bool operator<(const obj &c) const
    {
        return (a[x]+b[y])>(a[c.x]+b[c.y]);    
    }
};

priority_queue<obj> s;

int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int i,j;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    
    sort(a,a+m);
    sort(b,b+n);
    for(int i=0;i<m;++i)
    {
        s.push(obj(i,0));    
    }
    obj g;
    for(int i=1;i<=k;++i)
    {   
          if(s.empty()) {printf("Empty\n"); continue;}
          g=s.top() ;
          s.pop();
          printf("%d\n",a[g.x]+b[g.y]);
          g.y++;
          if(g.y<n)
              s.push(g);
    }
}
