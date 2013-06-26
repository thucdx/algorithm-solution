// Created : 1:47:58 PM ; Oct 16, 2012

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

struct team{
	string name;
	int rating;
	int id;

	team(){}
	team(string n, int r, int i){
		name = n;
		rating = r;
		id = i;
	}
	bool operator< (const team& that) const{
		return rating > that.rating;
	}
};

vector<team> teams;
vector<string> teamName;
int n, x, a, b, c;

list<int> basket[4];
int group[20][4];

inline int getRandom(){
	x = (x * a + b) % c;
	return x;
}

inline int getRandomAndRemove(list<int>& l){
	int index = getRandom() % l.size();
	int val, cnt = 0;

	for (list<int>::iterator it = l.begin(); it != l.end(); it++){
		if (cnt == index){
			val = *it;
			break;
		}
		cnt++;
	}

	l.remove(val);
	return val;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> x >> a >> b >> c;

	string name;
	int rating;

	REP(i, n){
		cin >> name >> rating;
		teamName.PB(name);
		teams.PB(team(name, rating, i));
	}

	sort(ALL(teams));

	vector<int> index;
	REP(i, n) index.PB(teams[i].id);

	// process;
	int m = n / 4;

	REP(i, n) basket[i / m].push_back(index[i]);
	REP(i, m - 1) REP(j, 4) group[i][j] = getRandomAndRemove(basket[j]);
	REP(j, 4) group[m - 1][j] = basket[j].front();

	// xong!
	REP(i, m){
		printf("Group %c:\n", 'A' + i);
		REP(j, 4) cout << teamName[group[i][j]] << endl;
	}
}

