// Created : 7:03:06 AM ; Oct 15, 2012

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

void solve(){
	string s;
	cin >> s;

	bool vs[30];
	int cnt[30];
	int id[30];
	memset(vs, false, sizeof(vs));
	memset(cnt, 0, sizeof(cnt));

	REP(i, SZ(s)){
		id[s[i] - 'A'] = i;
	}

	REP(i, 26){
		if (!vs[i]){
			int len = 0, j = i;
			do{
				++len;
				vs[j] = true;
				j = id[j];
			}
			while (j != i);
			cnt[len]++;
		}
	}

	REP(i, 30){
		if ((i % 2 == 0) && (cnt[i] % 2 == 1)){
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	int ntest;
	cin >> ntest;
	REP(i, ntest){
		solve();
	}
}
