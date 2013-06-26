/*
* TIMXAD
* Date : Apr 28, 2013, 1:46:39 AM
* Task : 298B
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

int t, sx, sy, ex, ey;
char direction[(int)1e5 + 5];

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	cin >> t >> sx >> sy >> ex >> ey;
	scanf("%s", direction);
	int difX = ex - sx, difY = ey - sy;
	char dir1, dir2;
	dir1 = difX < 0 ? 'W' : 'E';
	dir2 = difY < 0 ? 'S' : 'N';
	if (difX < 0) difX = -difX;
	if (difY < 0) difY = -difY;

	int x = 0, y = 0;
	REP(i, strlen(direction)) {
		char cur = direction[i];
		if (cur == dir1) x++;
		if (cur == dir2) y++;
		if (x >= difX && y >= difY) {
			cout << (i + 1);
			return 0;
		}
	}
	cout << -1;
	return 0;
}
