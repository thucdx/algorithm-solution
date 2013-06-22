/*
* Who  : timxad
* Task : PRIME1_2
* Date : Jun 2, 2013
* Desc :
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define Sort(a) sort(all(a))
#define Unique(a) Sort(a); a.resize(unique(all(a) - a.begin()))

#define For(i, a, b) for (int _b = (b), i = (a); i <= _b; ++i)
#define Ford(i, a, b) for (int _b = (b), i = (a); i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define Fit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define nl puts("") // new line
#define sp printf(" ") // space
#define ok puts("ok")
#define show(x) cout << x << endl
#define dbg(x) cout << #x << " = " << x << endl

typedef pair<int, int> II;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

const int INF		= (int) 1e9 + 5;
const ll INFL 		= (ll) 1e16 + 6;
const int MOD 		= (int) 1e9 + 7;
const double EPS 	= 1e-6;

bool isPrime[(int)1e5 + 5];

void solve(int n, int m) {
	// set isPrime[i] = false for every i = 0 .. (m - n + 1)
	memset(isPrime, true, (m - n + 1) * sizeof(bool));

	int r = sqrt(m);
	for (int i = 2; i <= r; ++i) {
		int j = (n/i)* i;
		while (j <= m) {
			if (j >= n && j > i) isPrime[j - n] = false;
			j += i;
		}
	}
	for (int i = max(n, 2); i <= m; ++i) {
		if (isPrime[i - n]) {
			printf("%d\n", i);
		}
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int ntest, n , m;
	scanf("%d", &ntest);
	for (int i = 0; i < ntest; ++i) {
		scanf("%d %d", &n, &m);
		solve(n, m);
	}
}


