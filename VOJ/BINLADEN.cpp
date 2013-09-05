// [TIMXAD] ~ [A] @ [Aug 27, 2013]
#include <set>
#include <map>
#include <queue>
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
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = (int)5e6;

vector<pair<int, int> > adj[25000];
priority_queue<pair<int, int> > q;
int dist[25000];
int n, m;

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d %d", &m, &n);

	// 0 -> m * n
	int dis, curV = 0, prv;
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			scanf("%d", &dis);
			curV = (i - 1) * n + j;
			prv = max(curV - n, 0);
			adj[prv].pb(ii(curV, dis));
			adj[curV].pb(ii(prv, dis));
		}

		FOR(j, 1, n - 1) {
			scanf("%d", &dis);
			curV = (i - 1) * n + j;
			adj[curV].pb(ii(curV + 1, dis));
			adj[curV + 1].pb(ii(curV, dis));
		}
	}

	q.push(make_pair(0, 0));
	int destination = m * n;
	FOR(i, 1, destination) dist[i] = INF;
	dist[0] = 0;
	pair<int, int> top;
	while (!q.empty()) {
		top = q.top(); q.pop();
		dist[top.second] = -top.first;
		if (top.second == destination) {
			cout << -top.first << endl; break;
		}

		FIT(it, adj[top.second]) {
			if (dist[it->first] > -top.first + it->second)
				q.push(make_pair(top.first - it->second, it->first));
		}
	}
}
