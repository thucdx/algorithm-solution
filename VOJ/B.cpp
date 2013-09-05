// [TIMXAD] ~ [B] @ [Aug 21, 2013]
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

char imp[] = "IMPOSSIBLE", amb[] = "AMBIGUOUS";

ll pow(ll n, int mu) {
	ll rs = 1;
	for (; mu; mu >>= 1) {
		if (mu & 1) rs = rs * n;
		n = n * n;
	}
	return rs;
}

void solve(int k, int t) {
	if (t < 0 || k < 0) {
		printf("%s\n", imp);
		return;
	}

	if (k == 0) {
		if (t == 0) printf("0\n");
		else printf("%s\n", imp);
		return;
	}

	if (k == 1) {
		if (t == 1) {
			printf("%s\n", amb);
		} else {
			printf("%s\n", imp);
		}
		return;
	}

	if (t < k || (t - k) % (k - 1) != 0) {
		printf("%s\n", imp);
		return;
	}

	int _t = t;
	int nDig = 0, dig[100], sum = 0;
	do {
		dig[nDig] = t % k;
		sum += dig[nDig];
		++nDig;
		t /= k;
	} while (t != 0);

	if (sum != k) {
		printf("%s\n", imp);
		return;
	}

	int mu = log(_t) / log(k) + 1e-6;
	if (pow((ll)k, mu) == t) {
		printf("%s\n", amb);
		return;
	}

	DOW(i, nDig - 1, 0) {
		printf("%d", dig[i]);
		if (i != 0) printf(" ");
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int ntest, k, t;
	scanf("%d", &ntest);

	while (ntest--) {
		scanf("%d %d", &k, &t);
		solve(k, t);
	}
	
}
