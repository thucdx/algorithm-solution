#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std ;

const int MaxR = 20 ;
const int MaxN = 255 ;
const int MaxQ = 800000;
const int dx[5] = {-1 , 0 , 1 , 0 , 0} ;
const int dy[5] = {0 , 1 , 0 , -1 , 0} ;

int tot , w , h , n ;
char Map[MaxR][MaxR] ;
int ord[MaxR][MaxR] ;
int e[MaxN][6], len[MaxN];
int d1[MaxQ] ,d2[MaxQ], q1[MaxQ], q2[MaxQ], cur1 , tail1, cur2, tail2 ;
int goal, start ;
bool found ;
int sd ;

unsigned char hash[256*256*256+3];
unsigned char hash2[256*256*256+3];

bool init() {
  if (3!=scanf("%d%d%d" , &h , &w , &n) || w+h+n==0) return false ;
  gets(Map[0]) ;
  for (int i = 0 ; i<w ; ++i) gets(Map[i]) ;

  tot = 0 ;
  for (int i = 0 ; i<w ; ++i)
    for (int j = 0 ; j<h ; ++j) if (Map[i][j]!='#') ord[i][j] = tot++ ;

  memset(len , 0 , sizeof(len)) ;
  for (int i = 0 ; i<w ; ++i)
    for (int j = 0 ; j<h ; ++j) if (Map[i][j]!='#') {
      int c = ord[i][j] ;
      for (int k = 0 ; k<5 ; ++k) {
	int tx = i+dx[k] , ty = j+dy[k] ;
	if (Map[tx][ty]!='#') e[c][len[c]++] = ord[tx][ty] ;
      }
    }

  goal = 0 ;  start = 0;
  for (int i = 0 ; i<w ; ++i)
    for (int j = 0 ; j<h ; ++j) {
      if (islower(Map[i][j])) start |= (ord[i][j]<<8*(Map[i][j]-'a')) ;
      if (isupper(Map[i][j])) goal |= (ord[i][j]<<8*(Map[i][j]-'A')) ;
    }
    
  return true ;
}

inline void encode(int&s , int*a) {
  static int i ;
  s = 0 ;
  for (i = n-1 ; i>=0 ; --i) s = (s<<8)+a[i] ;
}

inline void decode(int s , int*a) {
  static int i ;
  for (i = 0 ; i<n ; ++i) a[i] = s&255 , s>>=8 ;
}

void expand(int*a , int*b , int dep) {
    if (found) return;
  if (dep==n) {
    for (int i = 0 ; i<n ; ++i)
      for (int j = i+1 ; j<n ; ++j) {
	if (b[i]==b[j]) return ;
	if (a[i]==b[j]&&a[j]==b[i]) return ;
      }

    int s ;
    encode(s , b);

    if (hash[s] == 0xff) {
      hash[s] = sd + 1 ;  q1[tail1] = s ; d1[tail1++] = sd+1 ;if (tail1 >= MaxQ) tail1 = 0;
      if (s==goal) { found = true ; printf("%d\n" , sd+1) ; return ; }
    }
    if (hash2[s] != 0xff){
        printf("%d\n", hash2[s] + sd + 1); found = true; return;
    }
    return ;
  }

  for (int i = len[a[dep]]-1 ; i>=0 ; --i) {
    b[dep] = e[a[dep]][i] ;
    expand(a , b , dep+1) ;
  }
}


void expand2(int*a , int*b , int dep) {
    if (found) return ;
  if (dep==n) {
    for (int i = 0 ; i<n ; ++i)
      for (int j = i+1 ; j<n ; ++j) {
	if (b[i]==b[j]) return ;
	if (a[i]==b[j]&&a[j]==b[i]) return ;
      }

    int s ;
    encode(s , b) ;

    if (hash2[s] == 0xff) {
      hash2[s] = sd + 1 ; q2[tail2] = s ; d2[tail2++] = sd+1 ;if (tail2 >= MaxQ) tail2 = 0;
      if (s==start) { found = true ; printf("%d\n" , sd+1) ; return ; }
    }
    if (hash[s] != 0xff){
        printf("%d\n", hash[s] + sd + 1); found = true; return;
    }
    return ;
  }

  for (int i = len[a[dep]]-1 ; i>=0 ; --i) {
    b[dep] = e[a[dep]][i] ;
    expand2(a , b , dep+1) ;
  }
}

void solve() {
  int a[3] , b[3] ;
  memset(hash , 0xff , sizeof(hash)) ; 
  q1[0] = start;
  hash[q1[0]] = 0 ; 
  d1[0] = 0 ; found = false ;
  memset(hash2, 0xff, sizeof(hash2));
  d2[0] = 0; q2[0] = goal; hash2[q2[0]] = 1;
  int k = 0;
  cur1 = 0, cur2 = 0;
  tail1 = 1, tail2 = 1; 
  while (1){
    k++;
    for (; cur1<tail1 ; ++cur1) {
        if (cur1 >= MaxQ) tail2 = 0;
        decode(q1[cur1] , a) ; sd = d1[cur1] ;
        if (sd > k) break;
        expand(a , b , 0) ;
        if (found) return ;
    }
    for (; cur2 < tail2; ++cur2){
        if (cur2 >= MaxQ) tail2 = 0;
        decode(q2[cur2], a); sd = d2[cur2];
        if (sd > k) break;
        expand2(a, b, 0);
        if (found) return ;
    }
  }
}

int main() {
    //freopen("G.in", "r", stdin);
  while (init()) 
    solve() ;
    //system("pause");
}

