// Created : 1:47:58 PM ; Oct 16, 2012

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define FILL(a, x, n) fill(a, a + n, x)
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4.0f * atan(1);  // double or long double ?
const int INF = (int) 1E9 + 5;    // enough ?
const double EPS = 1E-11;        // enough ?
const ll MOD = (ll) 1E9 + 7;    // of problem ?

const int PSIZE = (int) (1e5);
int lft[PSIZE + 5];
int rgt[PSIZE + 5];
int a[PSIZE + 5];
int n;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d",&n);

	memset(lft, 0, sizeof(lft));
	memset(rgt, 0, sizeof(rgt));


	REP(i, n){
		scanf("%d",&a[i]);
		if (a[i] >= 0) lft[i] = (i == 0) ? 1 : (lft[i-1] + 1);
		else lft[i] = (i == 0) ? 0 : lft[i - 1];
	}

	rgt[n - 1] = (a[n - 1] <= 0);

	FORD(i, n - 2, 0){
		rgt[i] = rgt[i + 1] + (a[i] <= 0);
	}

	/*REP(i, n){
		cout << i << " " << lft[i] << endl;
	}
	cout << " ______ " << endl;
	REP(i, n){
			cout << i << " " << rgt[i] << endl;
	}*/

	rgt[n] = 0;

	int ret = INF;
	int first = (a[0] >= 0) + rgt[1];
	int last = (a[n-1] <= 0 ) + lft[n - 2];
	ret = min (ret, first);
	ret = min (ret, last);

	FOR(i, 1, n - 2){
		int cur = lft[i] + rgt[i + 1];
		if (cur < ret) ret = cur;
	}
	cout << ret ;
}
