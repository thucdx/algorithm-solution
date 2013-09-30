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

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
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
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int nTest;
	string a,temp;
	cin>>nTest;
	while(getchar()!='\n');
	FOR(i,1,nTest)
	{

		cout<<i<<" ";
		getline(cin,a);
		getline(cin,temp);
		FOR(i,0,(a.length()-1))
		{
			if(a[i]>='A' && a[i]<='Z')
			{
				cout<<temp[a[i]-'A'];
			}
			else cout<<a[i];
		}
	cout<<endl;
	}
}
