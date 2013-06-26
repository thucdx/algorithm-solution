/* TIMXAD
* Task : 299B
* Desc : 
*/
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

string road;
int n, k;

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &k);
		cin >> road;
		int last = -1;
		bool isOK = true;
		REP(i, road.length()) {
			if (road[i] == '.') {
				if (last != -1 && (i - last) > k) {
					isOK = false;
					break;
				}
				last = i;
			}
		}
		isOK &= (road[0] == '.' && road[road.length() - 1] == '.');
		puts(isOK ? "YES" : "NO");
	}
}
