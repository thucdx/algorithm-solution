#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAX = (int) 1e6;
int euler[MAX + 5];
ll f[MAX + 5];

void init() {
   // init
   for (int i = 1; i <= MAX; ++i) {
      euler[i] = i;
   }
   fill(f + 1, f + MAX + 1, 1);

   // sieve
   for (int i = 2; i <= MAX; ++i) {
      if (euler[i] == i) {
         for (int j = i << 1; j <= MAX; j += i) {
            euler[j] -= euler[j] / i;
         }
         --euler[i];
      }
   }

   // a(n) = sum(d | n) d.euler(d) => multiplicative
   for (int i = 2; i <= MAX; ++i) {
      ll val = (ll)i * euler[i];
      for (int j = i; j <= MAX; j += i) {
         f[j] += val;
      }
   }
}

int INP,AM;
#define BUFSIZE (1<<10)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        fread(BUF,1,BUFSIZE,stdin); \
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}

int main() {
   /*
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   //*/
   init();

   int ntest, n;
   ll val;
   scanf("%d", &ntest);
   while (ntest--) {
      //scanf("%d", &n);
      GN(n);

      val = (1 + f[n]) * n / 2;
      printf("%lld\n", val);
   }
}

