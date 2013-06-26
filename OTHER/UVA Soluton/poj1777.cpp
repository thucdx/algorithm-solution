#include <cstdio> 
#include <cstring> 
#include <algorithm> 

using namespace std ; 

const int p[] = {2, 3, 5, 7, 13, 17, 19, 31}; 
const int v[] = {3, 7, 31, 127, 8191, 131071, 524287, 2147483647}; 
const int MaxN = 110;
const int MaxT = 300;

int n, a[MaxN]; 
int f[MaxT]; 
int TMax; 
int c[MaxT];

void prepare()
{
    for (int i = 0; i < 256; i++)
    {
        c[i] = 0;
        for (int j = 0; j < 8; j++)
            if ( (i & (1<<j)) > 0) c[i] += p[j];
    }
}

bool init() 
{ 
    if (1!=scanf("%d" , &n)) return false ;  
    return true;
} 


void solve() 
{ 
    memset(f, 0, sizeof(f)); 
    f[0] = true; 

    for (int i = 0; i < n; ++i) 
    {
        int p, t = 0;
        scanf("%d", &p);
        for (int j = 0; j < 8; j++)
        {
            int cnt = 0; 
            while (p % v[j] == 0)
            {
                p /= v[j];
                cnt++;
            }
            if (cnt == 1) t |= (1 << j);
            else if (cnt >= 2) { t = -1; break; }
        }
        if (p > 1) t = -1;
        if (t <= 0) continue;
        for (int j = 0; j < 256; j++)
            if ( (j & t) == t && f[j ^ t] == 1) 
                f[j] = true;
    }

    int ans = 0;
    for (int i = 0; i < 256; i++)
        if (f[i] && ans < c[i]) ans = c[i];
    if (ans == 0) printf("NO\n"); else printf("%d\n", ans); 
} 


int main() 
{ 
    prepare();
    while (init()) solve(); 
} 
