#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 410;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = 1e15;

inline int dcmp(const double&x) { return (x<-eps)?-1:(x>eps); }

struct Point 
{
  int x , y ;

  Point(const int&_x=0 , const int&_y=0) : x(_x) , y(_y) {}

  bool operator < (const Point&B) const 
  {
    return x<B.x || x==B.x&&y<B.y ;
  }

  bool operator == (const Point&B) const 
  {
    return x==B.x&&y==B.y ;
  }

  double dist(const Point&B) const 
  {
    return sqrt(1.0*((x-B.x)*(x-B.x)+(y-B.y)*(y-B.y))) ;
  }
} ;

int det(const Point&a , const Point&b , const Point&c)
{
  return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) ;
}

int dot(const Point&a , const Point&b , const Point&c) 
{
  return (b.x-a.x)*(c.x-a.x)+(c.y-a.y)*(b.y-a.y) ;
}

int PtOnLn(const Point&a , const Point&b , const Point&c) 
{
  return det(a , b , c)==0 ;
}

int PtOnSg(const Point&a , const Point&b , const Point&c) 
{
  return det(a , b , c)==0 && dot(a , b , c) <= 0 ;
}

double angle(const Point&a , const Point&b , const Point&c) 
{
  int dt = dot(a , b , c) ;
  return acos(1.0*dt/(b.dist(a)*c.dist(a))) ;
}

struct Segment 
{
  Point a , b ;
} ;

Segment s[maxn] ;
int n , m , S , T ;
Point p[maxn] , ps , pt ;
vector<int> olst[maxn] , e[maxn] ;
bool g[maxn][maxn] ;
double dis[maxn][maxn] ;
int deg[maxn] ;

int sec[maxn] , valid[maxn] ;

double d[maxn] ;
int las[maxn] ;
bool mark[maxn] ;

bool cmp(const int&i , const int&j) 
{
  return p[i] < p[j] ;
}

bool init() 
{
  if (1!=scanf("%d" , &m)||m==0) return false ;
  n = 0 ;
  scanf("%d%d%d%d" , &ps.x , &ps.y , &pt.x , &pt.y) ;
  p[n++] = ps ; p[n++] = pt ;
  for (int i = 0 ; i<m ; ++i) 
  {
    scanf("%d%d%d%d" , &s[i].a.x , &s[i].a.y , &s[i].b.x , &s[i].b.y) ;
    p[n++] = s[i].a ; p[n++] = s[i].b ;
  }
  return true ;
}

void output(int k) 
{
  if (k==-1) return ;
  output(las[k]) ;
  if (sec[k]>=2) printf("%d %d\n" , p[k].x , p[k].y) ;
}

void dijkstra(int s , int t) 
{
  for (int i = 0 ; i<n ; ++i) d[i] = inf , mark[i] = false ;
  d[s] = 0 ; las[s] = -1 ;
  for (int i = 0 ; i<n ; ++i) 
  {
    int k = -1 ;
    for (int j = 0 ; j<n ; ++j) if (!mark[j])
      if (k==-1||d[j]<d[k]) k = j ;
    if (k==-1||k==t) break ;
    mark[k] = true ;
    for (int j = 0 ; j<n ; ++j) if (!mark[j])
      if (d[j] > d[k] + dis[k][j]) 
      {
	     d[j] = d[k] + dis[k][j] ;
	     las[j] = k ;
      }
  }

  if (d[t]>1e10) { puts("-1") ; return ; }
  output(t) ;
  puts("0") ;
}

void solve() 
{
  sort(p , p+n) ;
  n = unique(p , p+n)-p ;

  S = lower_bound(p , p+n , ps)-p ;
  T = lower_bound(p , p+n , pt)-p ;

  for (int i = 0 ; i<m ; ++i) olst[i].clear() ;

  memset(deg , 0 , sizeof(deg)) ;
  for (int i = 0 ; i<n ; ++i) e[i].clear() ;
  memset(g , 0 , sizeof(g)) ;

  for (int i = 0 ; i<m ; ++i) 
  {
    for (int j = 0 ; j<n ; ++j) 
      if (PtOnSg(p[j] , s[i].a , s[i].b)) olst[i].push_back(j) ;

    sort(olst[i].begin() , olst[i].end() , cmp) ;

    int sz = olst[i].size() ;
    for (int j = 1 ; j<sz ; ++j) 
    {
      int u = olst[i][j] , v = olst[i][j-1] ;
      e[u].push_back(v) ;
      e[v].push_back(u) ;
      g[u][v] = g[v][u] = true ;
      ++deg[u] ; ++deg[v] ;
    }
  }

  for (int i = 0 ; i<m ; ++i) 
  {
    int sz = olst[i].size() ;
    for (int j = 1 ; j<sz-1 ; ++j) 
    {
      int u = olst[i][j] ;
      for (vector<int>::iterator I = e[u].begin() ; I!=e[u].end() ; ++I) 
	    if (deg[*I]==1) 
        {
	       double ag = angle(p[olst[i][j]] , p[*I] , p[olst[i][j-1]]) ;
	       int x = olst[i][j-1] , y = olst[i][j] , z = olst[i][j+1] ;

	       int kk = dcmp(ag-pi/2) ;
	       if (kk<0) 
	         g[z][y] = g[y][x] = false ;
	       else if (kk==0) 
           {
	         g[x][y] = g[y][x] = false ;
	         g[x][z] = g[z][x] = false ;
	         g[y][z] = g[z][y] = false ;
	       }
	       else 
	           g[x][y] = g[y][z] = false ;
	    }
    }
  }

  for (int i = 0 ; i<n ; ++i)
    for (int j = 0 ; j<n ; ++j) 
    {
      if (g[i][j]) dis[i][j] = p[i].dist(p[j]) ;
      else dis[i][j] = inf ;
    }

  memset(valid , 0 , sizeof(valid)) ;

  for (int j = 0 ; j<m ; ++j) 
  {
    int u = lower_bound(p , p+n , s[j].a)-p ;
    int v = lower_bound(p , p+n , s[j].b)-p ;

    if (deg[u]==1||deg[v]==1) valid[j] = 0 ;
    else valid[j] = 1 ;
  }

  memset(sec , 0 , sizeof(sec)) ;

  for (int i = 0 ; i<n ; ++i) 
  {
    for (int j = 0 ; j<m ; ++j) 
      if (valid[j]&&PtOnSg(p[i] , s[j].a , s[j].b))
	sec[i]++ ;
  }

  dijkstra(S , T) ;
}

int main() 
{
  while (init()) 
    solve() ;
}

