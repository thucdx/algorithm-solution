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
	freopen("C.in", "r", stdin);
//	freopen("C.out", "w", stdout);
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

const int MAXN = 25;
const int MAXS = 100;

string s;
int n, a[MAXN], result, o[MAXN], numSolution;

inline void normalize(string &s) {
	FIT(it, s) {
		if (!isdigit(*it)) {
			*it = ' ';
		}
	}
}

char trans(int k) {
	if (k == 3) {
		return '/';
	}
	if (k == 2) {
		return '*';
	}
	if (k == 1) {
		return '-';
	}
	return '+';
}

int pop(vector<int>& stk) {
    if (stk.empty()) {
    	return 0;
    }
    int result = stk.back();
    stk.pop_back();
    return result;
}//end pop

ll calculate() {
	ostringstream ccout;
	REP(i, n) {
	ccout << a[i];
	if (i < n - 1) {
		ccout << " " << trans(o[i]) << " ";
	}
	}
	string s = ccout.str();
	cout << s;

	istringstream ccin(s);

    vector<int> opndStack; // vector used as operand stack
    string token;          // to read number or operator

    while (ccin >> token) {
        if (isdigit(token[0])) { // if first is digit, it's number.
            opndStack.push_back(atoi(token.c_str())); // convert, push

        } else { // If it's not a number, assume it's an operator
            int left, right;  //  used by some operators as temps

            switch (token[0]) {  // assume operators are one char
              case '+': opndStack.push_back(pop(opndStack) + pop(opndStack));
                        break;
              case '-': right = pop(opndStack); // get right operand
                        left  = pop(opndStack); // get left operand
                        opndStack.push_back(left - right);
                        break;
              case '*': opndStack.push_back(pop(opndStack) * pop(opndStack));
                        break;
              case '/': right = pop(opndStack); // get right operand
                        left  = pop(opndStack); // get left operand
                        opndStack.push_back(left / right);
                        break;
              default:  return 0;
            }
            int z = opndStack.back();
            cout << " = " << z << endl;
            return z;
        }
    }
    return 0;
}

bool dfs(int lvl, int value) {
	if (lvl >= n - 1) {
		ll nowResult = calculate();
		if (nowResult == result) {
			REP(i, n) {
				cout << a[i];
				if (i < n - 1) {
					cout << " " << trans(o[i]) << " ";
				}
			}
			cout << " = " << result << endl;
			numSolution++;
			if (numSolution >= MAXS) {
				return true;
			}
		}
		return false;
	}
	REP(i, 4) {
		o[lvl] = i;
		if (i == 3 && value % a[lvl + 1] != 0) {
			continue;
		}
		if (i == 3) { // divide
			if (dfs(lvl + 1, value / a[lvl + 1])) {
				return true;
			}
		} else if (i == 2) { // multiply
			if (dfs(lvl + 1, value * a[lvl + 1])) {
				return true;
			}
		} else { // add and subtract
			if (dfs(lvl + 1, a[lvl + 1])) {
				return true;
			}
		}
	}
	return false;
}

inline void run() {
	getline(cin, s);
	normalize(s);

	istringstream iss(s);
	{
		n = 0;
		while (iss >> a[n]) {
			n++;
		}
	}

	cin >> result;
	numSolution = 0;

	dfs(0, a[0]);
}
