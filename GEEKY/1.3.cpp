#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?

const int MAX = 1200;
int n;
int total;
bool bs[30][MAX + 5][MAX + 5];
int bestX = -1, bestY = -1, bestSize = 0;

void rotate(int i);
void go(int n);
inline int check(int &, int &);
inline int checkCur(int k);
int findLargest(int &X, int &Y); // matrix
bool tmp[MAX + 5][MAX + 5];
int d[MAX + 5][MAX + 5], all[MAX + 5][MAX + 5];
bool isSquareAllOne(int i, int j, int size);
int getTotalOne(int i, int j, int size);

int main() {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif

	scanf("%d", &n);
	int num;
	total = 0;
	while (scanf("%d", &num) != EOF) {
		bs[total][0][0] = (num == 1);
		FOR (i, 0, n - 1) {
			FOR (j, 0, n - 1) {
				if (i + j == 0) continue;
				scanf("%d", &num);
				bs[total][i][j] = (num == 1);
			}
		}
		total++;
	}
	go (1);
	cout << bestX << " " << bestY << " " << bestSize << endl;
}

void rotate(int k) { // clockwise
	bool tmp[MAX][MAX];
	FOR(i, 0, n - 1) {
		FOR(j, 0, n - 1) {
			tmp[i][j] = bs[k][n - 1 - j][i];
		}
	}
	FOR(i, 0, n - 1) {
		FOR(j, 0, n - 1) {
			bs[k][i][j] = tmp[i][j];
		}
	}
}

void go(int k ){
	if (k >= total) {
		int X, Y;
		int curMax = check(X, Y);
		if (curMax > bestSize) {
			bestX = X;
			bestY = Y;
			bestSize = curMax;
		}
		return;
	}

	FOR(i, 0, 3) {
		rotate(k);
		if (checkCur(k) > bestSize)
			go(k + 1);
	}
}

int checkCur(int t) {
	FOR(i, 0, n - 1) tmp[i][0] = tmp[0][i] = 0;
	FOR(i, 1, n)  FOR(j, 1, n) tmp[i][j] = 1;

	FOR(k, 0, t) {
		FOR(i, 0, n - 1) {
			FOR(j, 0, n - 1) {
				tmp[1 + i][1 + j] &= bs[k][i][j];
			}
		}
	}
	int tx, ty;
	return findLargest (tx, ty);
}

int check(int& X, int& Y) {
	FOR(i, 0, n - 1) tmp[i][0] = tmp[0][i] = 0;
	FOR(i, 1, n)  FOR(j, 1, n) tmp[i][j] = 1;

	FOR(k, 0, total - 1) {
		FOR(i, 0, n - 1) {
			FOR(j, 0, n - 1) {
				tmp[1 + i][1 + j] &= bs[k][i][j];
			}
		}
	}
	return findLargest (X, Y);
}

int findLargest(int &X, int &Y) {
	FOR(i, 0, n) FOR(j, 0, n) d[i][j] = all[i][j] = 0;
	FOR(j, 1, n) FOR(i, 1, n) {
		d[i][j] = d[i - 1][j] + tmp[i][j];
	}

	FOR(i, 1, n) FOR(j, 1, n) {
		all[i][j] = all[i][j - 1] + d[i][j];
	}

	int bestSize = 0;
	FOR(i, 1, n) FOR(j, 1, n) {
		int low = 1, hi = min (n + 1 - i, n + 1 - j);
		while (low < hi - 1) {
			int mid = (low + hi) / 2;
			if (isSquareAllOne(i, j, mid)) {
				low = mid;
			} else hi = mid - 1;
		}

		int curSize = low;
		if (isSquareAllOne(i, j, hi)) {
			curSize = hi;
		}

		if (curSize > bestSize) {
			bestSize = curSize;
			X = i - 1;
			Y = j - 1;
		}
	}
	return bestSize;
}

bool isSquareAllOne(int i, int j, int size) {
	if (i + size > n + 1 || j + size > n + 1 || size < 1) return false;
	return getTotalOne(i, j, size) == size * size;
}

int getTotalOne(int x, int y, int size) {
	return all[x + size - 1][y + size - 1] - all[x-1][y + size - 1]
		  - all[x + size - 1][y - 1] + all[x-1][y - 1];
}

