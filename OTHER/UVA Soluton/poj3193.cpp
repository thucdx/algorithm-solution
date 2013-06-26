#include <algorithm>
#include <string>
#include <iostream>
#include <set>
using namespace std;

string  s[1010];
int     n, m;

bool    find(string st)
{
    int     low = -1, high = m - 1;
    int     mid;
    while (low + 1 < high)
    {
        mid = (low + high) >> 1;
        if (s[mid] > st) high = mid; else low = mid;
    }
    if (s[high]. substr(0, st. size()) == st) return true; 
    if (low >= 0 && s[low]. substr(0, st. size()) == st) return true;
    return false;
}

int main()
{
    char    str[60];
    scanf("%d %d", &m, &n);
    getchar();
    for (int i = 0; i < m; i++)
    {
        gets(str);
        s[i] = string(str);
    }
    sort(s, s + m);
    int     ans = 0;
    string  ss;
    while (n--)
    {
        gets(str);
        ss = string(str);        
        if (find(ss)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
