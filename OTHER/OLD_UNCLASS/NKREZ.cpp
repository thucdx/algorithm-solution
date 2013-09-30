#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
struct REZER
{
    int from, to;
    REZER()
    {}
    REZER(int _f, int _t)
    {
        from=_f;
        to=_t;    
    }
    bool operator<(const REZER&that) const
    {
        if(to!=that.to)
        {
            return to<that.to    ;
            
        }   
        else
        {
            return from<that.from;    
        } 
    }    
};
int n;
REZER r[30005];
int f[30005][2];
int main()
{
   // freopen("NKZEX.IN",  "rt", stdin);
   // freopen("NKZEX.OUT", "wt", stdout);
    scanf("%d",&n);
    REP(i,0,n-1)
    {
        scanf("%d %d",&r[i].from,&r[i].to);    
    }
    sort(r,r+n);
    //Quy hoach dong
    f[0][0]=0;
    f[0][1]=r[0].to-r[0].from;
    REP(i,1,n-1)
    {
        f[i][0]=max(f[i-1][0],f[i-1][1]); 
        //tim vi tri n ma r[k].to <=r[k].from;
        int start=0,end=i-1;
        if(r[0].to>r[i].from) f[i][1]=r[i].to-r[i].from;
        else if(r[i-1].to<r[i].from)
            f[i][1]=max(f[i-1][0],f[i-1][1])+ r[i].to-r[i].from;    
        else
        {
            int pos;
            int low=0, hi=i-1;
            while(low<hi-1)
            {
                int mid=(low+hi)/2;
                if(r[mid].to <=r[i].from)
                {
                    low=mid;    
                }    
                else 
                {
                    hi=mid;
                }
            }    
            if(r[hi].to<=r[i].from ) pos=hi;
            else if(r[low].to<=r[i].from) pos=low;
            else pos=-1;
            if(pos!=-1)
            {
                f[i][1]=max(f[pos][0],f[pos][1])+r[i].to-r[i].from;
            }
            else {
                cout<<"pos= -1";
                return 0;
            }
        }
        //cout<<i<<" "<<"f[i][0]"<<f[i][0]<<" "<<"f[i][1]"<<f[i][1]<<endl;
    }
    cout<<max(f[n-1][0],f[n-1][1]);
    
}
    
