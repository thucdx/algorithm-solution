// Created : 1:47:58 PM ; Oct 16, 2012

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

int h[205];
int c[205];
int maxRed, maxGreen;
int n;
int f[205][40005][2]; //0; last red, 1: last green;

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> maxRed >> maxGreen;

	c[0] = 0;
	h[0] = h[n + 1] = INF;

	REP(i, n){
		cin >> h[i + 1];
		c[i + 1] = c[i] + h[i + 1];
	}

	memset(f, -1 , sizeof(f));

	if (h[1] <= maxRed) f[1][h[1]][0] = 0;
	if (h[1] <= maxGreen) f[1][0][1] = 0;

	for (int x = 2; x <= n; x++){
		for (int red = 0; red <= maxRed; red++){
			int green =	c[x] - red;
			if (green < 0 || green >  maxGreen) continue;

			if (red >= h[x] && f[x-1][red- h[x]][0] != -1)
				f[x][red][0] = f[x - 1][red - h[x]][0];
			if (red >= h[x] && f[x - 1][red - h[x]][1] != -1){
				int news =  f[x - 1][red - h[x]][1] + min(h[x], h[x - 1]);
				if (f[x][red][0] == -1 ||( f[x][red][0] > news)) f[x][red][0] = news;
			}

			if (green >= h[x] && f[x - 1][red][1] != -1) f[x][red][1] = f[x - 1][red][1];
			if (green >= h[x] && f[x - 1][red][0] != -1){
				int news = f[x - 1][red][0] + min (h[x], h[x - 1]);
				if ((f[x][red][1] == -1 ) || (f[x][red][1] > news))	f[x][red][1] = news;
			}
		}
	}

	int ret = INF;
	for(int c = 0; c <= maxRed; c++){
		if (f[n][c][0] != -1 && f[n][c][0] < ret)	ret = f[n][c][0];
		if (f[n][c][1] != -1 && f[n][c][1] < ret)	ret = f[n][c][1];
	}

	if (ret == INF) ret = -1;
	cout << ret << endl;
}
