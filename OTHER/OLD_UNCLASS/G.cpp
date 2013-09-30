#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(typeof(n) i = 0; i < (n); ++i)
#define Repd(i,n) for(typeof(n) i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(typeof(b) i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(typeof(a) i = (a); i >= (b); --i)
#define Fit(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define nl puts("")
#define sp printf(" ")
#define ok puts("ok")
//#include <conio.h>

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> void db(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a << " "; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> struct Triple { T x, y, z; Triple() {} Triple(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {} };
template<class T> Triple<T> euclid(T a, T b) { if (b == 0) return Triple<T>(1, 0, a); Triple<T> r = euclid(b, a % b); return Triple<T>(r.y, r.x - a / b * r.y, r.z); }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
	v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

const double PI = 2 * acos(0);
const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const double eps = 1e-9;


#define MAX 111

struct Match2{

    int n,cuoi;
    ll c[MAX][MAX];
    ll fx[MAX],fy[MAX],mx[MAX],my[MAX],q[MAX],x[MAX],y[MAX],tr[MAX];
    
    void init(int _n){
        n = _n;
        memset(mx, 0, sizeof(mx));
        memset(my, 0, sizeof(my));
        memset(fx, 0, sizeof(fx));
        memset(fy, 0, sizeof(fy));
    }
    
    void add(int i, int j, long long cost){
        c[i][j] = cost;
    }
    
    int cothe(int s){
         int dau = 0,cuo = 0,u,v;
         memset(x,0,sizeof(x));
         memset(y,0,sizeof(y));
         memset(tr,0,sizeof(tr));
         
         q[cuo++] = s;
         while(dau!=cuo){
               u = q[dau++]; x[u] = 1;
               for(v = 1;v<=n;v++)
                    if(!y[v]&& c[u][v]==fx[u]+fy[v]){
                          y[v] = 1; tr[v] = u;
                          if(!my[v]) {cuoi = v; return true;}
                          q[cuo++] = my[v];
                    }
         }
         return false;
    }
    
    void dao(){
          ll delta = 1ll << 50;
          for(int u = 1;u<=n;u++) if(x[u])
               for(int v = 1;v<=n;v++) if(!y[v]) delta = min(delta,c[u][v]-fx[u]-fy[v]);
          for(int i = 1;i<=n;i++) if(x[i]) fx[i]+=delta;
          for(int i = 1;i<=n;i++) if(y[i]) fy[i]-=delta;
    }
    
    void rong(int s){
          int u,v = cuoi,t;
          while(!mx[s]){
                u = tr[v];
                t = mx[u];
                my[v] = u; mx[u] = v;
                v = t;
              //  printf("?");
          }
    }
    
    ll minimumCost(){
        for(int i = 1;i<=n;i++){
              // printf("%d\n",i);
            while(!cothe(i)) dao();
              // printf("%d\n",i);
            rong(i);
        }
        ll res = 0;
        for(int i = 1;i<=n;i++) res += fx[i]+fy[i];
        return res;
    }

} match;

struct Point{
    ll x, y;
    Point(){};
    Point(ll _x,ll _y){
        x = _x; y = _y;
    }
};

long long f[201][201];

Point q[201 * 201];

int r[] = {+2, +2, +1, -1, -2, -2, -1, +1};
int c[] = {-1, +1, +2, +2, +1, -1, -2, -2};

bool thoaman(ll x, ll y){
    return (x >= 0 && x <= 200 && y >= 0 && y <= 200);
}

void init(){
    memset(f, -1, sizeof(f));
    f[20][20] = 0;
    int size = 0;
    q[size++] = Point(20, 20);
    Rep(i, size){
        Rep(j, 8) if(thoaman(q[i].x + r[j], q[i].y + c[j]) && f[q[i].x + r[j]][q[i].y + c[j]] == -1){
            f[q[i].x + r[j]][q[i].y + c[j]] = f[q[i].x][q[i].y] + 1;
            q[size++] = Point(q[i].x + r[j], q[i].y + c[j]);
        }
    }
}

int test = 0;

long long khoang_cach(long long x, long long y){
    ll res = 0, ret, t;
    if(x <= 140 && y <= 140) return f[x + 20][y + 20];
    if(x > y) swap(x, y);
    
    if(y > 2 * x){
        if(x > 30) t = (x - 30);
        else t = 0;
        x -= t; y -= t * 2; res += t;
        if(y <= 100) return res + f[x + 20][y + 20];
        else{
            t = (y - 100) / 4;
            y -= t * 4;
            res += t * 2;
            return res + f[x + 20][y + 20];
        }
    }
    
    else{
        if(x > 30) t = min(x - 30, y - x);
        else t = 0;
        x -= t; y -= t * 2; res += t;
        if(x <= 40) return res + f[x + 20][y + 20];
        t = (x - 40) / 3;
        x -= t * 3; y -= t * 3; res += t * 2;
        if( y <= 120) return res + f[x + 20][y + 20];
        else{
            t = (y - 120) / 3;
            y -= t * 4;
            res += t * 2;
            return res + f[x + 20][y + 20];
        }
    }
}

long long d[20][20];
Point A[20], B[20];
int n;

int main(){
    
   freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    init();

    while(scanf("%d",&n) > 0 && n > 0){
    match.init(n);
    For(i, 1, n) scanf("%I64d %I64d", &A[i].x, &A[i].y); 
    For(i, 1, n) scanf("%I64d %I64d", &B[i].x, &B[i].y);
    For(i, 1, n) For(j, 1, n){
        match.add(i, j, khoang_cach(abs(A[i].x - B[j].x), abs(A[i].y - B[j].y)));
    }
    printf("%d. %I64d\n",++test, match.minimumCost()); 
    
    }
}

