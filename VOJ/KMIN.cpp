/*
* Who  : timxad
* Task : MINK
* Date : Jun 9, 2013
* Desc :
*/
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <queue>
#include <deque>
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

int n, k;
int a[17005];
deque<int> dq;

void push(int x) {
	while (!dq.empty() && a[dq.back()] >= a[x])
		dq.pop_back();
	dq.push_back(x);
}

void pop(int x) {
	while (!dq.empty() && dq.front() <= x)
		dq.pop_front();
}

void solve() {
	dq.clear();
	for (int i = 1; i <= k; ++i) push(i);
	printf("%d", a[dq.front()]);
	for (int j = k + 1; j <= n; ++j) {
		pop(j - k);	push(j);
		printf(" %d", a[dq.front()]);
	}

	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int ntest;
	scanf("%d", &ntest);
	Rep(i, ntest) {
		scanf("%d %d", &n, &k);
		For(j, 1, n) scanf("%d", &a[j]);
		solve();
	}
}

