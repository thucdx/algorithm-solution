// Created : 12:53:28 AM ; Oct 15, 2012

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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const double PI = 4.0f * atan(1);  // double or long double ?
const int INF = (int) 1E9 + 5;    // enough ?
const double EPS = 1E-11;        // enough ?
const ll MOD = (ll) 1E9 + 7;    // of problem ?

inline void solve();
int N, F;
double V[10005];

bool isOk(double k);
int main() {
	//freopen("input.txt", "rt" ,stdin);
	int ntest;
	scanf("%d", &ntest);
	REP(i, ntest){
		solve();
	}

}


bool isOk(double k){
	int canServe = 0;

	REP(i, N){
		canServe += V[i] / k;
	}

	return canServe >= F + 1;
}

void solve(){
	scanf("%d %d", &N, &F);
	int r;
	REP(i, N){
		scanf("%d", &r);
		V[i] = PI * r * r;
	}
	double low = 0.0, hi = 10000 * 10000 * PI;

	while( hi - low >= 1e-7){
		double mid = (hi + low) / 2.0;

		if (isOk(mid)){
			low = mid;
		}
		else hi = mid;
	}

	printf("%.4lf\n", low);
}
