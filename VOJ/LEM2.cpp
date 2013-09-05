// [TIMXAD] ~ [LEM2] @ [Aug 27, 2013]
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
const int INF = (int) 1e6;
int n, k, f[20];
bool vs[(1 << 20) - 1];
queue<pair<int, int> > q;

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d %d", &n, &k);
	int val = 0, total;
	REP(i, n) {
		scanf("%d", &total);
		f[i] = (1 << n) - 1;
		REP(j, total) {
			scanf("%d", &val);
			f[i] ^= 1 << --val;
		}
	}

	int init = 0;
	REP(i, n) {
		scanf("%d", &val);
		if (val) init |= 1 << i;
	}

	int destination = 1 << (k - 1), rs = -1, curState, newState;
	q.push(make_pair(init, 0));
	pair<int, int> top;
	vs[init] = true;

	while (!q.empty()) {
		top = q.front(); q.pop();
		curState = top.fi;
		if (curState == destination) { rs = top.se; break; }

		REP(i, n) {
			newState = (curState & f[i]) | (1 << i);
			if (!vs[newState]) {
				q.push(make_pair(newState, top.se + 1));
				vs[newState] = true;
			}
		}
	}

	cout << rs << endl;
}
