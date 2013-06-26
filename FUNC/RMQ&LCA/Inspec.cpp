/*
 * BZOJ 1787: AHOI 2008 Meet
 * Alg: heavy-light decompostion + LCA
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 500010;
const int M = 500010 * 2;

int nxt[M], to[M];
int eb[N], en;

int num[N], f[N], chd[N], dp[N];
bool vis[N], hvy[N];

void DFS (int u, int d, int p) {
	cout << "DFS " << u << " " << d << " " << p << endl;

    vis[u] = true; f[u] = p; num[u] = 1; dp[u] = d;
    for (int e = eb[u]; e != -1; e = nxt[e]) {
        int j = to[e];
        if (!vis[j]) {
            DFS (j, d + 1, u);
            num[u] += num[j];
        }
    }
    for (int e = eb[u]; e != -1; e = nxt[e]) {
        int j = to[e];
        if (f[j] == u && 2 * num[j] >= num[u])
            hvy[j] = true;
    }
}

void getChd (int x) {
    chd[x] = hvy[x] ? chd[f[x]] : x;
    for (int e = eb[x]; e != -1; e = nxt[e]) {
        int j = to[e];
        if (f[j] == x) getChd (j);
    }
}

int lca (int x, int y) {
    while (chd[x] != chd[y]) {
        if (dp[chd[x]] >= dp[chd[y]])
            x = f[chd[x]];
        else y = f[chd[y]];
    }
    return dp[x] < dp[y] ? x : y;
}

inline int dis (int x, int y) {
    return dp[x] + dp[y] - 2 * dp[lca(x,y)];
}

int main () {

	freopen("input.txt", "rt", stdin);
    int i, j, k;
    int n, m;
    memset (eb, -1, sizeof (eb));
    en = 0;
    //scanf ("%d%d", &n, &m);
    scanf("%d", &n);
    cout << n << endl;
    for (int cnt = 1; cnt < n; ++cnt) {
        scanf ("%d%d", &j, &k);
        to[en] = k; nxt[en] = eb[j]; eb[j] = en++;
        cout << en << " " << to[en] << " " << nxt[en] << " " << eb[j] << endl;
        to[en] = j; nxt[en] = eb[k]; eb[k] = en++;
        cout << en << " " << to[en] << " " << nxt[en] << " " << eb[j] << endl;
    }

    DFS (1, 0, 0);
    return 0;
    for (int i = 1; i <= n; ++i){
    	cout << i << " " << hvy[i] << endl;
    }

    hvy[1] = false; getChd (1);



    /*while( m > 0){
    	scanf("%d %d", &i, &j);
    	cout << i << " " << j << " lca = " << lca(i, j) << endl;
    	cout << "\t" << dis(i, j) << endl;
    	--m;
    }
*/
    /*for (; m; --m) {
        scanf ("%d%d%d", &i, &j, &k);

        int rt, rt1, d;

        rt = lca (i, j), d = dp[i] + dp[j] - 2 * dp[rt] + dis (rt, k);
        if (dp[rt1 = lca (j, k)] > dp[rt]) {
            rt = rt1;
            d = dp[j] + dp[k] - 2 * dp[rt] + dis (rt, i);
        }
        if (dp[rt1 = lca (i, k)] > dp[rt]) {
            rt = rt1;
            d = dp[i] + dp[k] - 2 * dp[rt] + dis (rt, j);
        }
        printf ("%d %d\n", rt, d);
    }
*/

}
