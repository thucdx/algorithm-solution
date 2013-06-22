#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
int dx[][2] = { {0, 1}, {0, 0}};
int dy[][2] = { {0, 0}, {0, 1}};

const int MAX_STEP = 28;
const int MAX_ROW = 7;
const int MAX_COL = 8;

int total, b[10][10];
bool vs[10][10], used[10][10];

inline void mark(int i, int j, bool value) {
   used[i][j] = used[j][i] = value;
}

inline void go(int row, int col) {
//   cout << "go  " << row << " " << col << endl;
   if (col == 8) {
      row++;
      col = 0;
   }

   if (row == 8) {
      ++total;
      return;
   }

   if (vs[row][col]) {
      go(row, col + 1);
      return;
   }

   if (!vs[row][col + 1] && !used[b[row][col]][b[row][col + 1]]) {
      vs[row][col + 1] = vs[row][col] = true;
      mark(b[row][col], b[row][col + 1], true);

      go(row, col + 2);

      mark(b[row][col], b[row][col + 1], false);
      vs[row][col + 1] = vs[row][col] = false;
   }

   if (!vs[row + 1][col] && !used[b[row + 1][col]][b[row][col]]) {
      vs[row + 1][col] = vs[row][col] = true;
      mark(b[row + 1][col], b[row][col], true);

      go(row, col + 1);

      mark(b[row + 1][col], b[row][col], false);
      vs[row][col] = vs[row + 1][col] = false;
   }

}

int main() {
   /*
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   //*/
   int ntest;
   scanf("%d", &ntest);

   while (ntest--) {
      for (int i = 0; i < MAX_ROW; ++i) {
         for (int j = 0; j < MAX_COL; ++j) {
            scanf("%d", &b[i][j]);
         }
      }

      // solve
      total = 0;
      memset(vs, false, sizeof(vs));
      memset(used, false, sizeof(used));
       for (int i = 0; i < 10; ++i) {
          for (int j = 0; j < 10; ++j) {
             if (i >= 7 || j >= 8) {
                vs[i][j] = true;
             } else vs[i][j] = false;
          }
       }


      go(0, 0);
      printf("%d\n", total);
   }
}



