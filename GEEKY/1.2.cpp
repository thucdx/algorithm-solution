#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <cstring>
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
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const int INF = (int) 1E9 + 5;  // enough ?
const double EPS = 1E-11;      // relevant ?
const ll MOD = (ll) 1E9 + 7;  // problem's mod ?
typedef pair<char, vector<char> > PCS;

vector<string> encrypted;
vector<string> decrypted;
set<string> dict;
map<char, char> m;
vector<PCS> subs;
bool found = true;

inline vector<string> split(string s);
void solve();
void go(int n);
inline bool isOK(char, char);
inline bool isInDict(string text);
inline string getDec(string enc);

int main() {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	string encryptedLine, dictLine, subLine;

	getline(cin, encryptedLine);
	encrypted = split(encryptedLine);

	getline(cin, dictLine);
	vector<string> _dict = split(dictLine);
	FOR(i, 0, SZ(_dict) - 1) dict.insert(_dict[i]);

	set<char> already;
	while (getline(cin, subLine)) {
		vector<string> tmp = split(subLine);
		vector<char> other;
		FOR(i, 1, SZ(tmp) - 1) {
			other.PB(tmp[i][0]);
		}
		already.insert(tmp[0][0]);
		subs.PB(MP(tmp[0][0], other));
	}

	vector<char> all;
	FOR(c,'a','z') all.PB(c);

	FOR(i, 0, encryptedLine.length() - 1) {
		if (encryptedLine[i] != ' ' && already.count(encryptedLine[i])< 1) {
			already.insert(encryptedLine[i]);
			subs.PB(MP(encryptedLine[i], all));
		}
	}

	solve();
}

void solve() {
	FOR(c,'a','z') m[c] = ' ';
	FOR(i, 0, SZ(encrypted) - 1) {
		string n;
		FOR(j, 0, encrypted[i].length() -1 ) n.PB(' ');
		decrypted.PB(n);
	}
	found = false;
	go(0);
}

void go(int n) {
	if (found) return;
	if (n >= SZ(subs)) {
		found = true;
		// show
		FOR(i, 0, SZ(encrypted) -1 ) {
			cout << getDec(encrypted[i]);
			if (i != SZ(encrypted) - 1) cout << " ";
		}
		cout << endl;
		return;
	}
	vector<char> other = subs[n].second;
	char cur 		   = subs[n].first;
	FOR(i, 0, SZ(other) - 1) {
		if (found) break;
		if (isOK(cur, other[i])) {
			char curMap = m[cur];
			m[cur] = other[i];
			go(n + 1);
			m[cur] = curMap;
		}
	}
}

bool isOK(char oldChar, char newChar) {
	char save = m[oldChar];
	m[oldChar] = newChar;
	bool result = true;
	FOR(i, 0, SZ(encrypted) - 1) {
		if (!isInDict(getDec(encrypted[i]))) {
			result = false;
			break;
		}
	}
	m[oldChar] = save;
	return result;
}

string getDec(string enc) {
	string result = enc;
	FOR(i, 0, enc.length() - 1) {
		result[i] = m[enc[i]];
	}
	return result;
}

bool isInDict(string text) {
	int len = text.length();
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
		string cur = *it;
		if (cur.length() != len) continue;
		bool isFit = true;
		FOR(i, 0, len - 1) {
			if (text[i] != ' ' && text[i] != cur[i]) {
				isFit = false;
				break;
			}
		}
		if (isFit) return true;
	}
	return false;
}


inline vector<string> split(string s) {
	vector<string> result;
	string sub;
	istringstream iss(s);
	while(iss) {
		iss >> sub;
		if (sub != " ")
			result.push_back(sub);
	}
	result.pop_back();
	return result;
}
