// Created : 12:18:02 PM ; Oct 15, 2012

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
const ll P = (ll) 2013;

ll pwr[3005];

void init(){
	pwr[0] = 1;
	FOR(i, 1, 3000){
		pwr[i] = (pwr[i - 1] * P) % MOD;
	}
}

ll hash(set<ll> s){ // add bracket and hash
	int len = s.size();
	int cnt = 0;

	ll ret = 0;
	for(set<ll>::iterator it = s.begin(); it != s.end(); it ++){
		ret += (*it) * pwr[len - cnt];
		ret %= MOD;
		cnt++;
	}
	return ret;
}

ll hash(ll num){ // add more bracket
	return (num % P) % MOD;
}

inline void run(){
	int N;
	scanf("%d", &N);
	stack< set<ll> > ss;
	set<ll> ONE;
	ONE.insert(1);

	char cmd[20];
	REP(i, N){
		scanf("%s", cmd);

		if (strcmp(cmd, "PUSH") == 0){
			ss.push(ONE);
		}
		else if (strcmp(cmd, "DUP") == 0){
			set<ll> top = ss.top(); ss.pop();
			ss.push(top);
			ss.push(top);
		}
		else if (strcmp(cmd, "ADD") == 0){
			set<ll> first =  ss.top(); ss.pop();
			set<ll> second = ss.top(); ss.pop();
			ll newH = hash(first);
			second.insert(newH);
			ss.push(second);
		}
		else if (strcmp(cmd, "UNION") == 0){
			set<ll> first =  ss.top(); ss.pop();
			set<ll> second = ss.top(); ss.pop();
			for(set<ll>::iterator it = second.begin(); it != second.end(); it ++){
				first.insert(*it);
			}
			ss.push(first);
		}
		else if (strcmp(cmd, "INTERSECT") == 0){
			set<ll> first =  ss.top(); ss.pop();
			set<ll> second = ss.top(); ss.pop();
			set<ll> intersect;
			for(set<ll>::iterator it = second.begin(); it != second.end(); it ++){
				if (first.count(*it) > 0){
					intersect.insert(*it);
				}
			}
			ss.push(intersect);
		}

		else {
			cout << i << " cmd ??????" << endl;
		}

		printf("%d\n", ss.top().size() - 1);
	}
	printf("***\n");

}
int main() {
	//freopen("input.txt", "r", stdin);

	init();
	int ntest;
	cin >> ntest;
	REP(i, ntest){
		run();
	}
}
