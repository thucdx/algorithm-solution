#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = (int) 1e5;
int x[MAX + 5], n;

int main() {
   /*
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   //*/

   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
   sort(x + 1, x + 1 + n);
   for (int i = 1; i <= n; ++i) {
      printf("%d ", x[i]);
   }
}

