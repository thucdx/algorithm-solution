// [TIMXAD] ~ [VCOLDWAT] @ [Aug 22, 2013]
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
const int MAX = (int) 1e5;
int child[MAX + 5][2], rs[MAX + 5], n, c;
bool isRoot[MAX + 5];

void dfs(int ver, int d) {
	rs[ver] = d;
	if (child[ver][0] != 0) {
		dfs(child[ver][0], d + 1);
		dfs(child[ver][1], d + 1);
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d %d", &n, &c);
	int e, b1, b2;
	memset(isRoot, true, sizeof(isRoot));
	FOR(i, 1, c) {
		scanf("%d %d %d", &e, &b1, &b2);
		child[e][0] = b1, child[e][1] = b2;
		isRoot[b1] = isRoot[b2] = false;
	}

	FOR(i, 1, n) {
		if (isRoot[i]) {
			dfs(i, 1);
			break;
		}
	}

	FOR(i, 1, n) {
		printf("%d\n", rs[i]);
	}
}
