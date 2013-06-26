// Created : 11:02:55 AM ; Oct 15, 2012

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

struct task{
	int priority;
	bool isMine;

	task(){}
	task(int _p, bool _i){
		priority = _p;
		isMine = _i;
	}
};

list<task> ts;
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	int ntest;
	cin >> ntest;

	int pos, p;

	list<task>::iterator it ;
	REP(i, ntest){
		ts.clear();
		scanf("%d %d", &n, &pos);
		REP(j, n) {
			scanf("%d", &p);
			ts.push_back(task(p, pos == j));
		}

		int time = 0;

		while (true){
			task top = ts.front();

			bool canPrintTop = true;
			for (it = ts.begin(); it != ts.end(); ++it){
				if (it->priority > top.priority){
					canPrintTop = false;
					break;
				}
			}

			ts.pop_front();
			if (canPrintTop){
				++time;
				if (top.isMine) break;
			}
			else ts.push_back(top);
		}

		printf("%d\n", time);
	}
}
