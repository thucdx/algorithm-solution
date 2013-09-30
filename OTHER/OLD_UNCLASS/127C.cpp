// Created : 3:41:34 PM Oct 19, 2012
// Task    : 127C

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

const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-7;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?


int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
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

ll t1, t2, x1, x2, t0;
int dcmp(double a, double b){
	if (fabs(a - b) < EPS) return 0;
	if (a < b) return -1;
	return 1;
}

inline double temper(ll x, ll y){
	return ((double)x * t1 + y * t2) / (x + y);
}

inline void run() {
	cin >> t1 >> t2 >> x1 >> x2 >> t0;

	int bestX = -1, bestY = -1;
	double minDis = INF;

	// equal
	FOR(cold, 0, x1){
		int lowHot = 0, hiHot = x2;
		while (hiHot - lowHot > 1){

			int mid = (hiHot + lowHot) / 2;
			double cur = temper(cold, mid);
			if (dcmp(cur, t0) <= 0){
				lowHot = mid;
			}
			else hiHot = mid - 1;
		}

		if (dcmp(temper(cold, hiHot), t0) == 0){
			if (bestX + bestY < cold + hiHot){
				bestX = cold;
				bestY = hiHot;
				minDis = 0;
			}
		}
		else {
			if (dcmp(temper(cold, lowHot), t0) == 0){
				if (bestX + bestY < cold + lowHot){
					bestX = cold;
					bestY = lowHot;
					minDis = 0;
				}
			}
		}
	}

	if (bestX == -1){
		bestX = INF, bestY = INF;

		// cold = 0
		if (t2 >= t0){
			minDis = t2 - t0;
			bestX = 0;
			bestY = x2;
		}

		// hot = 0
		if (t1 >= t0 && (t1 - t0 <= minDis)){
			if (x1 > bestX + bestY){
				minDis = t1 - t0;
				bestX = x1;
				bestY = 0;
			}
		}

		FOR(cold, 1, x1){
			int lowHot = 1, hiHot = x2;
			while (hiHot - lowHot > 1){
				int mid = (hiHot + lowHot) / 2;
				double cur = temper(cold, mid);
				if (dcmp(cur, t0) < 0){
					lowHot = mid;
				}
				else {
					hiHot = mid;
				}
			}
			double tempLowHot = temper(cold, lowHot);
			if (tempLowHot > t0 && dcmp(tempLowHot - t0, minDis) <= 0){
				minDis = tempLowHot - t0;
				bestX = cold;
				bestY = lowHot;
			}
			else {
				double tempHiHot = temper(cold, hiHot);
				if (tempHiHot > t0 && dcmp(tempHiHot - t0, minDis) <= 0){
					minDis = tempHiHot - t0;
					bestX = cold;
					bestY = hiHot;
				}
			}
		}
	}

	//greater
	cout << bestX << " " << bestY << endl;
}
