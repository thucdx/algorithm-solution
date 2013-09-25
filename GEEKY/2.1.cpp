/* TIMXAD
* Task : 2.1_Bomberman_2
* Desc : Geeky 2.1
*/
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

#define FOR(i, a, b) for (int _b = (b), i = (a); i <= _b; i++)
#define FORD(i, a, b) for (int _b = (b), i = (a); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

struct Bomb {
	int row, col, timing, state;

	Bomb(int r, int c, int t) {
		row = r;
		col = c;
		timing = t;
		state = 0; //0 : timing; 1, 2, 3, 4, 5: exploding; 6 : exploded
	}

	bool operator<(const Bomb& other) const {
		return timing < other.timing;
	}
};

struct Path {
	vector<int> path;
	Path(vector<int> &p) {
		path = p;
	}

	bool operator<(const Path& other) const{
		int sz = path.size(), osz = other.path.size();
		if (sz != osz) {
			return sz < osz;
		}
		REP(i, sz) {
			if (path[i] != other.path[i]) {
				return path[i] < other.path[i];
			}
		}
		return true;
	}

	void show() {
		printf("%d", path[0]);
		FOR(i, 1, SZ(path) - 1) {
			printf(" %d", path[i]);
		}
	}
};

//const int MAX = 250;
bool **maze, **mazeState, **visited;
vector< vector<bool> > tmp;
vector<int> trace;
int row, col, rowStart, colStart, rowEnd, colEnd, curRow, curCol;

vector<Bomb> bombs;
vector< Path> result;
const string IMPOSSIBLE  = "Impossibru!";

inline void getCordinate(int a, int &r, int &c) { // base 1
	c = a % col + 1;
	r = a / col + 1;
}

inline int toIndex(int r, int c) {
	return (r - 1) * col + c - 1;
}

inline void getBombDetail(string detail, int &a, int &t) {
	istringstream is (detail);
	char c;
	is >> a;
	is >> c; // :
	is >> t;
}

inline int toNum(string x) {
	int result;
	istringstream is(x);
	is >> result;
	return result;
}

inline string toString(int x) {
	string result;
	stringstream is;
	is << x;
	is >> result;
	return result;
}

void input() {
	int start, end;
	string str;
	vector<pair<int, int> > bombInfo;

	scanf("%d %d", &start, &end);
	scanf("%*c");

	getline(cin, str);
	istringstream is(str);
	string part;
	while (is >> part) {
		int a, t;
		getBombDetail(part, a, t);
		bombInfo.PB(MP(a, t));
	}

	int number;
	stringstream ss;
	while (getline(cin, str)) {
		vector<bool> t;
		++row;
		col = 0;
		ss.clear();
		ss << str;
		while (ss >> number) {
			++col;
			t.PB(number);
//			maze[row][col] = number;
		}
		tmp.push_back(t);
	}

	maze = new bool *[row + 1];

	REP(i, SZ(tmp)) {
		maze[i + 1] = new bool[col + 1];
		REP(j, SZ(tmp[i])) {
			maze[i + 1][j + 1] = tmp[i][j];
		}
	}

	getCordinate(start, rowStart, colStart);
	getCordinate(end, rowEnd, colEnd);

	REP(i, SZ(bombInfo)) {
		int r, c;
		getCordinate(bombInfo[i].first, r, c);
		bombs.PB(Bomb(r, c, bombInfo[i].second));
	}
}

inline void bang(int r, int c, int state) {
	if (state <= 0 || state >= 6) return;
	if (state >= 4) state = 6 - state;
	state--;
	FOR(i, r - 2, r + 2) {
		FOR(j, c - 2, c + 2) {
			if (i > 0 && i <= row && j > 0 && j <= col) {
				if (abs(i - r) + abs(j - c) <= state) {
					mazeState[i][j] = true;
				}
			}
		}
	}
}

void showMaze() {
	FOR(i, 1, row) {
		FOR(j, 1, col) {
			cout << mazeState[i][j];
			if (i == curRow && j == curCol) {
				cout << "'";
			}
			cout << " ";
		}
		cout << endl;
	}
}

