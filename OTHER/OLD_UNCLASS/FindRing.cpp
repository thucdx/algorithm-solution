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
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
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
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const double EPS = 1E-11;
const ll MOD = (ll) 1E9 + 7;
const int PSIZE = 1e5 + 5;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	ntest = 1;
}

int totalRing = 0;
vector<int> adj[PSIZE];
int ring[PSIZE];
int findRing(int v, vector<int>& r);
void dfs(int v);
void bfs(int v);
int prev[PSIZE];
bool inQueue[PSIZE];
bool visited[PSIZE];
int n, m;
inline void run() {
	cin >> n >> m;
	int u, v;
	REP(i, m){
		cin >> u >> v;
		--u, --v;
		adj[u].PB(v);
		adj[v].PB(u);
	}

	cout << "dfs" << endl;
	dfs(0);
	cout << "bfs" << endl;
	bfs(0);
	/*fill(ring, ring + n, -1);
	REP(i, n){
		if (ring[i] == -1){
			vector<int> r;
			int nextRing = findRing(i, r);
			if (nextRing != -1){
				REP(j, SZ(r)){
					ring[r[j]] = nextRing;
					cout << r[j] << " " ;
				}
				cout << endl;
			}
		}
		else cout << "not found ring" << endl;
	}*/
}

void dfs(int v){
	stack<int> st;
	st.push(v);
	bool visited[PSIZE];

	while(!st.empty()){
		int cur = st.top(); st.pop();
		if (visited[cur]) continue;
		cout << cur << " ";
		visited[cur] = true;
		REP(j, SZ(adj[cur])){
			int nxt = adj[cur][j];
			if (!visited[nxt]){
				st.push(nxt);
			}
		}
	}
	cout << endl;
}

void bfs(int v){
	queue<int> q;
	q.push(v);
	bool visited[PSIZE];

	memset(visited, false, sizeof(visited));
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if (visited[cur]) continue;
		cout << cur << " ";
		visited[cur] = true;
		REP(j, SZ(adj[cur])){
			int nxt = adj[cur][j];
			if (!visited[nxt]){
				q.push(nxt);
			}
		}
	}
	cout << endl;
}

/*
	bool minDistance(int u, int v, int &dis){
		if (u < 0 || v >= n) {
			dis = INF;
			return false;
		}

		priority_queue< pair<int, int> > q;

		q.push(MP(0, u));
		bool visited[PSIZE];
		int d[]
		memset(visited, false, sizeof(visited));

		while (!q.empty()){
			pair<int, int> fr = q.top(); q.pop();
			if (visited[fr.second]) continue;
			visited[fr.second] = true;
			int curVer = fr.second;
			REP(j, SZ(adj[curVer])){
				int nxt = adj[curVer][j];

			}

		}

	}
*/

int findRing(int v, vector<int>& r){
	cout << "findRing of " << v << endl;
	memset(inQueue, false, sizeof(inQueue));
	memset(visited, false, sizeof(visited));
	fill(prev, prev + n, -1);

	stack<int> st;
	st.push(v);
	inQueue[v] = true;
	int last = -1;
	while (!st.empty()){
		int f = st.top();
		st.pop();

		if (visited[f]) continue;
		visited[f] = true;
		REP(j, SZ(adj[f])){
			int nxt = adj[f][j];
			if (nxt == v && prev[f] != v){ // found
				last = nxt;
				prev[nxt] = f;
				break;
			}

			if (visited[nxt]) continue;

			st.push(nxt);
			prev[nxt] = f;
		}
	}

	if (last == -1) return -1;

	int cur = last;
	do {
		r.PB(cur);
		cur = prev[cur];
	}
	while (cur != v);

	return ++totalRing;
}
