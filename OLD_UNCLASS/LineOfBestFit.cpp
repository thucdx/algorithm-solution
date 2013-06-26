// Created : 7:53:25 PM Oct 18, 2012
// Task    : LineOfBestFit

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

#define FOR(i, a, b) for (typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) for (typeof(a) i = (a); i >= (b); i--)
#define REP(i, a) for (typeof(a) i = 0; i < (a); i++)
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

const double PI = 4 * atan(1);   // d / ld ?
const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?


int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}
struct Point{
	double x, y;
	Point(double _x = 0, double _y = 0){
		x = _x;
		y = _y;
	}
};

Point p[1005];
int n;

double sqr(double x){
	return x * x;
}

inline double calc(double a, double b){
	double ret = 0;
	REP(i, n){
		ret += sqr(p[i].y - p[i].x * a - b);
	}
	return ret;
}

double findMin(double a){  // findB calc(a,x) min
	double lowB = -(1e6), hiB = 1e6;
	while (hiB - lowB > 1e-6){
		double first = (lowB * 2 + hiB ) / 3;
		double second = (lowB + 2 * hiB) / 3;

		if (calc(a, first) >= calc(a, second)){
			lowB = first;
		}
		else hiB = second;
	}
	return lowB;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

inline void init() {
	ntest = 1;
}

inline void run() {
	scanf("%d",&n);
	double x, y;
	REP(i, n){
		scanf("%lf %lf", &x, &y);
		p[i] = Point(x, y);
	}

	double lowA = - (1e6), hiA = 1e6;
	while (hiA - lowA > 1e-6){
		double oneThirdA = (lowA * 2 + hiA) / 3;
		double twoThirdA = (lowA + hiA * 2) / 3;

		double minOneThirdA = calc(oneThirdA, findMin(oneThirdA));
		double minTwoThirdA = calc(twoThirdA, findMin(twoThirdA));

		if (minOneThirdA <= minTwoThirdA){
			hiA = twoThirdA;
		}
		else{
			lowA = oneThirdA;
		}
	}

	printf("%.3lf\n%.3lf", hiA + 1e-5, findMin(hiA) + 1e-5);
}
