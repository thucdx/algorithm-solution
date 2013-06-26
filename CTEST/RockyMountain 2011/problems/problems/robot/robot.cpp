#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int,int> pii;

struct State
{
  int r, c, dir;
};

int M, N, mod;
string maze[1000];
pii end;

int ch_to_dir[256];
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int dist[1000][1000][4];
int paths[1000][1000][4];

void add_state(queue<State> &q, const State &curr, const State &next)
{
  int newdist = dist[curr.r][curr.c][curr.dir] + 1;
  if (dist[next.r][next.c][next.dir] >= 0 &&
      dist[next.r][next.c][next.dir] < newdist) return;
  if (dist[next.r][next.c][next.dir] < 0) {
    q.push(next);
  }
  dist[next.r][next.c][next.dir] = dist[curr.r][curr.c][curr.dir] + 1;
  paths[next.r][next.c][next.dir] += paths[curr.r][curr.c][curr.dir];
  paths[next.r][next.c][next.dir] %= mod;
}

bool solve(int id)
{
  ch_to_dir[(int)'N'] = 0;
  ch_to_dir[(int)'E'] = 1;
  ch_to_dir[(int)'S'] = 2;
  ch_to_dir[(int)'W'] = 3;
  
  cin >> M >> N >> mod;
  if (mod == 0) return false;
  getline(cin, maze[0]);

  for (int i = 0; i < M; i++) {
    getline(cin, maze[i]);
  }
  char dir_ch;

  State s;
  cin >> s.r >> s.c >> end.first >> end.second >> dir_ch;
  s.dir = ch_to_dir[(int)dir_ch];

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      fill(dist[i][j], dist[i][j]+4, -1);
      fill(paths[i][j], paths[i][j]+4, 0);
    }
  }

  queue<State> q;
  dist[s.r][s.c][s.dir] = 0;
  paths[s.r][s.c][s.dir] = 1;
  q.push(s);
  while (!q.empty()) {
    State curr = q.front();
    q.pop();

    if (curr.r == end.first && curr.c == end.second) break;

    // try to move forward
    State next = curr;
    next.r += dr[curr.dir];
    next.c += dc[curr.dir];
    if (0 <= next.r && next.r < M &&
	0 <= next.c && next.c < N &&
	maze[next.r][next.c] != '*') {
      add_state(q, curr, next);
    }

    // try to turn left
    next = curr;
    next.dir = (next.dir + 3) % 4;
    add_state(q, curr, next);

    // try to turn right
    next = curr;
    next.dir = (next.dir + 1) % 4;
    add_state(q, curr, next);
  }

  int ans = 0;
  bool reachable = false;
  for (int i = 0; i < 4; i++) {
    if (dist[end.first][end.second][i] >= 0) {
      ans += paths[end.first][end.second][i];
      ans %= mod;
      reachable = true;
    }
  }
  if (!reachable) {
    ans = -1;
  }
  cout << "Case " << id << ": " << mod << ' ' << ans << endl;

  return true;
}

int main()
{
  int id = 1;
  while (solve(id++))
    ;
  return 0;
}
