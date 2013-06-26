#include <iostream>
#include <vector>

using namespace std;

int f[105][105];
vector <int> adj[105];
int val[105];
int n,k;
int main()
{   
    freopen("OPTION.INP", "rt", stdin);
    freopen("OPTION.OUT", "wt", stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {   
        int value,m,ver;
        scanf("%d%d",&value,&m);
        val[i]=value;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&ver);
            adj[i].push_back(ver);    
        }
   
    }
    int l=0;
    for(int i=1;i<=n;i++)
    {
        f[i][0]=0;
        f[i][1]=val[i];
    }
    for(l=2;l<=k;l++)
    {
        for(int i=1;i<=n;++i)
        {
            //tinh f[i][l]=val[i]+max(...)
            for(int j=0;j<adj[i].size();j++)
            {
                f[i][l]=max(f[i][l],f[adj[i][j]][l-1]);
            }
            f[i][l]+=val[i];    
        }   
    }
    int rs=-1;
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i][k]> rs) 
        {rs=f[i][k];    
        pos=i;
        }
    }
    cout<<rs<<" "<<pos<<endl;
    
    
}
