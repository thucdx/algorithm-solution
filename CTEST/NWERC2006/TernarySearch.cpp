// Created : 4:12:35 AM ; Oct 15, 2012

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

int n;
vector<int> v;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	int val;
	REP(i, n){
		cin >> val;
		v.PB(val);
	}

	int lo = 0, hi = 9;
	while (hi - lo > 2){
		int oneThird = (lo * 2 + hi) / 3;
		int twoThird = (lo + hi * 2) / 3;

		if (v[oneThird] < v[twoThird]){
			lo = oneThird;
		}
		else hi = twoThird;
		cout << lo << " " << hi << endl;
	}

	int max = v[lo], id = lo;

	FOR(i, lo + 1, hi){
		if (v[i] > max){
			max = v[i];
			id = i;
		}
	}

	cout << id << " " << max << endl;
}
