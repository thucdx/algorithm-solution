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
struct house
{
int income,outcome,dia;
house(){
    income=-1;outcome=-1;
    dia=1000005;
}
};
struct tanktap
{
int tank,tap,diameter;    
};
tanktap tt[1005];
bool cmp( tanktap t1, tanktap t2)
{
if (t1.tank >t2.tank) return false;
return true;    
}
int nTank;
bool f[1005];
house h[1005];
int n,nPipe;

void trace(int a);
int main()
{
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    scanf("%d%d",&n,&nPipe);
    int in,ou,di;
    for(int i=1;i<=nPipe;i++)
    {
        scanf("%d%d%d",&in,&ou,&di);
        h[in].outcome=ou;
        h[in].dia=di;
        h[ou].income=in;  
    }
    int i,j,t;
    
    for(i=1;i<=n;i++)
    {
        if(h[i].outcome!=-1 && h[i].income==-1) //tank
            nTank++;   
    }
    cout<<nTank<<endl;
    for(i=1;i<=n;i++)
    {
        if(h[i].outcome!=-1 && h[i].income==-1    )
        {
            cout<<i<<" ";    
            int next=h[i].outcome;
            int minDia=h[i].dia;
            while(h[next].outcome!=-1)
            {
                minDia=min(minDia,h[next].dia);
                next=h[next].outcome;
            }
            cout<<next<<" "<<minDia<<endl;
        }
    }
}
    
