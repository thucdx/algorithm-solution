#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXL = 100010; 
int f[2][MAXL], p[MAXN];
int n, l, d;

pair<int, int> range(int x)
{
     return make_pair(max(x * d, l - (n-1-x) * (d+1)),
                      min(x * (d+1), l - (n-1-x) * d) );  
}

int main()
{
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }
    d = l / (n - 1); 
    int t = 0;
    memset(f, 0, sizeof(f));
    f[0][0] = p[0];
    for (int i = 1; i < n; i++)
    {
        pair<int, int> pp = range(i - 1);
        pair<int, int> pq = range(i);
        for (int j = pq. first; j <= pq. second; j++)
        {
            f[1-t][j] = INT_MAX;
            if (j - (d + 1) >= pp. first)
                f[1-t][j] <?= f[t][j - d - 1];
            if (j - d <= pp. second) 
                f[1-t][j] <?= f[t][j - d];
            f[1-t][j] += abs(p[i] - j); 
        }
        t = 1 - t;
    }
    printf("%d\n", f[t][l]);
    return 0;
}
