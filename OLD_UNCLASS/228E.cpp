// Created : 3:39:57 AM ; Oct 16, 2012

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

const int PSIZE = 1e6;

bool visit[PSIZE + 5];
bool needSwitch[PSIZE + 5];

bool found;
vector<int> adj[PSIZE];
vector<bool> state[PSIZE];
int n, m;

void unvisit(int vertice){
	if (!visit[vertice]) return;
	visit[vertice] = false;
	REP(i, SZ(adj[vertice])){
		int nxt = adj[vertice][i];
		unvisit(nxt);
	}
}

void dfs(int vertice, bool isSwitchOn){
	//cout << "dfs " << vertice << " " << isSwitchOn << endl;
	if (!found) return;

	if (visit[vertice]){
		if (needSwitch[vertice] != isSwitchOn){
			found = false;
		}
		return;
	}

	visit[vertice] = true;
	needSwitch[vertice] = isSwitchOn;

	REP(i, SZ(adj[vertice])){
		int nxt = adj[vertice][i];
		bool isNxtOn = state[vertice][i];

		if (isNxtOn){
			dfs(nxt, isSwitchOn);
		}
		else dfs(nxt, !isSwitchOn);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);

	int u, v, c;
	bool already = true;
	REP(i, m){
		scanf("%d %d %d", &u, &v, &c);
		if (c != 1) already = false;

		adj[u].PB(v);
		state[u].PB(c == 1);
		adj[v].PB(u);
		state[v].PB(c == 1);
	}

	if (already ) {
		cout << "0";
		return 0;
	}

	found = true;
	memset(visit, false, sizeof(visit));
	memset(needSwitch , false, sizeof(needSwitch));

	FOR(i, 1, n){
		if (!found) break;

		if (!visit[i]){
			dfs(i, 1);
			if (!found) {
				unvisit(i);
				dfs(i, 0);
			}
			if (!found) break;
		}
	}

	if (found){
		int nSwitch = 0;
		FOR(i, 1, n){
			nSwitch += needSwitch[i];
		}

		printf("%d\n", nSwitch);
		FOR(i, 1, n){
			if (needSwitch[i]){
				printf("%d ", i);
			}
		}
		return 0;
	}
	else cout << "Impossible";

}
