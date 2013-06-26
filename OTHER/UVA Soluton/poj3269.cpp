#include <algorithm>
using namespace std;

struct point
{
    int x, y;
}   p[10010];
int     n;

int     x[10010], y[10010];

int calc(int px, int py)
{
    int     t = 0, i;
    for (i = 0; i < n; i++) t += abs(p[i]. x - px);
    for (i = 0; i < n; i++) t += abs(p[i]. y - py);
    return t;
}

int main()
{
    int     i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {    
        scanf("%d %d", &p[i]. x, &p[i]. y);
        x[i] = p[i]. x;
        y[i] = p[i]. y;
    }
    sort(x, x + n);
    sort(y, y + n);
    int     x1, x2, y1, y2;
    if (n % 2 == 1) 
    { 
        x1 = x2 = x[n/2];
        y1 = y2 = y[n/2];
    }
    else 
    {
        x1 = x[n/2-1]; x2 = x[n/2];
        y1 = y[n/2-1]; y2 = y[n/2];
    };
    int     t = calc(x1, y1);       
    int     s = (x2 - x1 + 1) * (y2 - y1 + 1);
    for (i = 0; i < n; i++)
        if (p[i]. x >= x1 && p[i]. x <= x2 && p[i]. y >= y1 && p[i]. y <= y2)
            s--;     
    if (s == 0)
    {
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, -1, 0, 1};
        int costs[4];
        for (int d = 0; d < 4; d++)
            costs[d] = calc(x1 + dx[d], y1 + dy[d]);
        t = *min_element(costs, costs + 4);
        s = count(costs, costs + 4, t);
    }
    printf("%d %d\n", t, s); 
    return 0;
}
