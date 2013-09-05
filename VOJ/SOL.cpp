// [TIMXAD] ~ [SOL] @ [Sep 1, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "@OK!" << endl
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = (int) 1e5;
int it[MAX + 5], n, a[MAX + 5];

void update(int pos, int val) {
	for ( ;pos <= MAX; pos += pos & -pos)
		it[pos] = max(it[pos], val);
}

inline int get(int x) {
	int rs = 0;
	for (; x; x -= x & -x) rs = max(rs, it[x]);
	return rs;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d", &n);
	int val;
	FOR(i, 1, n) {
		scanf("%d", &val);
		int m = get(val - 1);
		update(val, m + 1);
	}
	cout << get(MAX + 1) << endl;
}
