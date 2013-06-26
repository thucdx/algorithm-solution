// Created : 5:05:22 AM ; Oct 15, 2012

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
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <sstream>
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
#define FILL(a, x, n) fill(a, a + n, x)
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4.0f * atan(1);  // double or double ?
const int INF = (int) 1E9 + 5;    // enough ?
const double EPS = 1E-7;        // enough ?
const ll MOD = (ll) 1E9 + 7;    // of problem ?

inline void solve();
double area(double xPos);

int N, L;
vector<double> x, y;
int main() {
	//freopen("input.txt", "r", stdin);
	int ntest;
	scanf("%d", &ntest);
	REP(i, ntest){
		solve();
	}
}

double area(double xPos){
	int i = 0;
	while (x[i + 1] < xPos) ++i;
	if (x[i + 1] >= xPos + L){
		double y1 = y[i] + (xPos - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
		double y2 = y[i] + (xPos + L - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);

		return fabs(y1 - y2) * L / 2.0;
	}

	double yPos = y[i] + (xPos - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
	double ylow = yPos;
	double ret = (y[i + 1] + yPos) * (x[i + 1] - xPos) / 2.0;

	++i;
	while (x[i + 1] < xPos + L){
		ylow = min(ylow, y[i]);
		ret += (x[i + 1] - x[i]) * (y[i + 1] + y[i]) / 2.0;
		++i;
	}

	ylow = min(ylow, y[i]);
	yPos = y[i] + (xPos + L - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
	ylow = min(ylow, yPos);
	ret += (xPos + L - x[i]) * (y[i] + yPos) / 2.0;

	return ret - ylow * L;

}


void solve(){
	scanf("%d %d", &N, &L);

	x.resize(N);
	y.resize(N);

	REP(i, N){
		scanf("%lf %lf", &x[i], &y[i]);
	}

	double ret = 1e9;

	FOR(i, 0, N - 2){
		FOR(j, i, N - 2){
			if (x[j] - x[i + 1] > L) continue;
			if (x[j + 1] - x[i] < L) continue;

			double lo = max(x[i], x[j] - L);
			double hi = min(x[i + 1], x[j + 1] - L);

			FOR(step, 1, 100){
				double one = (2 * lo + hi) / 3;
				double two = (lo + 2 * hi)  / 3;

				if (area(one) < area(two)){
					hi = two;
				}
				else lo = one;
			}

			double localMin = area(lo);
			if (ret > localMin) ret = localMin;
		}
	}

	printf("%.6lf\n", ret + 1e-9); // -0.0000000 & 0.0000000
}
