#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define FORX(i, a, b) for (int i = a; i <= b; ++i)
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

int l[5];
int n;
int make();
list<int> t[150];
int main()
{
	//freopen("input.txt","rt",stdin);
	//FORX(i,0,99) t[i]=new list();
	freopen("output.txt","wt",stdout);
	n=25;
	//att(0);
	int lim=(1<<n)-1;
	FORX(i,1,lim)
	{
     int count=0,val=0;
     FORX(j,0,n-1)
     {
        if ((i & (1<<j))!=0)
        {
         count++;
         val+=(j+1);       
        }           
     }   
     if(count==5)
        t[val].push_back(i);         
    }
    cout<<"Xong"<<endl;
    
    FORX(i,0,149)
    {
     if(!t[i].empty())
     {
         cout<<endl<<i<<" ";
         cout<<t[i].size()<<" ";
         while(!t[i].empty())
         {
            cout<<t[i].front()<<" ";                 
            t[i].pop_front();
         }              
     }
    }
    
}
