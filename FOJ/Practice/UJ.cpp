#include <cstdio>
typedef unsigned long long ul;
ul r[510], n, c, m = (ul)1e15, t;
int d, k, i, j;

int main() {
   while (scanf("%llu%d", &n, &d) && n) {
      for (i = k = r[0] = 1; i <= d; ++i) {
          for (j = c = 0; j < k; ++j){
               t = r[j]*n + c;
               r[j] = t % m;
               c = t / m;
          }
          if (c > 0) r[k++] = c;
      }
      printf("%llu", r[--k]);
      while(k) printf("%015llu", r[--k]);
      printf("\n");
   }
}
