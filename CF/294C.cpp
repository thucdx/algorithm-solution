/*
* TIMXAD
* Date : Apr 11, 2013, 9:41:01 PM
* Task : A.cpp
* Desc : http://codeforces.com/problemset/problem/294/C
*/
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; i++)
#define FORD(i, a, b) for (int _a = (a), _b = (b), i = _a; i >= _b; i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SORT(v) sort(ALL(v))
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))

#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())
#define SHOW(v) cout << #v << " = " << v << endl;
#define SHOWARR(arr, begin, end) FOR(i, begin, end) cout << a[i
#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
const int MOD = (int) (1e9 + 7);

int pow2[1005];
int c[1005][1005];
int n, m;
vector<int> pos;

void init();

int main() {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
	init();
	cin >> n >> m;
	int p;
	FOR(i, 1, m) {
		scanf("%d", &p);
		pos.PB(p);
	}

	SORT(pos);
	int last = 0;
	ll ans = 1;
	int j;
	n -= m;
	for (int i = 0; i < pos.size(); ++i) {
		int first ;
		first = 1;
		if (last != 0) {
			int diff = pos[i] - last - 2;
			if (diff > 0) first = pow2[diff];
		}
		ans = (ans * first) % MOD;
		ans = (ans * c[pos[i] - last - 1][n]) % MOD;
		n -= pos[i] - last - 1;
		last = pos[i];
	}

	cout << ans << endl;
}

void init() {
	pow2[0] = 1;
	FOR(i, 1, 1000) pow2[i] = (2 * pow2[i - 1]) % MOD;
	FOR(i, 0, 1000) c[0][i] = 1;
	FOR(i, 1, 1000) {
		FOR(j, 1, i) {
			c[j][i] = (c[j - 1] [i - 1] + c[j][i - 1]) % MOD;
		}
	}
}
