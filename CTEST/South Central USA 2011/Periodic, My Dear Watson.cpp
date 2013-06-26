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
	scanf("%d", &ntest);
}

struct Element{
	char* name;
	int number;

	Element(){}
	Element(char* _name, int _number){
		name = strdup(_name);
		number = _number;
	}
};

struct Path{
	vector<Element> elements;
	int sum;
	bool isObvious;

	Path(){
		sum = 0;
		isObvious = false;
	}

	Path(vector<Element> _elements){
		sum = 0;
		isObvious = false;
		REP(i, SZ(_elements)){
			elements.PB(_elements[i]);
		}
	}

	void addElement(const Element& that){
		elements.push_back(that);
		sum += that.number;
	}

	bool isEmpty(){
		return elements.size() == 0;
	}

	int compare(const Path& other) const {
		if (elements.size() < other.elements.size()) return 1;
		else if (elements.size() > other.elements.size()) return -1;
		else {  // equal;
			if (sum < other.sum) return 1;
			else if (sum > other.sum) return -1;
		}

		return 0;
	}

	void print(){
		if (isObvious){
			puts("Too Obvious");
		}
		else {
			FORD(i, SZ(elements) - 1, 0){
				printf("[%s]", elements[i].name);
			}
			printf("\n");
		}
	}
};

int numberElements;
vector<Element> elements;

Path findBestPath(char * s){
	Path ret = Path();
	REP(i, numberElements){
		Path elemPath = Path();

		char* curElementName = elements[i].name;
		int len = strlen(curElementName);
		if (strncasecmp(curElementName, s, len) == 0){
			// ok
			if ((int)strlen(s) == len){
				elemPath.addElement(elements[i]);
			}
			else{
				elemPath = findBestPath(s + len);
				if (!elemPath.isEmpty())
					elemPath.addElement(elements[i]);
			}
		}

		if (elemPath.elements.size() == 0) continue;

		if (ret.elements.size() == 0) ret = elemPath;
		else {
			int compareRet = ret.compare(elemPath);
			if (compareRet == -1)
				ret = elemPath;
			else if (compareRet == 0)
				ret.isObvious = true;
		}
	}
	return ret;
}

inline void run() {
	elements.clear();

	char s[5005];
	scanf("%d", &numberElements);
	REP(i, numberElements){
		scanf("%s", s);
		elements.PB(Element(s, i + 1));
	}

	int query;
	scanf("%d", &query);

	REP(i, query){
		scanf("%s", s);
		Path bestPath = findBestPath(s);
		bestPath.print();
	}
}
