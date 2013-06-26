#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, npoint, a[105], which[105][105];

int main() {
    freopen("CTRIA.INP", "r", stdin);
    freopen("CTRIA.OUT", "w", stdout);
    
    memset(which, -1, sizeof(which));
    scanf("%d", &n);
    npoint = 0;
    
    for (int i = 0, k = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[j]);
            npoint = max(npoint, a[j]);
        }
        
        for (int x = 0; x < k; ++x)
            for (int y = x + 1; y < k; ++y)
                which[a[x]][a[y]] = which[a[y]][a[x]] = i;
    }
    
    int cnt = 0;
    
    for (int x = 1; x <= npoint; ++x)
        for (int y = x + 1; y <= npoint; ++y)
            for (int z = y + 1; z <= npoint; ++z) {
                int w1 = which[x][y], w2 = which[x][z], w3 = which[y][z];
                if (w1 < 0 || w2 < 0 || w3 < 0) continue;
                if (w1 != w2 && w2 != w3 && w3 != w1) ++cnt;
            }
    
    printf("%d", cnt);
    return 0;
}
