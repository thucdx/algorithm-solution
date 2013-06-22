/*
* Who  : timxad
* Task : FQUEEN
* Date : Jun 13, 2013
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

int n;
int pos[15];
bool hieu[30], col[15], sum[30];

void go(int row) {
	if (row > n) {
		For(i, 1, n) printf("%d ", pos[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i) {
		bool& r = hieu[i - row + 10];
		bool& l = sum[i + row];

		if (!col[i] && !r & !l) {
			pos[row] = i;
			col[i] = true;
			l = true;
			r = true;

			go(row + 1);

			col[i] = false;
			l = false;
			r = false;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	memset(hieu, false, sizeof(false));
	memset(col, false, sizeof(false));
	memset(sum, false, sizeof(false));
	go(1);
}


