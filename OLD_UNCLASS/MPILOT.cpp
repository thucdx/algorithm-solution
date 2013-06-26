#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n,x,y,r=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        r+=x;
        q.push(x-y);
        if(i&1)
        {
            r-=q.top();
            q.pop();    
        }
    }
    printf("%d",r);
    
}
