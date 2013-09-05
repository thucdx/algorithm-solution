// [TIMXAD] ~ [E] @ [Aug 21, 2013]
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "@OK!" << endl
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int EPS = 1e-6;

inline bool equal(double a, double b) {
	return fabs(a - b) < EPS;
}

inline int cmp(double a, double b) {
	if (fabs(a - b) < EPS)
		return 0;
	if (a > b)
		return 1;
	return -1;
}

inline double area(int a, int b, int c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

inline bool isTriangle(int a, int b, int c) {
	return (a + b > c && c + a > b && b + c > a);
}

double determinant(double b[5][5], int m) {
	int i, j;
	double sum = 0, c[5][5];
	if (m == 2) {                                        //BASE CONDITION
		sum = b[0][0] * b[1][1] - b[0][1] * b[1][0];
		return sum;
	}
	for (int p = 0; p < m; p++) {
		int h = 0, k = 0;
		for (i = 1; i < m; i++) {
			for (j = 0; j < m; j++) {
				if (j == p)
					continue;
				c[h][k] = b[i][j];
				k++;
				if (k == m - 1) {
					h++;
					k = 0;
				}

			}
		}

		sum = sum + b[0][p] * pow(-1, p) * determinant(c, m - 1);
	}
	return sum;
}

int main() {
#ifdef LOCAL
	freopen("./IO/input", "r", stdin);
#endif
	vector<int> sides;
	int ntest;
	scanf("%d", &ntest);

	int s;
	double d[5][5];

	while (ntest--) {
		sides.clear();
		REP(i, 6)
		{
			scanf("%d", &s);
			sides.push_back(s);
		}

		sort(sides.begin(), sides.end());
		bool isOk = false;
		int lastSides = -1;
		do {
			isOk = isTriangle(sides[0], sides[1], sides[2]);
			if (!isOk)
				continue;
			if (sides[2] == lastSides) {
				isOk = false;
				continue;
			}
			lastSides = sides[2];
			double a = sides[0], b = sides[1], c = sides[2];
			double ax = sides[3], bx = sides[4], cx = sides[5];

			for (int i = 1; i < 5; ++i)
				d[0][i] = d[i][0] = 1;
			REP(i, 5) d[i][i] = 0;
			d[1][2] = d[2][1] = c * c;
			d[1][3] = d[3][1] = b * b;
			d[1][4] = d[4][1] = ax * ax;
			d[2][3] = d[3][2] = a * a;
			d[2][4] = d[4][2] = bx * bx;
			d[3][4] = d[4][3] = cx * cx;

			double det = determinant(d, 5);
			if (cmp(det, 0) > 0) {
				isOk = true;
				break;
			} else
				isOk = false;
		} while (next_permutation(sides.begin(), sides.end()));

		puts(isOk ? "YES" : "NO");
	}
}
