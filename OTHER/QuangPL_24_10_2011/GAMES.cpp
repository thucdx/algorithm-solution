#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 1000
#define oo 1000000000000000LL

int n, a[maxn + 5], mi[maxn + 5], mj[maxn + 5];
long long sum[maxn + 5], dp[maxn + 5][maxn + 5];

int main() {
    freopen("GAMES.INP", "r", stdin);
    freopen("GAMES.OUT", "w", stdout);
    
    for (int test = 0; test < 3; ++test) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
        
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j) dp[i][j] = -oo;
        
        for (int i = n; i >= 1; --i) {
            dp[i][i] = a[i];
            mi[i] = mj[i] = i;
            
            for (int j = i + 1; j <= n; ++j) {
                long long total = sum[j] - sum[i - 1];
                dp[i][j] = max(dp[i][j], total);
                dp[i][j] = max(dp[i][j], total - dp[i][mj[i]]);
                dp[i][j] = max(dp[i][j], total - dp[mi[j]][j]);
                if (dp[i][mj[i]] > dp[i][j]) mj[i] = j;
                if (dp[mi[j]][j] > dp[i][j]) mi[j] = i;
            }
        }
        
        cout << dp[1][n] << endl;
    }
    
    return 0;
}
