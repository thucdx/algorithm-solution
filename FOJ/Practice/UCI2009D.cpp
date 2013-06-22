#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

#define For(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define Down(i,a,b) for(int i = (a), _b = (b);i >= _b; --i)
#define Rep(i, a) for (int i = 0, _a = a; i < _a; ++i)

using namespace std;
typedef unsigned long long ul;

int n;
char c[10][10];
bool vs[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MAX_STEP = 8;
int trace[15];
ul f[65];
set< ul > octaves;

void init() {
   f[0] = 1;
   For(i, 1, 63) {
      f[i] = f[i-1]<<1;
//      cout << i << " " << f[i] << endl;
   }
}

void go(int step, int x, int y) {
   vs[x][y] = true;
   trace[step] = x*n + y;

   if (step >= MAX_STEP) {
      ul val = 0;
      For(i, 1, step) {
         val |= f[trace[i]];
//         cout << " " << trace[i];
      }
 //     cout << endl;
 //     cout << "Insert " << val << endl;
      octaves.insert(val);
      return;
   }

   Rep(i, 4) {
      int nx = dx[i] + x, ny = dy[i] + y;
      if (0 <= nx && nx < n && 0 <= ny && ny < n && !vs[nx][ny]) {
         go(step + 1, nx, ny);
         vs[nx][ny] = false;
      }
   }
}

inline void solve() {
   octaves.clear();
   memset(vs, false, sizeof(vs));
   For(i, 0, n - 1) For(j, 0, n - 1) {
      if (c[i][j] == '.') vs[i][j] = true;
   }

   For(i, 0, n - 1) For(j, 0, n - 1) {
      if (!vs[i][j]) {
         go(1, i, j);
         vs[i][j] = false;
      }
   }

   printf("%d\n", octaves.size());
}

int main() {
	/*
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	//*/
   init();

   int ntest;
   scanf("%d", &ntest);
   Rep(i, ntest) {
      scanf("%d", &n);
      for (int i = 0; i < n; ++i) {
         scanf("%s", c[i]);
        // cout << c[i] << endl;
      }
      solve();
   }
}

