// Created : 11:08:24 AM ; Oct 14, 2012

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

inline void solve();
int value[30];

int split(char* mix, int len);
vector<char> toPostFix(char* expression, int len);
int calcFromPostFix(vector<char> postFix);

inline bool isCharacter(char c);
inline bool isOpe(char c);
char mixExpression[100000];

int main() {
	//#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	int ntest;
	scanf("%d", &ntest);

	REP(i, ntest){
		printf("Data set %d: ", i + 1);
		solve();
		if (i != ntest - 1) printf("\n");
	}
}

bool isOpe(char c){
	return c == '|' || c == '&' || c == '~' || c == '^';
}

bool isCharacter(char c){
	return c >= 'a' && c <= 'z';
}

int split(char* mix, int len){

	FOR(i, 1, len - 1){
		if (mix[i] == '(' || mix[i] == '~' || isCharacter(mix[i])){
			char prev = mix[i-1];
			if (prev == ')' || (prev >= 'a' && prev <= 'z') ){
				return i;
			}
		}
	}
	return -1;
}

vector<char> toPostFix(char* exp, int len){
	stack<char> st;
	vector<char> postfix;

	// To postfix
	REP(i, len){
		int cur = exp[i];
		if (isCharacter(cur)){
			postfix.push_back(cur);

			if (!st.empty() && (st.top() == '~')){
				postfix.push_back('~');
				st.pop();
			}
		}
		else if (cur == '(' || isOpe(cur)){
			st.push(cur);
		}
		else { // cur == ')'
			do {
				char front = st.top();
				st.pop();
				if (front == '(') break;
				postfix.push_back(front);
			}
			while (!st.empty());
			if (!st.empty() && (st.top() == '~')){
				postfix.push_back('~');
				st.pop();
			}
		}
	}

	while (!st.empty()){
		char front = st.top();
		st.pop();
		postfix.push_back(front);
	}

	return postfix;
}

int calcFromPostFix(vector<char> postfix){
	stack<int> sti;
	// Calc
	REP(i, SZ(postfix)){
		if (isCharacter(postfix[i])){
			sti.push(value[postfix[i] - 'a']);
		}
		else {
			if (postfix[i] == '~'){
				int front = sti.top();
				sti.pop();
				sti.push(~front);
			}
			else {
				int a = sti.top(); sti.pop();
				int b = sti.top(); sti.pop();

				int ret;
				switch (postfix[i]){
					case '&': ret = a & b; break;
					case '|': ret = a | b; break;
					case '^': ret = a ^ b; break;
				}

				sti.push(ret);
			}
		}
	}

	int ret = sti.top(); sti.pop();
	assert(sti.empty());
	return ret;
}

void solve(){
	scanf("%s", mixExpression);
	int len = strlen(mixExpression);
	int between = split(mixExpression, len);
	int nTry = 20;

	bool isOK = true;
	vector<char> postFixOne = toPostFix(mixExpression, between);
	vector<char> postFixTwo = toPostFix(mixExpression + between, len - between);

	REP(i, nTry){
		FOR(i, 'a', 'z'){
			value[i - 'a'] = rand() % 100;
		}

		int first = calcFromPostFix(postFixOne);
		int second = calcFromPostFix(postFixTwo);

		if (first != second){
			isOK = false;
			break;
		}
	}

	printf(isOK ? "Equivalent" : "Different");
}
