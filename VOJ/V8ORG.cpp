// [TIMXAD] ~ [V8ORG] @ [Aug 22, 2013]
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
const int MAX = 10000;
int k, n, result = 0;
bool vs[MAX + 5];
vector<int> children[MAX + 5];

int dfs(int v) {
	int size = 1; vs[v] = true;
	FIT(it, children[v]) if (!vs[*it]) size += dfs(*it);
	if (size >= k) ++result, size = 0;
	return size;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	scanf("%d", &k);
	scanf("%d", &n);
	int v;
	FOR(i, 2, n) {
		scanf("%d", &v);
		children[v].push_back(i);
	}

	result = 0; dfs(1);
	cout << result << endl;
}
