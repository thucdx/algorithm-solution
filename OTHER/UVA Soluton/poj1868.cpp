#include <stdio.h>

int x[10000], y[10000];
int n;

void solve(){
    for (int i = 0; i < n;i++) {
        scanf("%d", &x[i]);
        y[x[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = x[j]+x[j]-x[i];
            if (k < 0 || k >= n) continue;
            if (y[k] > j) {
                printf("no\n");
                return;
            }
        }
    }
    printf("yes\n");
}


int main(){
    while (EOF != scanf("%d: ",&n) && n) 
        solve();
    return 0;        
}
