// [TIMXAD] ~ [DIVSEQQ] @ [Aug 30, 2013]
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

const int MAX = 100000;
ll sum[MAX + 5];
int head[MAX + 5], depth[MAX + 5], parent[MAX + 5], n, q, m;

inline ll getSum(int h, int t) {
	return sum[t] - (h ? sum[h - 1] : 0);
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	gi(n); gi(q); gi(m);
	int val, prv, d;
	ll s = 0;
	sum[0] = 0; depth[0] = 0; parent[0] = 0;

	FOR(i, 1, n) {
		gi(val); sum[i] = (s += val);
		prv = lower_bound(sum, sum + i + 1, s - m) - sum + 1;
		head[i] = prv;
		depth[i] = 1 + depth[prv - 1];
	}

	d = max(1, (int) sqrt(depth[n]));
	FOR(i, 1, n) {
		if (depth[i] <= d) parent[i] = 1;
		else {
			int pos = i;
			DOW(j, depth[i], depth[i] - d + 1)
				pos = head[pos] - 1;
			parent[i] = pos + 1;
		}
	}

	int u, v;
	REP(i, q) {
		gi(u); gi(v);
		if (v >= depth[u]) { printf("1\n"); continue; }

		int step = v / d, remain = v % d, pos = u;
		FOR(s, 1, step) pos = parent[pos] - 1;
		if (step && !remain) ++pos;

		FOR(s, 1, remain) pos = head[pos] - 1;
		if (remain) ++pos;

		printf("%d\n", pos);
	}
}
