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
	//freopen("output.txt", "w", stdout);
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

const int MAX_DIG = 50;

struct BigInt{
	char d[MAX_DIG];
	int leng;
	BigInt(){
		REP(i, MAX_DIG){
			d[i] = 0;
		}
		leng = 0;
	}

	BigInt(string a){
		leng = a.length();
		/*REP(i, leng){
			d[i] = a[i] - '0';
		}*/
	}

	BigInt(int a){
		if (a > 0)
			leng = log10(a) + 1;
		else leng = 1;
		int cnt = 0;
		do{
			d[leng - cnt - 1] = a % 10;
			a /= 10;
			cnt ++;
		}
		while (a != 0);
	}

	BigInt operator+(const BigInt &other) {
		int t[MAX_DIG];
		int cnt = 0;
		int mem = 0;

		for (int i = leng - 1, j = other.leng - 1 ; (i >= 0) || (j >= 0); --i, --j){
			cnt ++;
			int val = (i >= 0 ? d[i] : 0 )  + (j >= 0 ? other.d[j] : 0) + mem;
			t[cnt - 1] = val % 10;
			mem = val / 10;
		}
		if (mem > 0){
			cnt ++;
			t[cnt - 1] = mem;
		}

		BigInt ret = BigInt();
		ret.leng = cnt;
		REP(i, cnt){
			ret.d[i] = t[cnt - i - 1];
		}

		return ret;
	}

	void print(){
		REP(i, leng){
			printf("%d", d[i]);
		}
	}
};


//const int PSIZE = 1005;
BigInt** c;

inline void init() {
	ntest = 1;
}
BigInt zero = BigInt(0);

inline BigInt calc(int i, int j){
	if (c[i][j].leng == 0) return zero;
	return c[i][j];
}

inline void run() {
	int N;
	cin >> N;

	c = new BigInt*[N + 1];
	FOR(i, 0, N) c[i] = new BigInt[N + 1];
	/*FOR(i, 1, N)
	FOR(j, 1, N)
		c[i][j] = zero;*/

	FOR(i, 1, N) c[1][i] = 1;
	FOR(i, 2, N) c[2][i] = 1;

	for(int n = 3; n <= N; n++){
		for (int j = 1; j <= N; j++){
			if (n > j){
				c[n][j] = calc(n, j - 1) + calc(n - j, j - 1);
			}
			else if (j > n){
				c[n][j] = c[n][j -1];
			}
			else {
				c[n][j] = c[n][j-1] + 1;
			}
		}
	}

	c[N][N - 1].print();
}
