#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 50000

int m;
int pnt[maxn], d[maxn], list[maxn], len;
int a[maxn], b[maxn], v[maxn];

int find ( int x )
{
    int t_pnt;
    if ( pnt[x] != x ) t_pnt = pnt[x], pnt[x] = find ( pnt[x] ), d[x] += d[t_pnt];
    return pnt[x];
}

int main ( )
{
    scanf ( "%d", &m ); len = 0;
    for ( int i = 0; i < m; i ++ ) 
    {
        scanf ( "%d %d %d", a + i, b + i, v + i );
        if ( a[i] > b[i] ) swap ( a[i], b[i] );
        list[len ++] = a[i] - 1; list[len ++] = b[i];
    }
    sort ( list, list + len );
    len = unique ( list, list + len ) - list;
    memset ( d, 0, sizeof ( d ) );
    for ( int i = 0; i < len; i ++ ) pnt[i] = i;
    for ( int i = 0; i < m; i ++ ) 
    {
        int xx = upper_bound ( list, list + len, a[i] - 1 ) - list,
            yy = upper_bound ( list, list + len, b[i] ) - list;
        int x = find ( xx ), y = find ( yy );
        if ( x == y ) 
        {
            if ( v[i] != d[xx] - d[yy] ) printf ( "Bug Detected %d\n", d[xx] - d[yy] );
            else printf ( "Accept\n" );
        } 
        else 
        {
            pnt[y] = x;
            d[y] = d[xx] - d[yy] - v[i];
            printf ( "Accept\n" );
        }
    }
}

