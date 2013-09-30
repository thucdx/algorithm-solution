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

int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int nTest;
	string s;
	int gas, have;
	scanf("%d",&nTest);
	for(int i=1;i<=nTest;i++)
	{
        cout<<"Case #"<<i<<": ";
        cin>>have>>s;
        //cout<<have<<s<<endl;
        char prev=' ';    
        gas=0;
        for(int j=0;j<s.length();j++)
        {
              if(s[j]=='R')
                gas+=3;
              else  //s[j]='F'
              { 
                    gas+=2;
                    if(prev=='F')
                        gas-=1;
              }  
              prev=s[j];
        }
        if(gas<=have) cout<<"0"<<endl;
        else cout<< (gas-have)<<endl;
    }
	
}
