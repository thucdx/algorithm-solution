// [TIMXAD] ~ [MMMGAME] @ [Aug 16, 2013]
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

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	int ntest, n, a[500];
	string second = "Brother", first = "John";
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d", &n);
		int nPileGreaterThanOne = 0;
		int nimSum = 0;
		FOR(i, 1, n) {
			scanf("%d", &a[i]);
			nimSum ^= a[i];
			nPileGreaterThanOne += a[i] > 1;
		}

		if (nPileGreaterThanOne > 0) {
			cout << (nimSum == 0 ? second : first) << endl;
		} else {
			cout << (n % 2 == 0 ? first : second) << endl;
		}
	}
}
