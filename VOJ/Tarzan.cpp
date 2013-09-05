// [TIMXAD] ~ [Tarzan] @ [Aug 8, 2013]
#include <set>
#include <stack>
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

const int MAX = 10000;

vector<int> adj[MAX+ 5];
int num[MAX + 5], low[MAX + 5], id, ncc;
bool isListed[MAX + 5];
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


int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	REP(i, m) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
	}

	ncc = id = 0;
	FOR(i, 1, n) {
		if (!num[i]) dfs(i);
	}

	cout << ncc;
}
