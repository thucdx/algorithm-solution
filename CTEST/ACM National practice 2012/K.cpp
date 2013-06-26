// Created : 9:57:17 AM Oct 23, 2012
// Task    : K

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

#define DEBUG(x) cout << #x << " = "; cout << x << endl; // thank RR for that
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;

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

const int PSIZE = 1e5;

int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

int k, w;
int father[2 * PSIZE + 5];
int cntWish[2 * PSIZE + 5];
int nxt[2 * PSIZE + 5][2];
bool vs[2 * PSIZE+ 5];


vector< pair<int, int> > wishes;
map<int, int> m;
set<int> numbers;

int getRoot(int x){
	return x == father[x] ? x : father[x] = getRoot(father[x]);
}

bool unite(int x, int y){
	x = getRoot(x);
	y = getRoot(y);

	if (x == y) return false;
	father[x] = y;
	return true;
}

inline void init() {
	ntest = INF;
}

inline void solve(){
	m.clear(); numbers.clear();

	REP(i, SZ(wishes)){
		numbers.insert(wishes[i].F);
		numbers.insert(wishes[i].S);
	}

	UNIQUE(wishes);
	int cnt = 0;
	int total = SZ(numbers);

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
		m[*it] = cnt++;
	}

	//bool isOk = true;

	REP(i, SZ(wishes)){
		pair<int, int> cur = wishes[i];
		int first = m[cur.F];
		int second = m[cur.S];

		cntWish[first]++; cntWish[second]++;

		if (cntWish[first] > 2 || cntWish[second] > 2){
			printf("N\n");
			return;
		}

		REP(j, 2){
			if (nxt[first][j] == -1){
				nxt[first][j] = second;
				break;
			}
		}

		REP(j, 2){
			if (nxt[second][j] == -1){
				nxt[second][j] = first;
				break;
			}
		}
	}

	if (total == k){
		//Check xem co chu trinh do dai k ko ?
		int cntVer = 0;
		int i = 0;
		while (!vs[i]){
			cntVer ++;
			vs[i] = true;
			bool found = false;
			REP(j, 2){
				if (nxt[i][j] != -1){
					if (!vs[nxt[i][j]]){
						i = nxt[i][j];
						found = true;
						break;
					}
				}
			}
			if (!found) break;
		}

		if (cntVer == k){
			printf("Y\n");
			return;
		}
	}

	REP(i, total){
		father[i] = i;
	}

	REP(i, SZ(wishes)){
		pair<int, int> cur = wishes[i];
		int first = m[cur.F];
		int second = m[cur.S];

		if (!unite(first, second)){
			printf("N\n");
			return;
		}
	}

	printf("Y\n");
}

inline void run() {
	scanf("%d %d", &k, &w);
	if (k == 0) return stop();

	wishes.clear();
	memset(cntWish, 0, sizeof(cntWish));
	REP(i, 2 * PSIZE + 5){
		nxt[i][0] = nxt[i][1] = -1;
	}
	memset(vs, false, sizeof(vs));

	int a, b;
	REP(i, w){
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		wishes.PB(MP(a, b));
	}

	solve();
}

