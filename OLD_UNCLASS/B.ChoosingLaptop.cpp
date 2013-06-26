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
#define INF 10000000
typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;
struct lap{
    int speed, ram, hdd,cost;
    lap(){}
    lap(int s, int r, int h, int c)
    {
        speed=s;
        ram=r;
        hdd=h;
        cost=c;
    }
    bool operator<(const lap& that) const{
        if(speed <that.speed && ram<that.ram && 
            hdd<that.hdd)  
            return true;
        return false;
    }
    /*
    void operator=(const lap& that) 
    {
        speed=that.speed;
        ram=that.ram;
        hdd=that.hdd;
        cost=that.cost;
        pos=that.pos;
    } */   
};
bool cmp( lap l2, lap l1)
{
    if(l1.speed <l2.speed) return false;
    return true;    
}
lap l[1005];
int n;
int pos,postAfterSort, minPrice=INF;

int main()
{
	//freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	scanf("%d",&n);
	FOR(i,0,n-1)
	{
        scanf("%d%d%d%d",&l[i].speed,&l[i].ram,&l[i].hdd, &l[i].cost);
    }
    FOR(i,0,n-1)
    {   
        bool isOutdate=false;
        FOR(j,0,n-1)
        {
            if(l[i]<l[j]) { isOutdate=true; break;}
        }
        if(!isOutdate){
            if(l[i].cost<minPrice)
                {
                    minPrice=l[i].cost;
                    pos=i+1;    
                }   
        }
    }
	
    printf("%d",pos);
    return 0;
}
