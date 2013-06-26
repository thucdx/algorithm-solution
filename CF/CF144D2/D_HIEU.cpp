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
//typedef double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(int i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(int i = (v).rbegin(); i != (v).rend(); ++i)
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

const double PI = 2 * acos(0.0);
const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dr[] = {0, 0, -1, +1};
const int dc[] = {-1, +1, 0, 0};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ld eps = ld(1e-13);
const ll mod = 1000000007;
typedef pair<int, int> II;

#define maxn 105

ll C[maxn][maxn * maxn], f[maxn][maxn * maxn], mul[maxn][maxn];



ll mu(ll x, ll k){
    if(k == 0) return 1;
    if(k & 1) return x * mu(x, k - 1) % mod;
    ll res = mu(x, k >> 1);
    return res * res % mod;
}

int main(){
	freopen("input.txt" ,  "rt", stdin);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    cout << "x" << endl;

    ms(C, 0);

    ll n, m, k;
    cin >> n >> m >> k;

    Rep(i, maxn * maxn) C[0][i] = 1;
    For(i, 1, 100) For(j, 1, min(i, 100)) C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % mod;


    For(i, 1, n) For(j, 0, n){
        ll num = (m - i) / n + 1;
        mul[i][j] = mu(C[j][n], num);
    }

    ms(f, 0);
    For(i, 0, n) f[1][i] = mul[1][i];
    For(i, 2, n) {
        For(j, 0, k){
            For(t, 0, min((ll)j, n)){
                f[i][j] = (f[i][j] + f[i - 1][j - t] * mul[i][t]) % mod;
            }
        //cout << i << " " << j << " " << f[i][j] << endl;
        }
    }


    cout << f[n][k] << endl;

    return 0;
}
