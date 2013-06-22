/*
* Who  : timxad
* Task : PALIN
* Date : May 30, 2013
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

char s[(int)1e6];
void solve() {
	int len = strlen(s);
	int middle = (len - 1) / 2;
	int i = (len - 1) / 2, j = len / 2;
	int compare = 0;
	for (; i >= 0 && j < len; i--, ++j) {
		if (s[i] > s[j]) {
			compare = 1;
			break;
		} else if (s[i] < s[j]) {
			compare = -1;
			break;
		}
	}

	if (compare == 1) {
//		cout << " KIDND 1" << endl;
		for (i = 0, j = len - 1; i <= j; i++, j--) {
			s[j] = s[i];
		}
		printf("%s\n", s);
	} else {
//		cout << "KIND 2" << endl;
		bool carryOut = true;
		int pos = middle;
		for (pos = middle; pos >= 0; --pos) {
			if (s[pos] != '9') {
				s[pos]++;
				carryOut = false;
				break;
			} else {
				s[pos] = '0';
			}
		}
		for (i = 0, j = len - 1; i <= j; ++i, --j) {
			s[j] = s[i];
		}
		if (!carryOut)
			printf("%s\n", s);
		else {
			printf("1");
			Rep(i, len - 1)
				printf("0");
			printf("1\n");
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif

	int ntest;
	scanf("%d", &ntest);
	Rep(i, ntest) {
		scanf("%s", s);
		solve();
	}
}


