//带容量下界的网络流
# include <stdio.h>
# include <string.h>

# define maxr 200
# define maxc 20
# define maxn 300
# define maxm 60000
# define inf  1000000000

class   N_Base_Matrix
{
    public :
    int     n ;
    int     c[maxn][maxn] , f[maxn][maxn] ;
    N_Base_Matrix() { memset(c , 0 , sizeof(c)) ; } 
} ;
       
class   Maxflow_SPA_Matrix : public N_Base_Matrix
{
    public :
    Maxflow_SPA_Matrix() {} ;
    Maxflow_SPA_Matrix(int nn) { n = nn ; } ;
# define Highest n
    int     operator () (int s , int t)
    {
        int     res(0) , cur , tail , u , v ;
        bool    find ;
        memset(d , 0xff , sizeof(d)) ;
        for (p[cur = tail = 0] = t , d[t] = 0 ; cur <= tail ; cur ++)
        {
            u = p[cur] ;
            for (v = 0 ; v < n ; v ++) if (d[v] < 0 && (c[v][u] > 0 || c[u][v] > 0))
            {
                d[v] = d[u] + 1 ; p[++ tail] = v ;
            }
        }
        if (d[s] < 0) d[s] = Highest ;
        for (value[u = s] = inf ; d[s] < Highest ; )
        {
            for (find = false , v = 0 ; v < n && !find; v ++) if (d[u] == d[v] + 1 && f[u][v] < c[u][v])
            {
                find = true ;
                if (c[u][v] - f[u][v] < value[u])
                    value[v] = c[u][v] - f[u][v] ;
                else
                    value[v] = value[u] ;
                p[v] = u ; u = v ;
                if (u == t)
                {
                    res += value[t] ;
                    for ( ; u != s ; )
                    {
                        v = u ; u = p[v] ;
                        f[u][v] += value[t] ; f[v][u] = -f[u][v] ;
                    }
                    u = s ;
                }
            }
            if (!find)
            {
                d[u] = Highest ;
                for (v = 0 ; v < n ; v ++) if (f[u][v] < c[u][v] && d[u] > d[v] + 1)
                    d[u] = d[v] + 1 ;
                if (u != s) u = p[u] ;
            }
        }
        return res ;
    } ;
    private :
    int     d[maxn] , p[maxn] , value[maxn] ;
} ;

int     n , m , no , tot , fail , source , sink ;
int     row[maxr] , col[maxc] , sum ;
int     upper[maxn][maxn] , lower[maxn][maxn] ;
char    s[100] , ch ;

void    command()
{
    int x , y , v , i , j , low , high ;
    sscanf(s , "%d %d %c %d" , &x , &y , &ch , &v) ;
    x -- , y -- ;
    switch (ch)
    {
        case '>' : low = v + 1 ; high = inf ; break ;
        case '<' : low = 0 ; high = v - 1 ; break ;
        case '=' : low = high = v ;
    }
    if (x == -1)
    {
        if (y == -1)
        {
            for (i = 0 ; i < n ; i ++)
                for (j = n ; j < n + m ; j ++)
                {
                    if (lower[i][j] < low) lower[i][j] = low ;
                    if (upper[i][j] > high) upper[i][j] = high ;
                }
        }
        else
        {
            for (i = 0 ; i < n ; i ++)
            {
                if (lower[i][y + n] < low) lower[i][y + n] = low ;
                if (upper[i][y + n] > high) upper[i][y + n] = high ;
            }
        }
    }
    else
        if (y == -1)
        {
            for (j = n ; j < n + m ; j ++)
            {
                if (lower[x][j] < low) lower[x][j] = low ;
                if (upper[x][j] > high) upper[x][j] = high ;
            }
        }
        else
        {
            if (lower[x][y + n] < low) lower[x][y + n] = low ;
            if (upper[x][y + n] > high) upper[x][y + n] = high ;
        }
}

void    init()
{
    int i , j , k ;
    scanf("%d%d" , &n , &m) ;
    memset(lower , 0 , sizeof(lower)) ;
    memset(upper , 0 , sizeof(upper)) ;
    for (i = 0 ; i < n ; i ++)
        for (j = n ; j < n + m ; j ++)
            upper[i][j] = inf ;
    sum = k = 0 ;
    for (i = 0 ; i < n ; i ++)
        scanf("%d" , row + i) , sum += row[i] ;
    for (j = 0 ; j < m ; j ++)
        scanf("%d" , col + j) , k += col[j] ;
    if (sum != k) fail = 1 ; 
    scanf("%d" , &k) ; gets(s) ;
    for ( ; k -- ; )
    {
        gets(s) ;
        if (!fail) command() ;
    }
}

typedef Maxflow_SPA_Matrix Network ;

Network net ;
int     inner[maxn] , outer[maxn] ;

void    build_net()
{
    int i , j , x , y ;
    tot = n + m ;
    for (i = 0 ; i < n ; i ++) upper[tot][i] = lower[tot][i] = row[i] ;
    for (j = n ; j < tot ; j ++) upper[j][tot + 1] = lower[j][tot + 1] = col[j - n] ;
    upper[tot + 1][tot] = inf ;    
    tot += 2 ;
    net = Network(tot + 2) ;
    memset(inner , 0 , sizeof(inner)) ;
    memset(outer , 0 , sizeof(outer)) ;
    for (i = 0 ; i < tot ; i ++)
        for (j = 0 ; j < tot ; j ++)
        {
            inner[j] += lower[i][j] ;
            outer[i] += lower[i][j] ;
            if (lower[i][j] > upper[i][j])
            {
                fail = 1 ;
                return ;
            }
            net.c[i][j] = upper[i][j] - lower[i][j] ;
        }
    source = tot ; sink = tot + 1 ;
    for (i = 0 ; i < tot ; i ++)
        if (inner[i] > outer[i])
            net.c[source][i] = inner[i] - outer[i] ;
        else
            net.c[i][sink] = outer[i] - inner[i] ;
}

void    solve()
{
    build_net() ;
    net(source , sink) ;
    for (int i = 0 ; i < net.n && !fail ; i ++)
        if (net.c[source][i] > net.f[source][i]) fail = 1 ;
}

void    out()
{
    if (fail)
        printf("IMPOSSIBLE\n") ;
    else
    {
        for (int i = 0 ; i < n ; i ++)
        {
            for (int j = 0 ; j < m ; j ++)
            {
                if (j) printf(" ") ;
                printf("%d" , net.f[i][j + n] + lower[i][j + n]) ;
            }
            printf("\n") ;
        }
    }
}

int     main()
{
    for (scanf("%d" , &no) ; no -- ; )
    {
        fail = 0 ;
        init() ;
        if (!fail) solve() ;
        out() ;
        if (no) printf("\n") ;
    }
    return 0 ;
}
