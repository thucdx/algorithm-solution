// [TIMXAD] ~ [BIC] @ [Sep 4, 2013]
#include <set>
#include <map>
#include <stack>
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
const int MAX = 10000;

vector<int> adj[MAX+ 5], adj2[MAX + 5];
int num[MAX + 5], low[MAX + 5], id, ncc;
bool isListed[MAX + 5];
bool vs[MAX + 5], same[MAX + 5];
stack<int> s;

void dfs(int ver) {
	num[ver] = low[ver] = ++id;
	s.push(ver);
	int cur;
	FIT(it, adj[ver]) {
		cur = *it;
		if (!isListed[cur]) {
			if (num[cur]) {
				low[ver] = min(low[ver], num[cur]);
			} else {
				dfs(cur);
				low[ver] = min(low[ver], low[cur]);
			}
		}
	}

	if (low[ver] == num[ver]) { // is Chot
		ncc++;
		do {
			cur = s.top(); s.pop();
			isListed[cur] = true;
		} while (cur != ver);
	}
}

void dfs2(int ver) {
	vs[ver] = true;
	FIT(it, adj2[ver]) {
		if (!vs[*it]) {
			dfs2(*it);
		}
	}
}

int cnt[MAX + 5];
const int MOD = (int) 1e9;
bool isGreater = false, isInf = false;
int count(int ver) {
	if (same[ver]) {
		isInf = true;
		return 0;
	}
	if (cnt[ver] != -1) return cnt[ver];
	int rs = 0;
	FIT(it, adj[ver]) {
		rs += count(*it);
		if (rs >= MOD) {
			isGreater = true;
			rs -= MOD;
		}
	}
	if (rs >= MOD) {
		isGreater = true;
		rs -= MOD;
	}
	return cnt[ver] = rs;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	REP(i, m) {
		scanf("%d %d", &u, &v);
		adj2[u].pb(v), adj2[v].pb(u);
		if (v != u)	adj[u].pb(v);
		else same[u] = true;
	}

	// lien thong
	dfs2(1);
	if (!vs[2]) {
		printf("0"); return 0;
	}

	int cntN = 0;
	FOR(i, 1, n) if (vs[i]) cntN++;

	ncc = id = 0;
	FOR(i, 1, n) {
		if (vs[i] && !num[i]) dfs(i);
	}

	if (ncc < cntN) { // ton tai cycle
		printf("inf\n");
	} else {
		memset(cnt, -1, sizeof(cnt));
		cnt[2] = 1;
		isGreater = false;
		int rs = count(1);
		if (isInf) { printf("inf"); return 0; }
		if (isGreater) printf("%09d", rs);
		else printf("%d", rs);
	}
}
