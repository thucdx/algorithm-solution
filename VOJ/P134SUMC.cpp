// [TIMXAD] ~ [P134SUMC] @ [Aug 6, 2013]
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX_V = 20000;
vi adj[MAX_V + 5];
int n, m, num[MAX_V + 5], low[MAX_V + 5], moreCC[MAX_V + 5], id;
// moreCC[i] is number of connected components if remove i vertex

inline void vs(int v) {
	id++;
	num[v] = low[v] = id;

	FIT (it, adj[v]) {
		int cur = *it;
		if (num[cur] > 0) {
			low[v] = min(low[v], num[cur]);
		} else {
			vs(cur);
			low[v] = min(low[v], low[cur]);
			if (low[cur] >= num[v]) moreCC[v]++;  // v is articulation
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	int u, v;
	REP(i, m) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v); adj[v].pb(u);
	}

	id = 0;
	int cc = 0; // connected components
	FOR(i, 1, n) {
		if (num[i] == 0) {
			cc++;
			vs(i);
			--moreCC[i];
		}
	}

	FOR(i, 1, n) printf("%d\n", cc + moreCC[i]);
}
