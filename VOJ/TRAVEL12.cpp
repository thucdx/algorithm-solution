// [TIMXAD] ~ [TRAVEL12] @ [Sep 3, 2013]
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

const int MAX = 10000;

set<pair<short, short> > s;
vector<short> adj[MAX + 5];

//Fast input
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}
//End of fast input

int prv[MAX + 5];
bool isOk(int v) {
	memset(prv, 0, sizeof(prv));
	FIT(it, adj[v]) {
		int u = *it;
		FIT(it, adj[u]) {
			int l = *it;
			if (l != v) {
				if (!prv[l]) {
					prv[l] = u;
				} else {
					printf("%d %d %d %d", v, u, l, prv[l]);
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int n, m, u, v;
	gi(n), gi(m);
	REP(i, m) {
		gi(u), gi(v);
		if (u > v) swap(u, v);
		s.insert(make_pair(u, v));
	}
	FIT(it, s) {
		adj[it->first].push_back(it->second);
		adj[it->second].push_back(it->first);
	}

	FOR(x, 1, n) {
		if (isOk(x)) return 0;
	}
	cout << -1 << endl;
}
