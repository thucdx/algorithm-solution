#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

#define INF 1000000000

string line;
int n, p, m;
VI c[15];
bool mark[1 << 10][10000 + 10][4];

void getInt(VI& b, int& a) {
    a = 0;
    REP(i, p)
        a = a * n + b[i];
}

void getConf(int a, VI& b) {
    REP(i, p) {
        b.PB(a % n);
        a /= n;
    }
    reverse(ALL(b));
}

struct V {
    int mask, a, k, dist;

    V(int _mask, int _a, int _k, int _dist) {
        mask = _mask;
        a = _a;
        k = _k;
        dist = _dist;
    }

    bool operator<(const V& that) const {
        if (dist != that.dist)
            return dist < that.dist;
        if (mask != that.mask)
            return mask < that.mask;
        if (a != that.a)
            return a < that.a;
        return k < that.k;
    }
};

void solve() {

    REP(i, 15)
        c[i].clear();

    stringstream ss;

    ss << line;

    ss >> n >> p >> m;

    REP(i, m) {
        string t;
        ss >> t;
        int x = (int) (t[0] - 'A');
        int y = (int) (t[1] - 'A');
        c[x].PB(y);
        c[y].PB(x);
    }

    REP(i, n)
        c[i].PB(i);

    int l = 1;
    REP(i, p)
        l *= n;

    queue<V> q;
    REP(i, (1 << n))
        REP(j, l)
            REP(k, p)
                mark[i][j][k] = false;

    V h(1, 0, 0, 0);
    q.push(h);
    mark[h.mask][h.a][h.k] = true;

    while (!q.empty()) {
        int mask = q.front().mask;
        int a = q.front().a;
        int k = q.front().k;
        int dist = q.front().dist;

        q.pop();

        if (mask + 1 == (1 << n)) {
            cout << dist << endl;
            return;
        }

        VI b;

        getConf(a, b);

        REP(l, SIZE(c[b[k]])) {
            int i = c[b[k]][l];

            VI e = b;
            e[k] = i;

            int d;
            getInt(e, d);

            V h(mask | (1 << i), d, (k + 1) % p, dist + (k == 0));

            if (!mark[h.mask][h.a][h.k]) {
                q.push(h);
                mark[h.mask][h.a][h.k] = true;
            }
        }

    }

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (getline(cin, line)) {
        if (line == "0")
            break;
        solve();
    }

    return 0;
}
