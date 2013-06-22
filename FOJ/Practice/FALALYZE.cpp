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
int n, a[55];

inline void show(int k) {
   for (int i = 1; i <= k; ++i) {
      printf("%d ", a[i]);
   }
   printf("\n");
}

void go(int step, int lastValue, int total) {
   if (total < lastValue) {
     if (total == 0) show(step - 1);
     return;
   }

  int half = total/2;
  for (int i = lastValue; i <= half; ++i) {
     int save = a[step];
     a[step] = i;
     go(step + 1, i, total - i);
   }

   a[step] = total;
   go(step +1, total, 0);
}

int main() {
	/*
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	//*/
   scanf("%d", &n);
//   cout << "N = " << n << endl;
   go(1, 1, n);
}