void go(int n) {
//	cout << "Go " << n << endl;
	if (curRow == rowEnd && curCol == colEnd) {
		int c = colStart, r = rowStart;
		string str;
		vector<int> p;
		p.PB(toIndex(r, c));

		REP(i, SZ(trace)) {
			int dir = trace[i];
			c += dc[dir];
			r += dr[dir];
			p.PB(toIndex(r, c));
		}

		result.PB(Path(p));
		return;
	}

	FOR(i, 1, row) FOR(j, 1, col) mazeState[i][j] = false;

	// update next state
	REP(i, SZ(bombs)) {
		if (bombs[i].state >= 1 && bombs[i].state <= 5) bombs[i].state++;
		else if (bombs[i].state == 0 && bombs[i].timing == n + 1) {
			bombs[i].state = 1;
		}
	}

	// Explode
	REP(i, SZ(bombs)) {
		bang(bombs[i].row, bombs[i].col, bombs[i].state);
	}

	// Chain
	REP(i, SZ(bombs)) {
		if ((bombs[i].state == 0) && mazeState[bombs[i].row][bombs[i].col]) {
			bombs[i].state = 1;
			bang(bombs[i].row, bombs[i].col, bombs[i].state);
		}
	}

	// mazeState
	FOR(i, 1, row) {
		FOR(j, 1, col) {
			mazeState[i][j] |= maze[i][j];
		}
	}

	int saveRow = curRow;
	int saveCol = curCol;

	vector<int> saveBombstate(SZ(bombs));
	bool **saveMazeState;
	saveMazeState = new bool* [row + 1];
	FOR(i, 1, row) saveMazeState[i] = new bool[col + 1];

	REP(i, SZ(bombs)) saveBombstate[i] = bombs[i].state;
	FOR(i, 1, row) FOR(j, 1, col) saveMazeState[i][j] = mazeState[i][j];

	REP(i, 4) {
		int nr = saveRow + dr[i];
		int nc = saveCol + dc[i];
		if (nr > 0 && nr <= row && nc > 0 && nc <= col
				&& !visited[nr][nc] && !mazeState[nr][nc]) {
			curRow = nr; curCol = nc;
			visited[nr][nc] = true;
			trace.push_back(i);

			go(n + 1);

			trace.pop_back();
			visited[nr][nc] = false;
			REP(j, SZ(saveBombstate)) bombs[j].state = saveBombstate[j];
			FOR(i, 1, row) FOR(j, 1, col) mazeState[i][j] = saveMazeState[i][j];
		}
	}
}

void solve() {
	visited = new bool* [row + 1];
	FOR(i, 1, row) visited[i] = new bool[col + 1];
	mazeState = new bool* [row + 1];
	FOR(i, 1, row) mazeState[i] = new bool[col + 1];

	FOR(i, 1, row) FOR(j, 1, col) visited[i][j] = mazeState[i][j] = false;

	curRow = rowStart;
	curCol = colStart;
	visited[curRow][curCol] = true;

	REP(i, SZ(bombs)) {
		if (bombs[i].timing == 1) {
			mazeState[bombs[i].row][bombs[i].col] = true;
		}
	}

	REP(i, SZ(bombs)) {
		if (mazeState[bombs[i].row][bombs[i].col]) {
			bombs[i].state = 1;
		}
	}
	if (!mazeState[rowStart][colStart]) {
		go(1);
	}

	sort(result.begin(), result.end());
	if (result.size() == 0) {
		cout << IMPOSSIBLE << endl;
	} else {
		REP(i, SZ(result)) {
			result[i].show();
			if (i != (int) SZ(result) - 1) printf("\n");
		}
	}
}


int main() {
#ifdef LOCAL
	freopen("./IO/bomb.txt", "rt", stdin);
//	freopen("./IO/output.txt", "wt", stdout);
#endif
	input();
	solve();
}
