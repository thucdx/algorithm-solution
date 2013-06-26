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

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

inline void init() {
	ntest = 1;
}

int f(string s){
	string t ="";
	REP(i, s.length()){
		if (s[i] != '-')
			t.PB(s[i]);
	}

	bool same = true;
	FOR(i, 1, t.length() - 1){
		if (t[i] != t[i-1]){
			same = false;
			break;
		}
	}

	if (same) return 0; // taxi

	bool isPizza = true;
	FOR(i, 0, t.length() - 2){
		if (t[i] <= t[i + 1]){
			isPizza = false;
			break;
		}
	}
	if (isPizza) return 1;
	return 2;
}

vector<string> ns;
int cnt[105][3];

inline void run() {
	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	int m;
	string name, number;
	vector<string> s[3];
	int maxCnt[3];

	memset(maxCnt, 0, sizeof(maxCnt));

	REP(i, n){
		cin >> m;
		cin >> name;
		ns.PB(name);
		REP(j, m){
			cin >> number;
			int kind = f(number);
			//cout << f(number) << " " << number << endl;
			cnt[i][kind]++;
			if (cnt[i][kind] > maxCnt[kind]){
				maxCnt[kind] = cnt[i][kind];
			}
		}
	}

	REP(kind, 3){
		REP(i, n){
			if (cnt[i][kind] == maxCnt[kind]){
				s[kind].PB(ns[i]);
				//cout << kind << " pb " << ns[i] << endl;
			}
		}
	}



	cout << "If you want to call a taxi, you should call:";
	for (int i = 0; i < s[0].size(); ++i){
		if (i != s[0].size() - 1){
			cout << " " << s[0][i] << ",";
		}
		else cout << " " << s[0][i] <<"." << endl;
	}

	cout << "If you want to order a pizza, you should call:";
	for (int i = 0; i < s[1].size(); ++i){
		if (i != s[1].size() - 1){
			cout << " " << s[1][i] << ",";
		}
		else cout << " " << s[1][i] <<"." << endl;
	}

	cout << "If you want to go to a cafe with a wonderful girl, you should call:";
	for (int i = 0; i < s[2].size(); ++i){
		if (i != s[2].size() - 1){
			cout << " " << s[2][i] << ",";
		}
		else cout << " " << s[2][i] <<"." << endl;
	}



}
