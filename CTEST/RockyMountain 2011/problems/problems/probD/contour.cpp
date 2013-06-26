#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX_R = 200;
const int MAX_C = 200;
const int MIN_REGION = 5;

int R, C;
char bitmap[MAX_R][MAX_C];

const int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dc[8] = { -1,  0, 1, 1, 1, 0, -1, -1 };

int count_region(int r, int c)
{
  if (r < 0 || c < 0 || r >= R || c >= C || bitmap[r][c] != '1') {
    return 0;
  }
  int ans = 1;
  bitmap[r][c] = '2';
  for (int d = 0; d < 8; d++) {
    ans += count_region(r + dr[d], c + dc[d]);
  }
  return ans;
}

void clear_region(int r, int c)
{
  if (r < 0 || c < 0 || r >= R || c >= C || bitmap[r][c] == '0') {
    return;
  }
  bitmap[r][c] = '0';
  for (int d = 0; d < 8; d++) {
    clear_region(r + dr[d], c + dc[d]);
  }
}

typedef pair<int,int> pii;

ostream &operator<<(ostream &os, pii p)
{
  return os << '(' << p.first << ", " << p.second << ')';
}

int trace(int rr, int cc)
{
  pii b0 = make_pair(rr, cc);
  pii c0 = b0;  c0.second--;
  
  /*
  cout << "b0 = " << b0 << endl;
  cout << "c0 = " << c0 << endl;
  */

  int start_dir = 7;
  pii b1 = c0, c1;
  do {
    c1 = b1;
    start_dir = (start_dir + 1) % 8;
    b1 = make_pair(b0.first + dr[start_dir], b0.second + dc[start_dir]);
  } while (bitmap[b1.first][b1.second] == '0');

  /*
  cout << "b1 = " << b1 << endl;
  cout << "c1 = " << c1 << endl;
  */

  pii b = b1, c = c1;
  int len = 2;          // b0, b1 are counted

  pii last1(-1, -1);

  while (true) {
    // find the start direction first
    start_dir = -1;
    for (int d = 0; d < 8; d++) {
      if (make_pair(b.first + dr[d], b.second + dc[d]) == c) {
	start_dir = d;
	break;
      }
    }
    assert(start_dir >= 0);

    pii n1 = c, n2;
    do {
      n2 = n1;
      start_dir = (start_dir + 1) % 8;
      n1 = make_pair(b.first + dr[start_dir], b.second + dc[start_dir]);
    } while (bitmap[n1.first][n1.second] == '0');
    
    b = n1;
    c = n2;
    /*    
    cout << "len = " << len+1 << endl;
    cout << "  b = " << b << endl;
    cout << "  c = " << c << endl;
    */
    if (b == b1 && last1 == b0) {
      break;
    }

    len++;
    last1 = b;
  }
  return len-1;       // remove the last b0 added
}

bool solve(int id)
{
  cin >> R >> C;
  if (!R && !C) {
    return false;
  }

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> bitmap[r][c];
    }
  }

  vector<int> len;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (bitmap[r][c] == '0') continue;
      int size = count_region(r, c);
      if (size >= MIN_REGION) {
	len.push_back(trace(r, c));
      }
      clear_region(r, c);
    }
  }

  sort(len.begin(), len.end());
  cout << "Case " << id << endl;
  for (unsigned int i = 0; i < len.size(); i++) {
    if (i) cout << ' ';
    cout << len[i];
  }
  if (len.size() == 0) {
    cout << "no objects found";
  }
      
  cout << endl;
  return true;
}

int main(void)
{
  int id = 1;
  while (solve(id++))
    ;
  return 0;
}
