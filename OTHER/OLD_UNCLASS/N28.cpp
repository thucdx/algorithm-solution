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
bool col[25];
long long num;
void att(int i);
int n=20;
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	
	for(n=2;n<=10;n++)
	{  
        for(int i=0;i<=24;i++)
        col[i]=false;
        num=0;
    	att(1);
	    cout<<n<<" "<<num<<endl;
    }
}
void att(int i) //dong i.
{   
    if(i==n+1) num++;
    for(int j=1;j<=n;++j)
    {
        if(!col[j] && j!=i)
        {
           col[j]=true;
           att(i+1);
           col[j]=false;        
        }    
    }
}
