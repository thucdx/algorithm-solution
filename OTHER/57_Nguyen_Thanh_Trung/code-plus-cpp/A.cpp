#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
#ifdef LOCAL
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stderr);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

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
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const double EPS = 1E-11;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	ntest = 1;
}

const int MAX_WIDTH = 10;
const int MAX_HEIGHT = 10;
const int STEP = 1 << 20;

const int WIDTH = 5;
const int HEIGHT = 5;
const int SIZE = WIDTH * HEIGHT;

typedef bool table[MAX_WIDTH][MAX_HEIGHT];

string s;
int a, b, x, y;
vector<pii> affectedTo[MAX_WIDTH][MAX_HEIGHT];
table initial, state;

inline void normalize(string &s) {
	FIT(it, s) {
		if (!isdigit(*it)) {
			*it = ' ';
		}
	}
}

inline void copy(table &dst, table &src) {
	FOR(i, 1, WIDTH) {
		FOR(j, 1, HEIGHT) {
			dst[i][j] = src[i][j];
		}
	}
}

inline void toggle(table &a, int r, int c) {
	a[r][c] ^= true;
	FIT(it, affectedTo[r][c]) {
		a[it->F][it->S] ^= true;
	}
}

inline bool allOff(table &a) {
	FOR(i, 1, WIDTH) {
		FOR(j, 1, HEIGHT) {
			if (a[i][j]) {
				return false;
			}
		}
	}
	return true;
}

inline void run() {
	SET(initial, false);
	{
		getline(cin, s);
		normalize(s);
		istringstream iss(s);
		while (iss >> x >> y) {
			initial[x][y] = true;
		}
	}

	while (getline(cin, s)) {
		normalize(s);
		istringstream iss(s);
		iss >> a >> b;
		while (iss >> x >> y) {
			affectedTo[a][b].PB(MP(x, y));
		}
	}

	puts("Checking states...");

	int maskBound = 1 << SIZE;
	int numSolution = 0;
	REP(mask, maskBound) {
		if (mask % STEP == 0 && mask != 0) {
			printf("[%.2f%%] %d / %d\n", 100.0 * (mask + 1) / (maskBound + 1),
					mask + 1, maskBound + 1);
			fflush(stdout);
		}
		copy(state, initial);
		REP(i, SIZE) {
			if (mask & (1 << i)) { // the i-th bit is ON
				int r = i / WIDTH + 1;
				int c = i % WIDTH + 1;
				toggle(state, r, c);
			}
		}
		if (allOff(state)) {
			fprintf(stderr, "Solution %d: [", ++numSolution);
			bool first = true;
			REP(i, SIZE) {
				if (mask & (1 << i)) { // the i-th bit is ON
					int r = i / WIDTH + 1;
					int c = i % WIDTH + 1;
					if (first) {
						first ^= true;
					} else {
						fprintf(stderr, ",");
					}
					fprintf(stderr, "(%d,%d)", r, c);
				}
			}
			fprintf(stderr, "]\n");

			printf("Found %d solution(s) so far\n", numSolution);
			fflush(stdout);
		}
	}
	printf("[%.2f%%] %d / %d\n", 100.0, maskBound + 1, maskBound + 1);
	puts("Finished checking states!");
}
