/*
* Who  : timxad
* Task : COINS
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
const int BASE = (int) 1e5;

int f[BASE + 5];

inline ll getMax(int n) {
	if (n <= BASE) return f[n];
	ll val = getMax(n >> 1) + getMax(n/3) + getMax(n >> 2);
	return max(val, (ll)n);
}

void init() {
	For(i, 0, 4) f[i] = i;
	For(i, 5, BASE) {
		int val = f[i >> 1] + f[i/3] + f[i >> 2];
		if (val < i) val = i;
		f[i] = val;
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int n;
	init();
//	time_t start, end;
//	start = clock();
	while (	scanf("%d", &n) != EOF){
		printf("%lld\n", getMax(n));
	}
//	end = clock();
//	printf("%.2lf\n", (double)(end- start) / CLOCKS_PER_SEC);
}






