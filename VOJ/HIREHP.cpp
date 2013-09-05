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
const int MAX = 5e5;
const ll INF = 1e16;
ll bit[MAX + 5];
int n;

inline ll get(int x) {
	ll rs = INF;
	for (; x <= n; x += x & -x) rs = min(rs, bit[x]);
	return rs;
}

inline void update(int x, ll val) {
	for(; x; x -= x & -x) bit[x] = min(bit[x], val);
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int t, p;
	gi(n);
	FOR(i, 1, n) bit[i] = INF;
	bit[0] = 0;
	FOR(i, 1, n) {
		gi(t), gi(p);
		ll x = p + (i == 1 ? 0 : get(i - 1));
		update(t, x);
	}

	cout << get(n) << endl;
}
