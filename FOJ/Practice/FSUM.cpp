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
#define Rep(i, a) for (int i = 0, _a = a; i <= _a; ++i)

using namespace std;

int n;
int maxVal = -1, a[15][15], per[15];

inline int getSum() {
   int sum = 0;
   for (int i = 1; i <= n; ++i) sum += a[i][per[i]];
   return sum;
}

int main() {
	/*
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	//*/
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         scanf("%d", &a[i][j]);
      }
   }

   for (int i = 1; i <= n; ++i) per[i] = i;
   maxVal = getSum();
   while (next_permutation(per + 1, per + n + 1)) {
      /*
      // just print
      for (int i = 1; i <= n; ++i) {
         printf("%d ", per[i]);
      }
      printf("\n");
      //*/
      int s = getSum();
      if (maxVal < s) maxVal = s;
   }
   cout << maxVal;
}

