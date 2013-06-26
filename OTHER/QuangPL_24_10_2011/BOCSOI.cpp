#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define mod 111539786
#define maxv 30000

int n, a[5], id[5][maxv + 1], dp[28][28][28][28][28];

int go() {
    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0) return 1;
    int &ret = dp[id[0][a[0]]][id[1][a[1]]][id[2][a[2]]][id[3][a[3]]][id[4][a[4]]];
    
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = 0; i < n; ++i) { 
        int &x = a[i], &y = a[(i + 1) % n];
        if ((x & 1) && (y & 1)) {
           --x; --y;
           ret += go();
           if (ret >= mod) ret -= mod;
           ++x; ++y;
        }
        if (x > 0 && y > 0) {
           int u = x, v = y;
           x /= 2; y /= 2;
           ret += go();
           if (ret >= mod) ret -= mod;
           x = u; y = v;
        }
    }
    
    return ret;
}

int main() {
    freopen("BOCSOI.INP", "r", stdin);
    freopen("BOCSOI.OUT", "w", stdout);
    
    memset(a, 0, sizeof(a));
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    
    for (int i = 0; i < 5; ++i) {
        id[i][a[i]] = 0;
        for (int val = a[i], cnt = 1; val > 0; ++cnt) {
            val = (val & 1) ? val - 1 : val >> 1;
            id[i][val] = cnt;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    printf("%d\n", go());
}
