// [TIMXAD] ~ [HIREHP] @ [Sep 5, 2013]
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

const int MAX = (int) 5e5;
ll it[4 * MAX + 5];
const ll INF = 1e18;
int n;

void update(int node, int u, int v, int open, int end, ll val) {
	if (end < u || open > v) return;
	if (u == v) {
		it[node] = min(it[node], val);
		return;
	}

	int mid = (u + v) >> 1;
	update(node << 1, u, mid, open, end, val);
	update(1 + (node << 1), mid + 1, v, open, end, val);

	if (u >= open && v <= end) it[node] = min(it[node], val);
	else {
		it[node] = min(it[node << 1], it[1 + (node << 1)]);
	}
}

ll rs;
inline void get(int node, int u, int v, int position) {
	if (u == v && v == position) {
		rs = it[node];
		return;
	}

	int mid = (u + v) >> 1;
	if (mid >= position) get(node << 1, u, mid, position);
	if (mid + 1 <= position) get((node << 1) + 1, mid + 1, v, position);
}

inline ll get(int position) {
	if (position == 0) return 0;
	rs = INF;
	get(1, 1, n, position);
	return rs;
}

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

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int t, p;
	ll cost;
	FOR(i, 1, 4 * MAX) it[i] = INF;
	gi(n);
	FOR(i, 1, n) {
		gi(t); gi(p);
		cost = get(i - 1) + p;
		update(1, 1, n, i, t, cost);
	}

	cout << get(n) << endl;
}
