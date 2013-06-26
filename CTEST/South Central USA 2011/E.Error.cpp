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

int num[30][30][30];
int dist[20005];
int more[20005];
vector<int> adj[20005];
set<int> already[20005];

int main() {

#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
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

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	cin >> ntest;
	REP(i, 27)
	REP(j, 27)
	REP(t, 27){
		num[i][j][t] = i * 27 * 27 + j * 27 + t;
	}
}

inline int getId(char * cityName, int i = 0){
	return num[cityName[i] - 'A'][cityName[i + 1] - 'A'][cityName[i + 2] - 'A'];
}

char record[30000000];

struct Mog {
	int ver;
	int dis;
	int more;

	Mog(){}
	Mog(int v, int d, int m){
		ver = v, dis = d, more = m;
	}

	bool operator< (const Mog& that) const{
		if (dis != that.dis) return dis < that.dis;
		return more < that.more;
	}
};


inline void run() {
	REP(i, 20000){
		dist[i] = INF;
		more[i] = INF;
		adj[i].clear();
		already[i].clear();
	}

	int n;
	char first[5], second[5];
	scanf("%d", &n);

	REP(i, n){
		scanf("%s %s", first, second);
		int f = getId(first);
		int s = getId(second);
		adj[f].PB(s);
		adj[s].PB(f);
	}

	int m;
	scanf("%d ", &m);
	gets(record);

	int start = getId(record), end;
	int last = start;

	int id = 0;
	FOR(i, 1, m){
		id += 4;
		int news = getId(record, id);
		already[last].insert(news);
		last = news;
	}
	end = last;

	//Dijikstra
	priority_queue< Mog > q;
	q.push(Mog(start, 0, 0));
	dist[start] = 0;
	more[start] = 0;

	int ret = 0;
	while (!q.empty()){
		Mog top = q.top(); q.pop();
		int d = top.dis;
		int m = top.more;
		int v = top.ver;

		if ((dist[v] < d) || ((dist[v] == d) && more[v] < m)) continue;

		if (v == end){
			ret = m;
			break;
		}

		REP(i, SZ(adj[v])){
			int nxt = adj[v][i];
			int maybeMore = m + 1 - already[v].count(nxt);

			if (d + 1 < dist[nxt]){
				dist[nxt] = d + 1;
				more[nxt] = maybeMore;
				q.push(Mog(nxt, dist[nxt], more[nxt]));
			}
			else if (d + 1 == dist[nxt] && more[nxt] > maybeMore){
				more[nxt] = maybeMore;
				q.push(Mog(nxt, dist[nxt], more[nxt]));
			}
		}
	}

	printf("%d\n", ret);
}
