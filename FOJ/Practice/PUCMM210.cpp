#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = (int) 1e9 + 3;
const int MAX = (int) 1e6;

int f[MAX + 5];

int sqr(long long a) {
   a %= MOD;
   return a * a % MOD;
}

void init() {
   f[1] = 1;
   for (int i = 2; i <= MAX; ++i) {
      long long val = sqr((long long) i * (i + 1)/2);
      f[i] = f[i - 1] + val;
      if (f[i] >= MOD) f[i] -= MOD;
   }
}

int main() {
   /*
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   //*/
   int ntest, n;

   init();
   scanf("%d", &ntest);
   while (ntest--) {
      scanf("%d", &n);
      printf("%d\n", f[n]);
   }
}

