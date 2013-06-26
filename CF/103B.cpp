/*
* TIMXAD
* Date : Apr 16, 2013, 3:19:57 PM
* Task : 103B
* Desc :
*/
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

#define MAX 100

struct FindCycle {
private:
	int n;
	bool vs[MAX + 5];
	int prv[MAX + 5];
	vector<int> adj[MAX + 5];
	vector<int> cycle;
	bool found;
public:
	FindCycle(vector<int> _adj[], int _n) {
		found = false;
		n = _n;
		FOR(i, 1, n) {
			adj[i] = _adj[i];
		}
		memset(vs, false, sizeof(vs));
	}

	vector<int> getCycle() {
		if (found) return cycle;
		FOR(ii, 1, n) prv[ii] = -1;
		startFindFrom(1);
		return cycle;
	}

	void startFindFrom(int x) {
		REP(i, SZ(adj[x])) {
			if (found) return;
			int cur = adj[x][i];
			if (!vs[cur]) {
				int save = prv[cur];
				prv[cur] = x;
				vs[cur] = true;
				startFindFrom(cur);
				vs[cur] = false;
				prv[cur] = save;
			}
			else if (vs[cur] && prv[x] != cur && prv[x] != -1) {
				cycle.clear();
				prv[cur] = -1;
				cur = x;
				found = true;
				while (cur != -1) {
					cycle.PB(cur);
					cur = prv[cur];
				}
				return;
			}
		}
	}
};

struct P103B {
private:
		int n, m;
		vector<int> adj[MAX + 5];
		bool con[MAX + 5][MAX + 5];
		int r[MAX + 5];
		set<int> c;

		void readFromInput() {
			scanf("%d %d", &n, &m);
			int a, b;
			memset(con, false, sizeof(con));
			REP(i, m) {
				scanf("%d %d", &a, &b);
				con[a][b] = true;
				adj[a].PB(b);
				adj[b].PB(a);
			}
		}

		int getRoot(int x) {
			return x == r[x] ? x : r[x] = getRoot(r[x]);
		}

		bool unite(int a, int b) {
			int ra = getRoot(a), rb = getRoot(b);
			if (ra == rb) return false;
			r[ra] = rb;
			return true;
		}
public:
	void solve() {
		readFromInput();
		FindCycle f(adj, n);
		vector<int> cycle = f.getCycle();

		if (cycle.empty()) {
			puts("NO");
			return;
		}

		FOR(i, 1, n) r[i] = i;
		REP(i, SZ(cycle)) {
			c.insert(cycle[i]);
			r[cycle[i]] = cycle[0];
		}
		for(int i = 0; i < cycle.size(); ++i) {
			int u = cycle[i], v = (i == cycle.size() - 1 ? cycle[0] : cycle[i + 1]);
			con[u][v] = false, con[v][u] = false;
		}
		REP(i, SZ(cycle)) REP(j, SZ(cycle)) {
			if (con[cycle[i]][cycle[j]]) {
				puts("NO"); return;
			}
		}

		// Check Tree
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				if (con[i][j]) {
					if (!unite(i, j)) {
						puts("NO");
						return;
					}
				}
			}
		}

		FOR(i, 1, n) {
			if ((SZ(adj[i]) == 0) && c.count(i) == 0) {
				puts("NO");
				return;
			}
		}
		puts("FHTAGN!");
	}
};



int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	P103B p;
	p.solve();
}
