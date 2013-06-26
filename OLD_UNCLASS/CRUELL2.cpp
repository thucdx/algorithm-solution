#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;
struct inte{
    double h, t;
    inte()
    {}
    inte(double _h, double _t){
        h=_h;
        t=_t;   
    }
    
};
double f(double x);
queue <inte> q;
double d[15];
double x;
int n;
void solve();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
       cin>>d[i];    
    }
    solve();
    printf("%d",(int)(x*1000.0));
}
void solve()
{   
    double head=-1000000.0,tail=1000000.0,mid;  
    double fhead,ftail,fmid;
    double eps=1e-20;
    fhead=f(head);
    ftail=f(tail);
    while(tail-head>eps)
    {   
        mid=(head+tail)/2; 
        fmid=f(mid);                      
        if(fabs(fmid)<eps)
        {
            x=mid;
            return;    
        }
        if(fhead*fmid<eps)
        {
            ftail=fmid;
            tail=mid;    
        }
        else
        {
            head=mid;
            fhead=fmid;    
        }
    }
    x=(head+tail)/2.0;
    
}
double f(double x)
{
    double rs=d[n];    
    for(int i=n-1;i>=0;i--)
    {
        rs=rs*x+d[i];    
    }
    return rs;
}
