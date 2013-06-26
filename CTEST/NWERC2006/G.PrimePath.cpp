// Created : 1:09:20 AM ; Oct 15, 2012

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

vector<int> prime;
void init();
bool isPrime(int n);
bool isAdj(int a, int b);
vector<int> adj[1111];
map <int, int> m;
int id[10000];
int d[1111];
void findShortestPath(int u, int v);

int main() {
	//freopen("input.txt", "r", stdin);
	init();
	int ntest;
	cin >> ntest;
	int u, v;
	REP(i, ntest){
		scanf("%d %d", &u, &v);
		int mu = id[u], mv = id[v];
		findShortestPath(mu, mv);
	}
}

void findShortestPath(int u, int v){
	fill(d, d + prime.size(), INF);
	priority_queue < pair<int, int> > q;
	d[u] = 0;

	q.push(MP(0, u));

	while (!q.empty()){
		pair<int, int> front = q.top(); q.pop();
		int ver = front.second;
		int dis = front.first;

		if (dis > d[ver]) continue;

		REP(i, SZ(adj[ver])){
			int cur = adj[ver][i];
			if (d[cur] > dis + 1){
				d[cur] = dis + 1;
				q.push(MP(d[cur], cur));
			}
		}
	}

	//printf((d[v] == INF) ? "Impossible\n" : ("%d\n", d[v]));
	if (d[v] == INF){
		printf("Impossible\n");
	}
	else printf("%d\n", d[v]);
}

bool isPrime(int n){
	if ( n <= 3) return  n <= 2;
	if ( n % 2 == 0) return false;
	int lim = sqrt(n);
	for (int i = 3; i <= lim; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

bool isAdj(int a, int b){
	int cnt = 0;
	REP(i, 4){
		if ((a % 10) != (b % 10)){
			cnt ++;
		}
		a /= 10, b /= 10;
	}

	return cnt == 1;
}

void init(){
	int cnt = 0;
	FOR(i, 1000, 9999){
		if (isPrime(i)){
			prime.PB(i);
			id[i] = cnt;
			cnt++;
		}
	}

	int len = prime.size();

	REP(i, len)
	FOR(j, i + 1, len - 1)
	{
		if (isAdj(prime[i], prime[j])){
			adj[i].PB(j);
			adj[j].PB(i);
		}
	}
}
