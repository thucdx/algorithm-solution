/*
* Who  : timxad
* Task : CUBEFR
* Date : Jun 8, 2013
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

const int MAX = (int) 1e6;
bool notCubeFree[MAX + 5];
int id[MAX + 5];

void init() {
	for (int i = 2; i <= 100; ++i) {
		int j = i * i * i;
		int val = j;
		while (val <= MAX) {
			notCubeFree[val] = true;
			val += j;
		}
	}

	id[1] = 1;
	for (int i = 2; i <= MAX; ++i) {
		id[i] = id[i - 1] + (notCubeFree[i] ? 0 : 1);
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	init();
	int ntest, n;
	scanf("%d", &ntest);
	for (int i = 1; i <= ntest; ++i) {
		scanf("%d", &n);
		if (!notCubeFree[n]) {
			printf("Case %d: %d\n", i, id[n]);
		} else {
			printf("Case %d: Not Cube Free\n", i);
		}
	}

}


