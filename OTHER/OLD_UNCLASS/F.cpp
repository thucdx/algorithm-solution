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
int isWin(char p1,char p2)
{
	if(p1==p2) return 0;
	if(p1=='R' && p2=='S') return 1;
	if(p1=='S' && p2=='P') return 1;
	if(p1=='P' && p2=='R') return 1;
	return -1;

}
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	string a,b;
	int p1, p2;
	do
	{
		cin>>a;
		cin>>b;
		if(a=="E" && b=="E") break;
		p1=0;p2=0;
		FOR(i,0,a.length()-1)
		{
			int m=isWin(a[i],b[i]);
			if(m==1) p1++;
			else  if(m==-1) p2++;

		}
		cout<<"P1: "<<p1<<endl<<"P2: "<<p2<<endl;
	}
	while(true);
}
