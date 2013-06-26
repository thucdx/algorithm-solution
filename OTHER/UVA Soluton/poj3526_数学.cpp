# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

const int MaxN = 25 ;

# define long long double

int a , b , m , n ;
int t ;
long A[MaxN][MaxN] , B[MaxN] ;
int ord[MaxN][MaxN] ;

bool init() {
  return 4==scanf("%d%d%d%d" , &a , &m , &b , &n)&&a+m+b+n>0 ;
}

int Binomial(int n , int m) {
  if (m>n||m<0) return 0 ;

  int ret = 1 ;
  for (int i = n-m+1 ; i<=n ; ++i) ret = ret*i/(i-n+m) ;
  return ret ;
}

int gcd(int a , int b) {
  return (b==0)?a:gcd(b , a%b) ;
}

void print(double x) {
  char s[100] ;
  sprintf(s , "%.0lf" , x) ;
  if (!strcmp(s , "-0")) printf(" %s" , s+1) ;
  else printf(" %s" , s) ;
}

void solve() {
  t = n*m ;
  int k = 0 ;
  for (int i = 0 ; i<m ; ++i)
    for (int j = 0 ; j<n ; ++j) ord[i][j] = k++ ;

  memset(A , 0 , sizeof(A)) ;
  memset(B , 0 , sizeof(B)) ;
  for (int i = 0 ; i<t ; ++i) {
    for (int j = 0 ; j<=i ; ++j) {
      int p = j , q = i-j ;
      long s = Binomial(i , j) ;
      while (p>=m) s*=a , p-=m ;
      while (q>=n) s*=b , q-=n ;
      A[ord[p][q]][i] += s ;
    }
  }

  for (int j = 0 ; j<=t ; ++j) {
    int p = j , q = t-j ;
    long s = Binomial(t , j) ;
    while (p>=m) s*=a , p-=m ;
    while (q>=n) s*=b , q-=n ;
    B[ord[p][q]] -= s ;
  }

  //  printE() ;  
  for (int i = 0 , j , k ; i<t ; ++i) {
    if (A[i][i]==0) {
      for (j = i+1 ; j<t ; ++j) if (A[j][i]!=0) break ;
      if (j==t) { printf("Er!!\n") ; return ; }
      for (k = i ; k<t ; ++k) swap(A[j][k] , A[i][k]) ;
      swap(B[j] , B[i]) ;
    }

    for (j = 0 ; j<t ; ++j) if (j!=i) {
      long p = A[j][i] , q = A[i][i] ;
      for (k = 0 ; k<t ; ++k) A[j][k] = A[j][k]-A[i][k]*p/q ;
      B[j] = B[j]-B[i]*p/q ;
    }
  }

  printf("1") ;
  for (int i = t-1 ; i>=0 ; --i) print(B[i]/A[i][i]) ;
  printf("\n") ;
}

int main() {
  while (init()) 
    solve() ;
}
