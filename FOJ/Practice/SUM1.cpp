#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

inline long long calc(int n, int mod) {
   long long hi = n / mod;
   long long sum = hi * (hi + 1) / 2;
   if (n % mod == 0) sum -= hi;
   return sum * mod;
}

int main() {
   /*
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   //*/
   int ntest, n;
   long long sum = 0;
   scanf("%d", &ntest);
   while (ntest--) {
      scanf("%d", &n);
      sum = calc(n, 3) + calc(n, 5) - calc(n, 15);
      printf("%lld\n", sum);
   }
}

