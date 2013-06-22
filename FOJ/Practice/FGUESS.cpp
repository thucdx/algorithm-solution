/*
* Who  : timxad
* Task : GUESS_solve
* Date : Jun 3, 2013
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

int main() {
#ifdef LOCAL
	freopen("./IO/GUESS/input5.txt", "rt", stdin);
	freopen("./IO/GUESS/output5.txt", "wt", stdout);
#endif

	int ntest;
	const int STEP = 100000;
	scanf("%d", &ntest);
	double x;

	Rep(i, ntest) {
		scanf("%lf", &x);
		x += 1e-9;
		int k = x * 1000;
		if (k == STEP || k == 0) {
			puts("1");
			continue;
		}

		int res = INF;
		bool found = false;

		int min = 0, max = 0;
		int kp = k+5, km = k -5;
		for (int m = 1; m <= 1000; ++m) {
			if (found) break;
			max += kp;
			min += km;
			int r = min % STEP;
			if (r == 0) {
				res = m;
				found = true;
			} else {
				if (min + STEP - r < max) {
					res = m;
					found = true;
				}
			}
		}
		printf("%d\n", res);
	}

}


