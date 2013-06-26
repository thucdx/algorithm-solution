/* TIMXAD
* Task : 300B
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

int n;
bool adj[50][50];
vector<int> teams[50];
bool visited[50];
bool inTeam[50];

void visit(int start, int v) {
	visited[v] = true;
	teams[start].push_back(v);

	FOR(i, 1, n) {
		if (!visited[i] && adj[v][i]) {
			visit(start, i);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./IO/input.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	int a,b, m;
	memset(adj, false, sizeof(adj));
	memset(visited, false, sizeof(visited));
	memset(inTeam, false, sizeof(inTeam));

	scanf("%d %d", &n, &m);
	REP(i, m) {
		scanf("%d %d", &a, &b);
		adj[a][b] = adj[b][a] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			visit(i, i);
		}
		if (teams[i].size() > 3) {
			puts("-1");
			return 0;
		}
	}

	// OK
	FOR(i, 1, n) {
		if (SZ(teams[i]) > 1)
			REP(j, SZ(teams[i]))
				inTeam[teams[i][j]] = true;
	}

	FOR(i, 1, n) {
		if (teams[i].size() > 1) {
			int count = 0;
			int more = 3 - teams[i].size();
			FOR(j, 1, n) {
				if (!inTeam[j]) {
					if (count >= more) break;
					count ++;
					teams[i].PB(j);
					inTeam[j] = true;
				}
			}
			if (count < more) {
				puts("-1");
				return 0;
			}
		}
	}
	FOR(i, 1, n) {
		if (teams[i].size() > 1) {
			REP(ii, SZ(teams[i])) {
				cout << teams[i][ii] << " ";
			}
			cout << endl;
		}
	}

	int count = 0;
	FOR(i, 1, n) {
		if (!inTeam[i]) {
			inTeam[i] = true;
			count++;
			cout << i << " ";
			if (count == 3) {
				count = 0;
				cout << endl;
			}
		}
	}

}
