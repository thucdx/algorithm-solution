
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
#include <conio.h>
using namespace std;

int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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

const int MAX = 2 * 1e6;
bool p[(int)(2 * 1e6)];
int n, k;
string s;

inline void makePrime(){
	int cnt = 0;
	stringstream ss;

	memset(p, true, sizeof(p));
	p[0] = 0;
	p[1] = 0;
	p[2] = true;
	int i = 2;
	while (i  < MAX){
		if (p[i]){
			cnt ++;
			if ( cnt > n) break;
			long long j = ((long long) i) * i;
			while (j < MAX){
				p[j] = 0;
				j += i;
			}
			ss << i;
		}
		++i;
	}

	ss >> s;

#ifdef LOCAL
	//cout << s << endl;
#endif
}

char ret[MAX];


inline void run() {
    cin >> n >> k;
	makePrime();

	int len = s.length();
	int cur = 0;
	vector<char> ret;

	REP(i, k){
		int retsz = ret.size();
		bool isFound = false;

		if (retsz >= 2){
			if (ret[retsz - 1] > ret[retsz - 2]){
				int val = ret[retsz - 1];
				ret.pop_back();
				ret.pop_back();
				ret.push_back(val);
				isFound = true;
			}
		}

		if (!isFound){
			if (cur < len){
				int last = ret.size() > 0 ? ret[ret.size() - 1] : INF;
				while (cur < len && (s[cur] < last)){
					ret.push_back(s[cur]);
					last = s[cur];
					cur ++;
				}

				if (cur == len){
					ret.pop_back();
				}
				else {
					ret.pop_back();
					ret.push_back(s[cur]);
					cur++;
				}
			}
			else{
				ret.pop_back();
			}
		}
	}

	while(cur < len){
		ret.push_back(s[cur]);
		cur++;
	}

	string rs;
	rs.resize(ret.size());
	REP(i, ret.size())	rs[i] = ret[i];
	cout << rs << endl;
//	getch();
}
