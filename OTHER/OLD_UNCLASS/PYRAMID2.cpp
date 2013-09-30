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
#define MAX 1000000

long long  f[MAX+5];
int c;
char c[MAX+5];
void solve();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i)
	{
        scanf("%c",&c[i]);
    }
    solve();
}
void solve()
{   
    
    // 0 < , 1 >
    
    // 
    f[0][0]=0; f[1][0]=0;
    for(int i=1;i<n;i++){
        if(c[i]=='>')
        {  
                f[i]=f[i-1];
        }
        else  //c[i]=='<'
        {
            if(c[i-1]=='>') //doi dau
            {
                if(f[i-1]==0)
                    f[i]=1;
                else     
                    f[i]=f[i-1];
            }    
        }
    }
    
    
    
}
